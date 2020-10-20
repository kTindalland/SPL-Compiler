%{

/* Import c standard libs */
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1

void yyerror(char *s);
int yylex(void);

%}
%token COLON SEMICOLON DOT COMMA APOST ASSIGN BRA KET PLUS MINUS TIMES DIV EQUAL NOTEQ LESSTHAN MORETHAN LESSEQUAL MOREEQUAL ENDP CODE OF TYPE DECL IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE NEWL READ CHAR INT REAL NUMBER REALNUM CHARCONST IDEN
%left AND OR NOT
%type block identifiers_list declaration declaration_block type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparator expression term value constant number_constant
%%

program		: IDEN COLON block ENDP IDEN DOT
		;

block		: CODE statement_list
		| DECL declaration_block CODE statement_list
		;

identifiers_list: IDEN
		| identifiers_list COMMA IDEN
		;

declaration	: identifiers_list OF TYPE type SEMICOLON
		;

declaration_block: declaration
		| declaration_block declaration
		;

type		: CHAR
		| INT
		| REAL
		;

statement_list	: statement
		| statement_list SEMICOLON statement
		;

statement	: assignment_statement
		| if_statement
		| do_statement
		| while_statement
		| for_statement
		| write_statement
		| read_statement
		;

assignment_statement: expression ASSIGN IDEN
		;

if_statement	: IF conditional THEN statement_list ENDIF
		| IF conditional THEN statement_list ELSE statement_list ENDIF
		;

do_statement	: DO statement_list WHILE conditional ENDDO
		;
		
while_statement	: WHILE conditional DO statement_list ENDWHILE
		;

for_statement	: FOR IDEN IS expression BY expression TO expression DO statement_list ENDFOR
		;

write_statement	: WRITE BRA output_list KET
		| NEWL
		;

read_statement	: READ BRA IDEN KET
		;

output_list	: value
		| output_list COMMA value

conditional	: expression comparator expression
		| NOT conditional
		| conditional AND conditional
		| conditional OR conditional
		;

comparator	: EQUAL
		| NOTEQ
		| LESSTHAN
		| MORETHAN
		| LESSEQUAL
		| MOREEQUAL
		;

expression	: term
		| expression PLUS term
		| expression MINUS term
		;

term		: value
		| term TIMES value
		| term DIV value
		;

value		: IDEN
		| constant
		| BRA expression KET
		;

constant	: number_constant
		| CHARCONST
		;

number_constant : NUMBER
		| REALNUM
		| MINUS NUMBER
		| MINUS REALNUM
		;

%%
#include "lex.yy.c"
