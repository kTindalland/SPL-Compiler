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

enum ParseTreeNodeType { PROGRAM, BLOCK, NUMBER_CONSTANT, CONSTANT, VALUE, EXPRESSION, TERM, COMPARATOR, CONDITIONAL, OUTPUT_LIST, FOR_STATEMENT, WHILE_STATEMENT, FOR_EXPRESSIONS, DO_STATEMENT, IF_STATEMENT, ASSIGNMENT_STATEMENT, STATEMENT_LIST, TYPENODE, DECLARATION_BLOCK, WRITE_STATEMENT, READ_STATEMENT, STATEMENT, DECLARATION, IDENTIFIERS_LIST, INTEGER_NODE, REAL_NODE, IDENNODE } ;  


char *NodeNames[] = { "PROGRAM", "BLOCK", "NUMBER_CONSTANT", "CONSTANT", "VALUE", "EXPRESSION", "TERM", "COMPARATOR", "CONDITIONAL", "OUTPUT_LIST", "FOR_STATEMENT", "WHILE_STATEMENT", "FOR_EXPRESSIONS", "DO_STATEMENT", "IF_STATEMENT", "ASSIGNMENT_STATEMENT", "STATEMENT_LIST", "TYPENODE", "DECLARATION_BLOCK", "WRITE_STATEMENT", "READ_STATEMENT", "STATEMENT", "DECLARATION", "IDENTIFIERS_LIST", "INTEGER_NODE", "REAL_NODE", "IDENNODE" };
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
void PrintTree(TERNARY_TREE, int);

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
%type<tVal> block identifiers_list declaration declaration_block type statement_list statement assignment_statement if_statement do_statement while_statement for_statement write_statement read_statement output_list conditional comparator expression term value constant number_constant program integer real_number identifier
%%

program		: identifier COLON block ENDP identifier DOT { TERNARY_TREE ParseTree;
						ParseTree = create_node(NOTHING, PROGRAM, $1, $3, $5);
						PrintTree(ParseTree, 0);
						}
		;

block		: CODE statement_list { $$ = create_node(NOTHING, BLOCK, $2, NULL, NULL); }
		| DECL declaration_block CODE statement_list { $$ = create_node(NOTHING, BLOCK, $2, $4, NULL); }
		;

identifiers_list: identifier { $$ = create_node(NOTHING, IDENTIFIERS_LIST, $1, NULL, NULL); }
		| identifiers_list COMMA identifier { $$ = create_node(NOTHING, IDENTIFIERS_LIST, $1, $3, NULL); }
		;

declaration	: identifiers_list OF TYPE type SEMICOLON { $$ = create_node(NOTHING, DECLARATION, $1, $4, NULL); }
		;

declaration_block: declaration { $$ = create_node(NOTHING, DECLARATION_BLOCK, $1, NULL, NULL); }
		| declaration_block declaration { $$ = create_node(NOTHING, DECLARATION_BLOCK, $1, $2, NULL); }
		;

type		: CHAR { $$ = create_node(CHAR, TYPENODE, NULL, NULL, NULL); }
		| INT { $$ = create_node(INT, TYPENODE, NULL, NULL, NULL); }
		| REAL { $$ = create_node(REAL, TYPENODE, NULL, NULL, NULL); }
		;

statement_list	: statement { $$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL, NULL); }
		| statement_list SEMICOLON statement { $$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL); }
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
		| IF conditional THEN statement_list ELSE statement_list ENDIF { $$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6); }
		;

do_statement	: DO statement_list WHILE conditional ENDDO { $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL); }
		;
		
while_statement	: WHILE conditional DO statement_list ENDWHILE { $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL); }
		;

for_statement	: FOR identifier IS expression BY expression TO expression DO statement_list ENDFOR { $$ = create_node(NOTHING, FOR_STATEMENT,$2, create_node(NOTHING, FOR_EXPRESSIONS, $4, $6, $8 ),$10 ); }
		;

write_statement	: WRITE BRA output_list KET { $$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL); }
		| NEWL { $$ = create_node(NOTHING, WRITE_STATEMENT, NULL, NULL, NULL); }
		;

read_statement	: READ BRA identifier KET { $$ = create_node(NOTHING, READ_STATEMENT, $3, NULL, NULL); }
		;

