#include <stdio.h>
int yyparse(void);
extern int yydebug;

int main(void) {
	yydebug = 1;
	return(yyparse());
}

void yyerror(char *s) {

	fprintf(stderr, "Error: %s\n", s);

}
