#include<stdio.h>
#include<string.h>

extern char reserve[80][40];
extern char opers[69][4];
extern char oone[10][2];
extern char none[34][3];
extern char otwo[21][3];
extern char ntwo[2][3];
extern char three[2][4];	
		
// the operator that has only one letter
int isoone( char );
// the operator that has only one letter
int isnone(char);
// the operator that has only two letter
int isotwo(char[]);
// the operator that has only two letter
int isntwo(char[]);
// the operator that has only three letter
int isthree(char []);
//chek if the character is an operator
int op(char);
// recognizing the chars	
int isch(char);
// chek if reserved word is found
int resfound(char[]);