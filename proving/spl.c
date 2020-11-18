#include <stdio.h>
int yyparse(void);

#ifdef YYDEBUG
extern int yydebug;
#endif

int main(void) {
	#ifdef YYDEBUG
	yydebug = 1;
	#endif
	return(yyparse());
}

void yyerror(char *s) {

	fprintf(stderr, "Error: %s\n", s);

}
