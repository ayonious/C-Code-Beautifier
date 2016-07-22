#include<stdio.h>
#include<string.h>
#include <assert.h>
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
	return i!=2;
}
// the operator that has only three letter
int isthree(char bla[])
{		
	int i;
	for(i=0;i<2;i++) if(strcmp(bla,three[i])==0) break;
	return i!=2;
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
// chek if reserved word is found
int resfound(char now[])
{
	int i;
	for(i=0;i<79;i++) if(strcmp(reserve[i],now)==0) break;
	return i!=79;
}

Tokenizer::Tokenizer(char *inputfile,char *tempfile) {
	n=0;
	si=0;
	fin = fopen(inputfile,"r");
	fout = fopen(tempfile,"w");

	assert(fin!=NULL);
	assert(fout!=NULL);
}

void Tokenizer::tokenize() {
	while((ch=fgetc(fin))!=EOF)												
	{
		prev:

		if(op(ch))
		{
			n=0;
			now[n]='\0';
			now[n++]=ch;
			now[n]='\0';


			store[si++]=' ';
			store[si++]=ch;
			//store[si++]=' ';

			if(isoone(ch))
			{
				store[si++]=' ';
				n=0;
				now[n]='\0';
				continue;
			}
			else if(isnone(ch))
			{
				ch=fgetc(fin);
				now[n++]=ch;
				now[n]='\0';
				if(isotwo(now))
				{
					store[si++]=ch;
					store[si++]=' ';
					if(strcmp(now,"//")==0)
					{
						store[si-3]='\n';
						store[si-2]='/';
						store[si-1]='/';
						while(ch!='\n')
						{
							ch=fgetc(fin);
							store[si++]=ch;
						}
						store[si++]=ch;
					}
					if(strcmp(now,"/*")==0)
					{
						store[si-3]='\n';
						store[si-2]='/';
						store[si-1]='*';
						//scanf("%s",now);
						fscanf(fin,"%s",now);
						while(strcmp(now,"*/")!=0)
						{
							store[si++]=' ';
							n=strlen(now);
							for(int j=0;j<n;j++)
								store[si++]=now[j];
							fscanf(fin,"%s",now);
						}
						store[si++]=' ';
						store[si++]='*';
						store[si++]='/';
						store[si++]='\n';
					}
					n=0;
					now[n]='\0';
					continue;
				}
				else if(isntwo(now))
				{
					store[si++]=ch;
					ch=fgetc(fin);
					now[n++]=ch;
					now[n]='\0';
					if(isthree(now))
					{
						store[si++]=ch;
						store[si++]=' ';

						
						n=0;
						now[n]='\0';
						continue;
					}
					else
					{
						store[si++]=' ';
						n=0;
						now[n]='\0';
						goto prev;
					}
				}
				else
				{
					store[si++]=' ';
					n=0;
					now[n]='\0';
					goto prev;
				}
			}
		}
		else if((ch==',')||(ch==';'))
		{
			n=0;
			now[n]='\0';
			store[si++]=' ';
			store[si++]=ch;
			store[si++]=' ';
			continue;
		}
		else if(ch=='(')
		{
			n=0;
			now[n]='\0';
			store[si++]=' ';
			store[si++]=ch;
			continue;
		}
		else if(((ch>='a')&&(ch<='z'))||(ch=='#')||(ch=='_'))
		{			
			now[n++]=ch;
			now[n]='\0';
		}
		else if(ch=='"') {
			//checking if it is in a prinf, scanf, string or means just a symbol
			// here is a bug left by ayon(me :D )  which is if there is a single " then this code will not work
			
			store[si++]=ch;
			while((ch=fgetc(fin))!='"')
				store[si++]=ch;
			n=0;
			now[n]='\0';
		}
		else if(ch=='\'') {
			// here is a bug left by ayon(me :D )  which is if there is a single ' then this code will not work
			
			store[si++]=ch;
			while((ch=fgetc(fin))!='\'')
				store[si++]=ch;
			n=0;
			now[n]='\0';
		}
		// all of these will indicate the cheking of reserved words
		else if((ch==' ')||(ch=='\t')||(ch=='\n')) {
			if(resfound(now)) {		
					store[si++]=' ';
					n=0;
					now[n]='\0';
			}
			else if((store[si-1]!=' ')&&(ch==' ')) {
				store[si++]=' ';
			}
			continue;
		}
		else
			n=0;

		store[si++]=ch;
	}
	
	for(int i=0;i<si;i++) {
		fprintf(fout,"%c",store[i]);
	}

	fclose(fin);
	fclose(fout);
}
