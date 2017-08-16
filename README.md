# Beautify/format your C/C++ code  
[![Build Status](https://travis-ci.org/ayonious/C-Code-Beautifier.svg?branch=master)](https://travis-ci.org/ayonious/C-Code-Beautifier)


## Build instructions: 

To build the binary from source:
```
g++ src/Main.cpp src/parselib.cpp src/tokenlib.cpp -o C-Code-Beautifier
```

To download directly:
Make sure you put the proper latest version instead of v0.7
```
curl -O "https://github.com/ayonious/C-Code-Beautifier/releases/download/v0.7/C-Code-Beautifier"
chmod +x C-Code-Beautifier
```

Now you will get the executables as 'C-Code-Beautifier'
## Running instructions:

```
./C-Code-Beautifier <inputfile_to_beformatted> <formatted_outputfile>
```
Find the beautiful output in <outputfile>. You can try the test cases avilable in 'testcases' folder.

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

