#include<stdio.h>
#include<string.h>
#include<assert.h>
#include "tokenlib.h"


// i have created operator // to make commenting condition																									
int main(int argc, char* argv[])																
{
	int i,j;
	char now[50],ch,ch1;
	char store[800000],*p;
	int n=0,si=0;

	FILE *fin = freopen(argv[1],"r",stdin);
	FILE *fout = freopen(argv[2],"w",stdout);

	assert(fin!=NULL);
	assert(fout!=NULL);

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
							for(j=0;j<n;j++)
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
	
	for(i=0;i<si;i++) {
		fprintf(fout,"%c",store[i]);
	}

	return 0;
					
}					
					
					
	
	
		
		