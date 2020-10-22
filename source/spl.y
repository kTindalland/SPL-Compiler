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

enum ParseTreeNodeType { PROGRAM, BLOCK, NUMBER_CONSTANT, CONSTANT, VALUE, EXPRESSION, TERM, COMPARATOR, CONDITIONAL, OUTPUT_LIST, FOR_STATEMENT, WHILE_STATEMENT, FOR_EXPRESSIONS, DO_STATEMENT, IF_STATEMENT, ASSIGNMENT_STATEMENT, STATEMENT_LIST, TYPENODE, DECLARATION_BLOCK, WRITE_STATEMENT, READ_STATEMENT, STATEMENT, DECLARATION, IDENTIFIERS_LIST, INTEGER_NODE, REAL_NODE } ;  
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
void PrintTree(TERNARY_TREE);

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

%token<iVal> COLON SEMICOLON DOT COMMA APOST ASSIGN BRA KET PLUS MINUS TIMES DIV EQUAL NOTEQ LESSTHAN MORETHAN LESSEQUAL MOREEQUAL ENDP CODE OF TYPE DECL IF THEN ELSE ENDIF DO WHILE ENDDO ENDWHILE FOR IS BY TO ENDFOR WRITE NEWL READ CHAR REAL INT NUMBER CHARCONST 
%left AND OR NOT
%type<tVal> block identifiers_list declaration declaration_block type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparator expression term value constant number_constant program integer real_number
%%

program		: IDEN COLON block ENDP IDEN DOT { TERNARY_TREE ParseTree;
						ParseTree = create_node(NOTHING, PROGRAM, $3, NULL, NULL);
						PrintTree(ParseTree);
						}
		;

block		: CODE statement_list { $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL); }
		| DECL declaration_block CODE statement_list { $$ = create_node(DECL, BLOCK, $2, $4, NULL); }
		;

identifiers_list: IDEN { $$ = create_node($1, IDENTIFIERS_LIST, NULL, NULL, NULL); }
		| identifiers_list COMMA IDEN { $$ = create_node($3, IDENTIFIERS_LIST, $1, NULL, NULL); }
		;

declaration	: identifiers_list OF TYPE type SEMICOLON { $$ = create_node(NOTHING, DECLARATION, $1, $4, NULL); }
		;

declaration_block: declaration { $$ = create_node(NOTHING, DECLARATION_BLOCK, $1, NULL, NULL); }
		| declaration_block declaration { $$ = create_node(BLOCK, DECLARATION_BLOCK, $1, $2, NULL); }
		;

type		: CHAR { $$ = create_node(NOTHING, TYPENODE, NULL, NULL, NULL); }
		| INT { $$ = create_node(INT, TYPENODE, NULL, NULL, NULL); }
		| REAL { $$ = create_node(REAL, TYPENODE, NULL, NULL, NULL); }
		;

statement_list	: statement { $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL, NULL); }
		| statement_list SEMICOLON statement { $$ = create_node(SEMICOLON, STATEMENT_LIST, $1, $3, NULL); }
		;

