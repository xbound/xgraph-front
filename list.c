#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xgraph/header/expr.h"
#include <time.h>
const char *t2s[]={
	[EXPR_CONSTANT]="Constant",
	[EXPR_VARIABLE]="Variable",
	[EXPR_FUNCTION]="Function",
	[EXPR_MDFUNCTION]="Multi-dimension function",
	[EXPR_MDEPFUNCTION]="Multi-dimension function*"
};
int main(int c,char **argv){
	for(const struct expr_builtin_symbol *p=expr_bsyms;p->str;++p){
		printf("%-12s\t%s",p->str,t2s[p->type]);
		switch(p->type){
			case EXPR_CONSTANT:
				printf("\tvalue: %e",p->un.value);
				break;
			case EXPR_VARIABLE:
				printf("\tvalue: %e",*(double *)p->un.addr);
				break;
			case EXPR_MDFUNCTION:
			case EXPR_MDEPFUNCTION:
				if(p->dim)
				printf("\tdimension: %u",p->dim);
				else
				printf("\tdimension: no limit");

		}
		printf("\n");
	}
	return 0;
}