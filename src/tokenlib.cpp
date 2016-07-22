#include<stdio.h>
#include<string.h>
#include "tokenlib.h"


char reserve[80][40]={"and","and_eq","asm","auto",
"bitand","bitor","bool","break","case","catch","char",
"class","compl","const","const_cast","continue","default",
"delete","do","double","dynamic_cast","else","enum",
"explicit","export","extern","false","float","for","friend",
"goto","if","inline","int","long","mutable","namespace",
"new","not","not_eq","operator","or","or_eq","private",
"protected","public","register","reinterpret_cast","return",
"short","signed","sizeof","static","static_cast","struct",
"switch","template","this","throw","true","try","typedef",
"typeid","typename","union","unsigned","using","virtual",
"void","volatile","wchar_t","while","xor","xor_eq",
"#include","#define","#ifdef","#ifndef","#endif"};
char opers[69][4]={ "~","(",")","{","}","[","]",",",".","?",
"+","-","/","%","=","!","<","<",">",">","!","&","|",
"&","|","<",">","=","+","-","*","/","%","&","|","^","<",">","+","-","&","*","-",":",
"==","!=","<=",">=","&&","||","+=","-=","*=","/=","%=","&=","|=",
"^=","++","--","->","::","//","/*","*/",
"<<",">>","<<=",">>="};
char oone[10][2]={"~","(",")","{","}","[","]",",",".","?"};
char none[34][3]={"+","-","/","%","=","!","<","<",">",">","!","&","|",
"&","|","<",">","=","+","-","*","/","%","&","|","^","<",">","+","-","&","*","-",":"};
char otwo[21][3]={"==","!=","<=",">=","&&","||","+=","-=","*=","/=","%=","&=","|=",
"^=","++","--","->","::","//","/*","*/"};
char ntwo[2][3]={"<<",">>"};
char three[2][4]={"<<=",">>="};

// the operator that has only one letter
int isoone(char ch)
{
	int i;
	for(i=0;i<10;i++) if(oone[i][0]==ch) break;
	return i!=10;
}
// the operator that has only one letter
int isnone(char ch)
{				
	int i;		
	for(i=0;i<34;i++) if(none[i][0]==ch) break;
	return i!=34;
}				
// the operator that has only two letter
int isotwo(char	bla[])
{				
	int i;		
	for(i=0;i<21;i++) if(strcmp(bla,otwo[i])==0) break;
	return i!=21;
}
// the operator that has only two letter
int isntwo(char	bla[])
{		
	int i;
	for(i=0;i<2;i++) if(strcmp(bla,ntwo[i])==0) break;
	return (i!=2);
}
// the operator that has only three letter
int isthree(char bla[])
{		
	int i;
	for(i=0;i<2;i++) if(strcmp(bla,three[i])==0) break;
	return (i!=2);
}
//chek if the character is an operator
int op(char ch)
{
	int i;
	for(i=0;i<69;i++) if(opers[i][0]==ch) break;
	return i!=69;
}
// recognizing the chars	
int isch(char ch) {
	return (((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9')));
}