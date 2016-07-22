#include<stdio.h>
#include<string.h>
			
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
			
	


/*
char opers[44][4]={"+","-","*","/","%","==","!=","<","<=",">",">=","!","&&","||",
"~","&","|","^","<<",">>","=","+=","-=","*=","/=","%=","&=","|=",
"^=","<<=",">>=","++","--","&","*","[","]","?",":",".","->","(",")",","};
*/

char opers[69][4]={ "~","(",")","{","}","[","]",",",".","?",
"+","-","/","%","=","!","<","<",">",">","!","&","|",
"&","|","<",">","=","+","-","*","/","%","&","|","^","<",">","+","-","&","*","-",":",
"==","!=","<=",">=","&&","||","+=","-=","*=","/=","%=","&=","|=",
"^=","++","--","->","::","//","/*","*/",
"<<",">>",
"<<=",">>="};


char oone[10][2]={"~","(",")","{","}","[","]",",",".","?"};


char none[34][3]={"+","-","/","%","=","!","<","<",">",">","!","&","|",
"&","|","<",">","=","+","-","*","/","%","&","|","^","<",">","+","-","&","*","-",":"};


char otwo[21][3]={"==","!=","<=",">=","&&","||","+=","-=","*=","/=","%=","&=","|=",
"^=","++","--","->","::","//","/*","*/"};
		


char ntwo[2][3]={"<<",">>"};



char three[2][4]={"<<=",">>="};		







char now[50],ch,ch1;
char store[800000],*p;
int n=0,si=0;
			
			
	

		
			
// to print all the include headres			
void printinclude()
{		
	int i;
	for(i=1;i<=4;i++)
	{
		printf("%s",now);
		p+=strlen(now);while(*p==' ')p++;
	
	}
}			



//to print all the define headrs
void printdefene()
{
	int i;
	for(i=1;i<=3;i++)
	{
		printf("%s",now);
		p+=strlen(now);while(*p==' ')p++;
	
	}
}





// chek if reserved word is found
int resfound()
{
	int i;
	for(i=0;i<79;i++)
	{
		if(strcmp(reserve[i],now)==0)
			break;
	}
	return ((i==79)?0:1);
}


			
// the operator that has only one letter
int isoone(char ch)
{
	int i;
	for(i=0;i<10;i++)
		if(oone[i][0]==ch)
			break;
	if(i==10)		
		return 0;
	else		
		return 1;
}				
				
				
// the operator that has only one letter
int isnone(char ch)
{				
	int i;		
	for(i=0;i<34;i++)
		if(none[i][0]==ch)
			break;
	if(i==34)		
		return 0;
	else		
		return 1;
}				
				
				
// the operator that has only two letter
int isotwo(char	bla[])
{				
	int i;		
	for(i=0;i<21;i++)
		if(strcmp(bla,otwo[i])==0)
			break;
	if(i==21)		
		return 0;
	else		
		return 1;
}				
				
				
				
				
				
// the operator that has only two letter
int isntwo(char	bla[])
{		
	int i;
	for(i=0;i<2;i++)
		if(strcmp(bla,ntwo[i])==0)
			break;
	if(i==2)			
		return 0;
	else
		return 1;
}





				
// the operator that has only three letter
int isthree(char bla[])
{		
	int i;
	for(i=0;i<2;i++)
		if(strcmp(bla,three[i])==0)
			break;
	if(i==2)			
		return 0;
	else
		return 1;
}


//chek if the character is an operator
int op(char ch)
{
	int i;
	for(i=0;i<69;i++)
		if(opers[i][0]==ch)
			break;
	if(i==69)		
		return 0;
	else
		return 1;
}




// recognizing the chars	
int isch(char ch)
{
	if(((ch>='a')&&(ch<='z'))||((ch>='A')&&(ch<='Z'))||((ch>='0')&&(ch<='9')))
		return 1;
	else
		return 0;
}	


// i have created operator // to make commenting condition																									
int main(int argc, char* argv[])																
{
	int i,j,n=0;

	freopen(argv[1],"r",stdin);														
 	freopen(argv[2],"w",stdout);
	while((ch=getchar())!=EOF)												
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
				ch=getchar();
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
							ch=getchar();
							store[si++]=ch;
						}
						store[si++]=ch;
					}
					if(strcmp(now,"/*")==0)
					{
						store[si-3]='\n';
						store[si-2]='/';
						store[si-1]='*';
						scanf("%s",now);
						while(strcmp(now,"*/")!=0)
						{
							store[si++]=' ';
							n=strlen(now);
							for(j=0;j<n;j++)
								store[si++]=now[j];
							scanf("%s",now);
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
					ch=getchar();
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
			store[si++]=' ';   //shaon er kotai dilm kn j dilm
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
			while((ch=getchar())!='"')
				store[si++]=ch;
			n=0;
			now[n]='\0';
		}
		else if(ch=='\'') {
			// here is a bug left by ayon(me :D )  which is if there is a single ' then this code will not work
			
			store[si++]=ch;
			while((ch=getchar())!='\'')
				store[si++]=ch;
			n=0;
			now[n]='\0';
		}
		// all of these will indicate the cheking of reserved words
		else if((ch==' ')||(ch=='\t')||(ch=='\n')) {
			if(resfound()) {		
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
	
	for(i=0;i<si;i++) {
		printf("%c",store[i]);
	}

	return 0;
					
}					
					
					
	
	
		
		