#include<stdio.h>
#include<string.h>
#include "tokenlib.h"

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
					
					
	
	
		
		