%{
/* Macro functions copied from Brian Tompsett's Lecture  */
#ifdef PRINT
#define RETURN(typearg, token) printf( #typearg " " #token "\n")
#else
#define RETURN(typearg, token) return(token)
#endif

#ifndef PRINT
/* Declare Symbol Table Type and Array as imported types */

#include <string.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char *);
#endif
%}
delim [ \t\r\n]
ws {delim}+
digit [0-9]
integer {digit}+
character [a-zA-Z]
identifier {character}({character}|{digit})*
characterConst \'{character}\'
%%
":" RETURN(symbol, COLON);
";" RETURN(symbol, SEMICOLON);
"." RETURN(symbol, DOT);
"," RETURN(symbol, COMMA);
"'" RETURN(symbol, APOST);
"->" RETURN(symbol, ASSIGN);
"(" RETURN(symbol, BRA);
")" RETURN(symbol, KET);
"+" RETURN(symbol, PLUS);
"-" RETURN(symbol, MINUS);
"*" RETURN(symbol, TIMES);
"/" RETURN(symbol, DIV);
"=" RETURN(comparator, EQUAL);
"<>" RETURN(comparator, NOTEQ);
"<" RETURN(comparator, LESSTHAN);
">" RETURN(comparator, MORETHAN);
"<=" RETURN(comparator, LESSEQUAL);
">=" RETURN(comparator, MOREEQUAL);
ENDP RETURN(keyword, ENDP);
CODE RETURN(keyword, CODE);
OF RETURN(keyword, OF);
TYPE RETURN(keyword, TYPE);
DECLARATIONS RETURN(keyword, DECL);
IF RETURN(keyword, IF);
THEN RETURN(keyword, THEN);
ELSE RETURN(keyword, ELSE);
ENDIF RETURN(keyword, ENDIF);
DO RETURN(keyword, DO);
WHILE RETURN(keyword, WHILE);
ENDDO RETURN(keyword, ENDDO);
ENDWHILE RETURN(keyword, ENDWHILE);
FOR RETURN(keyword, FOR);
IS RETURN(keyword, IS);
BY RETURN(keyword, BY);
TO RETURN(keyword, TO);
ENDFOR RETURN(keyword, ENDFOR);
WRITE RETURN(keyword, WRITE);
NEWLINE RETURN(keyword, NEWL);
READ RETURN(keyword, READ);
NOT RETURN(keyword, NOT);
AND RETURN(keyword, AND);
OR RETURN(keyword, OR);
CHARACTER RETURN(vartype, CHAR);
INTEGER RETURN(vartype, INT);
REAL RETURN(vartype, REAL);
{ws} ; /* Do nothing */
{integer} {
	
	#ifndef PRINT
	yylval.iVal = atoi(yytext);
	#endif

	RETURN(number, NUMBER);
	}
{characterConst} {
	char character;

	#ifndef PRINT
	character = yytext[1];
	yylval.iVal = character;
	#endif

	RETURN(character, CHARCONST);
	}
{identifier} {

	#ifndef PRINT
	yylval.iVal = installId(yytext);
	#endif 

	RETURN(identifier, IDEN);
	}

%%


#ifndef PRINT
/* Here is the code for the library of symbol table routines */

/* code for a simple symbol table, which is an array of pointers to
   structs, each of which contains an identifier.
*/


SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}
#endif

