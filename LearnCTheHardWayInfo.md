# Purpose
Record info about Learn C The Hard Way

# References
http://c.learncodethehardway.org/book/

# Results

## 2013-09-30

### Example 1
Write file ex1.c
In terminal
➜  LearnCTheHardWay git:(master) make ex1
cc     ex1.c   -o ex1
ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.

http://stackoverflow.com/questions/16876984/gcc-warning-implicit-declaration-of-function-puts-is-invalid-in-c99
