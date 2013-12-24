# Purpose
Record info about Learn C The Hard Way

# References
http://c.learncodethehardway.org/book/

# Results

## 2013-09-30

### Exercise 1
Write file ex1.c
In terminal
➜  LearnCTheHardWay git:(master) make ex1
cc     ex1.c   -o ex1

ex1.c:3:5: warning: implicit declaration of function 'puts' is invalid in C99 [-Wimplicit-function-declaration]
    puts("Hello world.");
    ^
1 warning generated.

Fix this by #import <stdio.h>
http://stackoverflow.com/questions/16876984/gcc-warning-implicit-declaration-of-function-puts-is-invalid-in-c99

### Exercise 2
make ex1 figures out what to do.
make runs cc program compiler on source file ex1.c to produce executable file named ex1
cc is c compiler
cc     ex1.c   -o ex1

➜  LearnCTheHardWay git:(master) ✗ make --version
GNU Make 3.81
➜  LearnCTheHardWay git:(master) ✗ cc --version
Apple LLVM version 5.0 (clang-500.2.75) (based on LLVM 3.3svn)
Target: x86_64-apple-darwin12.5.0
Thread model: posix

Makefile must have tabs only, no spaces!!!!!!

### Exercise 3

    $ man 3 printf

3 corresponds to man section 3, for C library functions
http://stackoverflow.com/questions/62936/what-does-the-number-in-parentheses-shown-after-unix-command-names-mean
