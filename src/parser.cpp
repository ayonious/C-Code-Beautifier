#include <assert.h>
#include <stdio.h>
#include <string.h>

void ungets(FILE *f, char *s)
{
	int i;
	for(i=0;i<(int)strlen(s);i++)
	{
		ungetc(s[strlen(s)-1-i],f);
	}
}


void indent(int n,FILE *fout)
{
	int i;
	for(i=0;i<n;i++)
		fprintf(fout,"\t");
}

int isLineBreaker(char *s) 
{
	return (strcmp(s,";")==0) ;
}

void conditionHeader(FILE *fin, FILE *fout, int cnt) 
{
	char s[100];

	int sc=0;
	int p=0;
	
	while(fscanf(fin,"%s",&s)==1)
	{
		fprintf(fout,"%s ",s);

		if(isLineBreaker(s)) 
		{
			sc++;
		}
		else if(s[0]=='(')
		{
			p++;
		}
		else if(s[0]==')')
		{
			p--;
		}

		if(p==0 && sc==cnt)
			break;
	}
}

void formatBlock(FILE *fin, FILE *fout, int d, int flg)
{
	char s[100];
	
	int nl=0;

	while(fscanf(fin,"%s",&s)==1)
	{
		

		if(strcmp(s,"}")==0)
		{
			indent(d-1,fout);
			fprintf(fout,"%s\n",s);
			break;
		}
		else if(strcmp(s,"{")==0)
		{
			fprintf(fout,"\n");
			indent(d,fout);
			fprintf(fout,"%s\n",s);
			indent(d+1,fout);
			formatBlock(fin,fout,d+1,0);
			nl=1;
			continue;
		}

		if(nl)
		{
			indent(d,fout);
			nl=0;
		}

		fprintf(fout,"%s ",s);

		if(strcmp(s,"for")==0)
		{
			conditionHeader(fin,fout,2);
			fprintf(fout,"\n");
			fscanf(fin,"%s",&s);
			if(s[0]=='{')
			{//compound statement
				indent(d,fout);
				fprintf(fout,"%s\n",s);
				indent(d+1,fout);
				formatBlock(fin,fout,d+1,0);
			}
			else 
			{
				indent(d+1,fout);
				ungets(fin,s);
				formatBlock(fin,fout,d+1,1);
			}
			if(flg)
				break;
			nl=1;
		}
		else if(strcmp(s,"while")==0)
		{
			conditionHeader(fin,fout,0);
			fprintf(fout,"\n");
			fscanf(fin,"%s",&s);
			if(s[0]=='{') 
			{//compound statement
				indent(d,fout);
				fprintf(fout,"%s\n",s);
				indent(d+1,fout);
				formatBlock(fin,fout,d+1,0);
			}
			else 
			{
				indent(d+1,fout);
				//fprintf(fout,"%s ",s);
				ungets(fin,s);
				formatBlock(fin,fout,d+1,1);
			}
			if(flg)
				break;
			nl=1;
		}
		else if( strcmp(s,"if")==0 )
		{
			conditionHeader(fin,fout,0);
			fprintf(fout,"\n");
			fscanf(fin,"%s",&s);
			if(s[0]=='{')
			{//compound statement
				indent(d,fout);
				fprintf(fout,"%s\n",s);
				indent(d+1,fout);
				formatBlock(fin,fout,d+1,0);
			}
			else
			{
				indent(d+1,fout);
				//fprintf(fout,"%s ",s);
				ungets(fin,s);
				formatBlock(fin,fout,d+1,1);
			}



			while(fscanf(fin,"%s",&s)==1) 
			{
				if(strcmp(s,"else")==0)
				{
					indent(d,fout);
					fprintf(fout,"%s ",s);
					fscanf(fin,"%s",&s);

					if(strcmp(s,"if")==0) 
					{ //  " else if "
						fprintf(fout,"%s ",s);
						conditionHeader(fin,fout,0);
						fprintf(fout,"\n");
						fscanf(fin,"%s",&s);
						if(s[0]=='{') 
						{//compound statement
							indent(d,fout);
							fprintf(fout,"%s\n",s);
							indent(d+1,fout);
							formatBlock(fin,fout,d+1,0);
						}
						else
						{
							indent(d+1,fout);
							//fprintf(fout,"%s ",s);
							ungets(fin,s);
							formatBlock(fin,fout,d+1,1);
						}
					}
					else
					{//	" else "
						fprintf(fout,"\n");
						//fscanf(fin,"%s",&s);
						if(s[0]=='{') 
						{//compound statement
							indent(d,fout);
							fprintf(fout,"%s\n",s);
							indent(d+1,fout);
							formatBlock(fin,fout,d+1,0);
						}
						else
						{
							indent(d+1,fout);
							//fprintf(fout,"%s ",s);
							ungets(fin,s);
							formatBlock(fin,fout,d+1,1);
						}
						nl=1;
						break;
					}
				}
				else 
				{
					ungets(fin,s);
					break;
				}
			}

			nl=1;
			if(flg)
				break;
		}
		else if(strcmp(s,"do")==0)
		{
			fprintf(fout,"\n");
			fscanf(fin,"%s",&s);
			if(s[0]=='{')
			{//compound statement
				indent(d,fout);
				fprintf(fout,"%s\n",s);
				indent(d+1,fout);
				formatBlock(fin,fout,d+1,0);
			}
			else
			{
				indent(d+1,fout);
				ungets(fin,s);
				formatBlock(fin,fout,d+1,1);
			}
			fscanf(fin,"%s",&s);//while
			indent(d,fout);
			fprintf(fout,"%s ",s);
			conditionHeader(fin,fout,0);
			fscanf(fin,"%s",&s);
			fprintf(fout,"%s\n",s);// ;
			if(flg)
				break;
			nl=1;
		}
		else if(isLineBreaker(s))
		{
			fprintf(fout,"\n");
			nl=1;
			if(flg)
				break;
		}
		/*else if(strcmp(s,"{")==0)
		{
			fprintf(fout,"\n");
			indent(d+1,fout);
			formatBlock(fin,fout,d+1,0);
			nl=1;
		}*/

	}
}



FILE *fin;
//FILE *ftmp;
FILE *fout;


int main(int argc, char* argv[]) 
{
	char s[1000];
	//freopen("tmp.txt","w",stdout);
	fin = freopen(argv[1],"r",stdin);
	fout = freopen(argv[2],"w",stdout);

	assert(fin!=NULL);
	assert(fout!=NULL);
	fscanf(fin,"%s",&s);
	while(strcmp(s,"#include")==0)
	{
		fprintf(fout,"%s",s);
		while(s[0]!='>')
		{
			fscanf(fin,"%s",&s);
			fprintf(fout,"%s",s);
		}
		fprintf(fout,"\n");
		fscanf(fin,"%s",&s);
		
	}
	ungets(fin,s);
	fprintf(fout,"\n\n\n\n");

	formatBlock(fin,fout,0,0);
	
	fclose(fin);
	fclose(fout);

	return 0;
	
}