output_list	: value { $$ = create_node(NOTHING, OUTPUT_LIST, $1, NULL, NULL); }
		| output_list COMMA value { $$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL); }

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

value		: identifier { $$ = create_node(NOTHING, VALUE, $1, NULL, NULL); }
		| constant { $$ = create_node(NOTHING, VALUE, $1, NULL, NULL); }
		| BRA expression KET { $$ = create_node(NOTHING, VALUE, $2, NULL, NULL); }
		;

constant	: number_constant { $$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL); }
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

identifier	: IDEN { $$ = create_node($1, IDENNODE, NULL, NULL, NULL); }
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

void PrintTree(TERNARY_TREE t, int tabbingAmount)
{
	if (t == NULL) return;

	/* Do tabbing */
	for (int i = 0; i < tabbingAmount; i++) {
		printf("    ");
	}

	if (t->item != NOTHING || t->nodeIdentifier == REAL_NODE) {
		
		if (t->nodeIdentifier == INTEGER_NODE) { /* Integer Number */
			printf("Integer Item: %d", t->item);
		}
		else if (t->nodeIdentifier == REAL_NODE) { /* Real Number */
			printf("Real Number Item: %d.%d", t->first->item, t->second->item);
		}
		else if (t->nodeIdentifier == CONSTANT && t->first == NULL) { /* Character Constant */
			printf("Character Constant: %c", t->item);
		}
		else if (t->nodeIdentifier == NUMBER_CONSTANT && t->item == MINUS) {
			printf("Number Constant Item: Minus");
		}
		else if (t->nodeIdentifier == IDENNODE) { /* Identifier */
			if (t->item < 0 || t->item >= SYMTABSIZE) {
				printf("Unknown identifier item: %d", t->item);
			}
			else {
				printf("Identifier Item: %s", symTab[t->item]->identifier);
			}
			
		}
		else if (t->nodeIdentifier == STATEMENT) {
			switch (t->item) {
				case ASSIGNMENT_STATEMENT:
					printf("Statement Item: assignment_statement");
				break;
				
				case IF_STATEMENT:
					printf("Statement Item: if_statement");
				break;

				case DO_STATEMENT:
					printf("Statement Item: do_statement");
				break;

				case WHILE_STATEMENT:
					printf("Statement Item: while_statement");
				break;

				case FOR_STATEMENT:
					printf("Statement Item: for_statement");
				break;

				case WRITE_STATEMENT:
					printf("Statement Item: write_statement");
				break;

				case READ_STATEMENT:
					printf("Statement Item: read_statement");
				break;

				default:
					printf("Statement Item: default");
				break;
			}

		}
		else if (t->nodeIdentifier == TYPENODE) {
			switch (t->item) {
				case CHAR:
					printf("TypeNode Item: char");
				break;

				case INT:
					printf("TypeNode Item: int");
				break;

				case REAL:
					printf("TypeNode Item: real");
				break;
			}
		}
		else if (t->nodeIdentifier == COMPARATOR) {
			switch (t->item) {
				case EQUAL:
					printf("Comparator Item: equal");
				break;
				case NOTEQ:
					printf("Comparator Item: noteq");
				break;
				case LESSTHAN:
					printf("Comparator Item: lessthan");
				break;
				case MORETHAN:
					printf("Comparator Item: morethan");
				break;
				case LESSEQUAL:
					printf("Comparator Item: lessequal");
				break;
				case MOREEQUAL:
					printf("Comparator Item: moreequal");
				break;

			}
		}
		else {
			printf("Unknown Item: %d", t->item);
		}


	}


	int namesLength = sizeof(NodeNames) / sizeof(NodeNames[0]);
	if (t->nodeIdentifier < 0 || t->nodeIdentifier >= namesLength) {
		printf(" unknown nodeIdentifier: %d\n", t->nodeIdentifier);
	}
	else {
		printf(" nodeIdentifier: %s\n", NodeNames[t->nodeIdentifier]);
	}


	PrintTree(t->first, tabbingAmount + 1);
	PrintTree(t->second, tabbingAmount + 1);
	PrintTree(t->third, tabbingAmount + 1);
}

#include "lex.yy.c"
