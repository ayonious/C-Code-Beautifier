#include <assert.h>
#include <stdio.h>
#include <string.h>


void ungets(FILE *f, char *s);
void indent(int n,FILE *fout);
int isLineBreaker(char *s);
void conditionHeader(FILE *fin, FILE *fout, int cnt);
void formatBlock(FILE *fin, FILE *fout, int d, int flg);
class Parser {
	private:	
	char s[1000];
	FILE *fin,*fout;
	public:
	Parser(char *tempfile,char *outputfile);
	void parse();
};
