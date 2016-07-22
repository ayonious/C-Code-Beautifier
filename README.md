# Program that helps to align/beautify C/C++ code  


##Build instructions: (optional step for those who wants some action building executables themselves :) you can skip this step and directly move to 'running instructions' stage
```
cd src
g++ Main.cpp parselib.cpp tokenlib.cpp -o c-code-beautifier
```
Now you will get the executables as 'c-code-beautifier'

##Running instructions:

```
./c-code-beautifier <inputfile> <outputfile>
```

Find the beautiful output in <outputfile>. You can try the test cases avilable in 'testcases' folder
##Example Run
```
./c-code-beautifier 13.txt output.txt
#output is ready in file output.txt
```
