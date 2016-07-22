# Program that helps to align/beautify C/C++ code  


##Build instructions: (optional step for those who wants some action building executables themselves :) you can skip this step and directly move to 'running instructions' stage
```
cd src
g++ tokenizer.cpp tokenlib.cpp -o tokenizer
g++ parser.cpp -o parser
```
Now you will get the executables as 'tokenizer' and 'parser'  

##Running instructions:

###step1: remove unnecessary tabs and spaces
```
./tokenizer <inputfile> <tempfile>
```

###step2: final parsing
```
./parser <tempfile> <outputfile>
```

Find the beautiful output in <outputfile>. You can try the test cases avilable in 'testcases' folder
##Example Run
```
./tokenizer 13.txt tempfile.txt
./parser tempfile.txt output.txt
#output is ready in file output.txt
```
