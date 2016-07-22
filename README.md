# Program that helps to align/beautify C/C++ code  


##build instructions: (optional step for those who wants some action building executables themselves :) you can skip this step and directly move to 'running instructions' stage
```
g++ step1.c -o step1
g++ step2.c -o step2
```
Now you will get the executables as 'step1' and 'step2'  

##running instructions:

###step1: remove unnecessary tabs and spaces
```
./step1 <inpuetfile> <tempfile>
```

###step2: final parsing
```
./step2 <tempfile> <output>
```

You can try the test cases avilable in 'testcases' folder
##Example Run
```
./step1 13.txt tempfile.txt
./step2 tempfile.txt output.txt
```