# Beautify/format your C/C++ code  
[![Build Status](https://travis-ci.org/ayonious/C-Code-Beautifier.svg?branch=master)](https://travis-ci.org/ayonious/C-Code-Beautifier)


## Build instructions: 

This is an optional step for those who wants some action building executables themselves :) you can skip this step and directly move to 'running instructions' stage
```
cd src
g++ Main.cpp parselib.cpp tokenlib.cpp -o c-code-beautifier
```
Now you will get the executables as 'c-code-beautifier'

## Running instructions:

```
./c-code-beautifier <inputfile> <outputfile>
```
 
Find the beautiful output in <outputfile>. You can try the test cases avilable in 'testcases' folder.

## Example Run
```
./c-code-beautifier testcases/13.txt pretty.txt
#output is ready in file pretty.txt
```


## Sample Input
```
#include<stdio.h> #include<conio.h>  if ( ) {
	    if ( ) the quik ; 
    else if ( ) 
		asdlkfjaskdjf ; 
else 
		asdfkljsdf ; }
```

## Sample output

```
#include<stdio.h>
#include<conio.h>
if ( ) 
{
	if ( ) 
		the quik ; 
	else if ( ) 
		asdlkfjaskdjf ; 
	else 
		asdfkljsdf ; 
}
```