statement	: assignment_statement { $$ = create_node(ASSIGNMENT_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| if_statement { $$ = create_node(IF_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| do_statement { $$ = create_node(DO_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| while_statement { $$ = create_node(WHILE_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| for_statement { $$ = create_node(FOR_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| write_statement { $$ = create_node(WRITE_STATEMENT, STATEMENT, $1, NULL, NULL); }
		| read_statement { $$ = create_node(READ_STATEMENT, STATEMENT, $1, NULL, NULL); }
		;

assignment_statement: expression ASSIGN IDEN { $$ = create_node(NOTHING, ASSIGNMENT_STATEMENT, $1, NULL, NULL); }
		;

if_statement	: IF conditional THEN statement_list ENDIF { $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL); }
		| IF conditional THEN statement_list ELSE statement_list ENDIF { $$ = create_node(ELSE, IF_STATEMENT, $2, $4, $6); }
		;

do_statement	: DO statement_list WHILE conditional ENDDO { $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL); }
		;
		
while_statement	: WHILE conditional DO statement_list ENDWHILE { $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL); }
		;

for_statement	: FOR IDEN IS expression BY expression TO expression DO statement_list ENDFOR { $$ = create_node(NOTHING, FOR_STATEMENT, create_node(NOTHING, FOR_EXPRESSIONS, $4, $6, $8 ),$10 , NULL); }
		;

write_statement	: WRITE BRA output_list KET { $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL); }
		| NEWL { $$ = create_node(NEWL, WRITE_STATEMENT, NULL, NULL, NULL); }
		;

read_statement	: READ BRA IDEN KET { $$ = create_node(NOTHING, READ_STATEMENT, NULL, NULL, NULL); }
		;

output_list	: value { $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL); }
		| output_list COMMA value { $$ = create_node(COMMA, OUTPUT_LIST, $1, $3, NULL); }

conditional	: expression comparator expression { $$ = create_node(NOTHING, CONDITIONAL, $1, $2, $3); }
		| NOT conditional { $$ = create_node(NOT, CONDITIONAL, $2, NULL, NULL); }
		| conditional AND conditional { $$ = create_node(AND, CONDITIONAL, $1, $3, NULL); }
		| conditional OR conditional { $$ = create_node(OR, CONDITIONAL, $1, $3, NULL); }	
		;

comparator	: EQUAL { $$ = create_node(EQUAL, COMPARATOR, NULL, NULL, NULL); }
		| NOTEQ { $$ = create_node(NOTEQ, COMPARATOR, NULL, NULL, NULL); }
		| LESSTHAN { $$ = create_node(LESSTHAN, COMPARATOR, NULL, NULL, NULL); }
		| MORETHAN { $$ = create_node(MORETHAN, COMPARATOR, NULL, NULL, NULL); }
		| LESSEQUAL { $$ = create_node(LESSEQUAL, COMPARATOR, NULL, NULL, NULL); }
		| MOREEQUAL { $$ = create_node(MOREEQUAL, COMPARATOR, NULL, NULL, NULL); }
		;

expression	: term { $$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL); }
		| expression PLUS term { $$ = create_node(PLUS, EXPRESSION, $1, $3, NULL); }
		| expression MINUS term { $$ = create_node(MINUS, EXPRESSION, $1, $3, NULL); }
		;

term		: value { $$ = create_node(NOTHING, TERM, $1, NULL, NULL); }
		| term TIMES value { $$ = create_node(NOTHING, TERM, $1, $3, NULL); }
		| term DIV value { $$ = create_node(NOTHING, TERM, $1, $3, NULL); }
		;

value		: IDEN { $$ = create_node($1, VALUE, NULL, NULL, NULL); }
		| constant { $$ = create_node(NOTHING, VALUE, $1, NULL, NULL); }
		| BRA expression KET { $$ = create_node(NOTHING, VALUE, $2, NULL, NULL); }
		;

constant	: number_constant { $$ = create_node(NUMBER, CONSTANT, $1, NULL, NULL); }
		| CHARCONST { $$ = create_node($1, CONSTANT, NULL, NULL, NULL); }
		;

number_constant : integer { $$ = create_node(NOTHING, NUMBER_CONSTANT, $1, NULL, NULL); }
		| real_number { $$ = create_node(NOTHING, NUMBER_CONSTANT, $1, NULL, NULL); }
		| MINUS integer { $$ = create_node(MINUS, NUMBER_CONSTANT, $2, NULL, NULL); }
		| MINUS real_number { $$ = create_node(MINUS, NUMBER_CONSTANT, $2, NULL, NULL); }
		;

integer		: NUMBER { $$ = create_node($1, INTEGER_NODE, NULL, NULL, NULL); }
		;

real_number	: integer DOT integer { $$ = create_node(NOTHING, REAL_NODE, $1, $3, NULL); }
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

void PrintTree(TERNARY_TREE t)
{
	if (t == NULL) return;
	printf("Item: %d", t->item);
	printf(" nodeIdentifier: %d\n", t->nodeIdentifier);
	PrintTree(t->first);
	PrintTree(t->second);
	PrintTree(t->third);
}

#include "lex.yy.c"
