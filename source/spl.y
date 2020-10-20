%{

/* Import c standard libs */
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1

void yyerror(char *s);
int yylex(void);

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { PROGRAM, BLOCK } ;  
                          /* Add more types here, as more nodes
                                           added to tree */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;

%}

%start program

%union {
	int iVal;
	TERNARY_TREE tVal;
}

%token<iVal> IDEN

%token COLON SEMICOLON DOT COMMA APOST ASSIGN BRA KET PLUS MINUS TIMES DIV EQUAL NOTEQ LESSTHAN MORETHAN LESSEQUAL MOREEQUAL ENDP CODE OF TYPE DECL IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE NEWL READ CHAR INT REAL NUMBER REALNUM CHARCONST 
%left AND OR NOT
%type<tVal> block identifiers_list declaration declaration_block type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparator expression term value constant number_constant
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


TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}


#include "lex.yy.c"
