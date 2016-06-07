/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *fp;

int lnx=25,lny=710,flag1=0,myline=5,sty=0,stx=0,anx=30;
char strln[10000][4];
char strfn[50000];

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
"include","define","ifdef","ifndef","endif"};

void *an(void)
{
	iShowBMP(0,80, "title.bmp");
	return NULL;
}

void imyText(double x,double y,char *tp)
{
	int i=0;
	double tpx=x;
	double tpy=y;
	char ttp[2]="a";
	while(tp[i]!=NULL)
	{
		ttp[0]=tp[i];
		ttp[1]=0;
		iText(tpx,tpy,ttp);
		tpx+=8;
		i++;
	}
}

void myiText(char *sp)
{
	int i=0,j=0,re=0;
	int tx=anx=32-(stx*8),ty=710+(sty*15);
	char c='a';
	char str[80]="\0";
	for(;c!=0;)
	{
		iSetColor(255,0,255);
		c=sp[i++];
		if(c=='_')
		{
			str[j++]=c;
			continue;
		}
		if(!isalpha(c))
		{
			str[j++]=0;
			j=0;
			for(re=0;re<80;re++)
			{
				if(!strcmp(reserve[re],str))break;
			}
			if(re<80)iSetColor(255,0,128);
			else iSetColor(255,0,255);
			//str[j++]=c;
			
			imyText(tx,ty,str);
			tx=tx+8*strlen(str);
			str[0]=0;
			if(c=='\n')
			{
				tx=anx;
				ty=ty-15;
				continue;
			}
			if(c=='\t')
			{
				tx=tx+45;
				continue;
			}
		
			if(c=='#')
			{
				iSetColor(255,0,128);
				imyText(tx,ty,"#");
				tx=tx+8;
				iSetColor(255,0,255);
				continue;
			}
			str[j++]=c;
			str[j]=0;
			j=0;
			iSetColor(255,0,255);
			imyText(tx,ty,str);
			tx=tx+8*strlen(str);
			str[0]='\0';	
			
		}
		else
		{
			str[j++]=c;
		}
	}
}


void iLine(void)
{
	int k=0;
	lnx=8-(stx*8);lny=710+(sty*15);
	iSetColor(0,212,212);
	for(k=0;k<myline-4;k++)
	{
		imyText(lnx,lny,strln[k]);
		lny-=15;
	}
}

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();
	if(flag1==1)
	{
		if(myline>55)
		{
			iLine();
			myiText(strfn);
			iSetColor(212,212,212);
			//iShowBMP(550,100,"Arrowright.bmp");
		}
		else
		{
			iLine();
			myiText(strfn);
		}
	}
	if(flag1==0)
	{
		iShowBMP(0,120, "CCB2.bmp");
		//iSetTimer(100000,an());
		//iShowBMP(600,400, "Moosasir.bmp");
		//iShowBMP(200,500, "Ayon.bmp");
		iSetColor(64,128,128);
		iFilledRectangle(0,0,800,120);
		iSetColor(255,255,255);
		iText(75,45, "Click the left button to start beautifier");
	}
}



/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		flag1=1;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if((key == GLUT_KEY_DOWN)||(key == GLUT_KEY_PAGE_DOWN))
	{
		sty++;
	}
	if((key == GLUT_KEY_UP)||(key == GLUT_KEY_PAGE_UP))
	{
		if(sty>0)sty--;
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(stx>0)stx--;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		stx++;
	}
	//place your codes for other keys here
}

int main()
{
	int i,j=0;
	char ch='a',filename[80];
	//place your own initialization codes here.
	printf("Enter the file name(it have to be saved in the directory where the graphics.cpp is saved) to show in graphical Notepad:");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	for(i=0;ch!=EOF;i++)
	{
		ch=fgetc(fp);
		if(ch=='\n')myline++;
		if(ch==EOF) break;
		strfn[i]=ch;
	}
	strfn[i]=0;
	for(i=0;i<myline;i++)
	{
		j++;
		sprintf(strln[i],"%3d",j);
	}
	iInitialize(800, 720, "demooo");
	return 0;
}	
