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

To execute compiled file
    $ ./ex1

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

Edit Makefile.
Makefile must have tabs only, no spaces!!!!!!

### Exercise 3

    $ man 3 printf

3 corresponds to man section 3, for C library functions
http://stackoverflow.com/questions/62936/what-does-the-number-in-parentheses-shown-after-unix-command-names-mean

### Exercise 4

#### valgrind
www.valgrind.org
Currently doesn't work with OS X Mavericks 10.9

#### Command line Clang static analyzer
I couldn't find scan-build.
http://clang-analyzer.llvm.org/scan-build.html

    $ scan-build make

Mountain Lion installed command line tools to /usr/bin and other system software directories.
In Mavericks Xcode 5 bundles command line tools in /Applications/Xcode.app e.g.
    /Applications/Xcode.app/Contents/Developer/usr/bin

Separate download will install to /Library/Developer/CommandLineTools/usr/bin

You can install both Xcode 5.0.x and the separate Xcode command line tools in Mavericks without a problem,
but Mavericks will prefer to use the tools that are bundled in /Applications/Xcode.app
and will ignore the tools installed into /Library/Developer unless Xcode.app is removed from the Mac.
https://derflounder.wordpress.com/2013/11/15/xcode-command-line-tools-included-with-xcode-5-0-x-on-mavericks/

#### Xcode
Even though tutorial wants to avoid IDE, use Xcode for now.
In Xcode File / Project / New Project / OS X / Application / Command Line Tool.
Name project LearnCTheHardWay.

### Exercise 6
Put arguments in wrong order:

    printf("My whole name is %s %c. %s.\n", initial, first_name, last_name);

vim syntax checker shows warning.

➜  LearnCTheHardWay git:(master) ✗ make ex6
cc -Wall -g    ex6.c   -o ex6
ex6.c:19:45: warning: format specifies type 'char *' but the argument has type 'char' [-Wformat]
    printf("My whole name is %s %c. %s.\n", initial, first_name, last_name);
                             ~~             ^~~~~~~
                             %c
ex6.c:19:54: warning: format specifies type 'int' but the argument has type 'char *' [-Wformat]
    printf("My whole name is %s %c. %s.\n", initial, first_name, last_name);
                                ~~                   ^~~~~~~~~~
                                %s
2 warnings generated.

➜  LearnCTheHardWay git:(master) ✗ ./ex6
You are 100 miles away.
You have 2.345000 levels of power.
You have 56789.453200 awesome super powers.
I have an initial A.
I have a first name Zed.
I have a last name Shaw.
[1]    2937 segmentation fault  ./ex6

