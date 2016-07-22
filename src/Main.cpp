#include<stdio.h>
#include<string.h>
#include<assert.h>
#include "tokenlib.h"
#include "parselib.h"

																								
int main(int argc, char* argv[])																
{	
	char tempfile[] = "tempfile.txt";

	Tokenizer *tokenizer = new Tokenizer(argv[1],tempfile);
	tokenizer->tokenize();

	Parser *parser = new Parser(tempfile,argv[2]);
	parser->parse();

	remove("tempfile.txt");

	return 0;					
}
