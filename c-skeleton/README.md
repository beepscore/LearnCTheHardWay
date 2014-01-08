# Purpose
Do Learn C the Hard Way Exercise 28, 29.

# Reference
Learn C The Hard Way
by Zed Shaw
http://c.learncodethehardway.org/book/ex28.html

# Results

## compile the lib file and make the .so

    c-skeleton$ cc -c ./src/libex29.c -o ./build/libex29.o

    c-skeleton$ cc -shared -o ./build/libex29.so ./build/libex29.o

## make the loader program
    c-skeleton git:(master) ✗ cc -Wall -g -DNDEBUG ./src/ex29.c -ldl -o ./build/ex29

## try it out with some things that work
    c-skeleton$ ./build/ex29 ./build/libex29.so print_a_message "hello there"
    A STRING: hello there

    c-skeleton$ ./build/ex29 ./build/libex29.so uppercase "hello there"
    HELLO THERE

    c-skeleton$ ./build/ex29 ./build/libex29.so lowercase "HELLO tHeRe"
    hello there

    c-skeleton$ ./build/ex29 ./build/libex29.so fail_on_purpose "i fail"
    [ERROR] (./src/ex29.c:35:main: errno: None) Function fail_on_purpose return 1 for data: i fail

## try to give it bad args
    c-skeleton$ ./build/ex29 ./build/libex29.so fail_on_purpose
    [ERROR] (./src/ex29.c:11:main: errno: None) USAGE: ex29 libex29.so function data

## try calling a function that is not there
    c-skeleton$ ./build/ex29 ./build/libex29.so foo bar
    [ERROR] (./src/ex29.c:31:main: errno: None) Did not find foo function in the library ./build/libex29.so: dlsym(0x7ff91ad00000, foo): symbol not found

## try loading a .so that is not there
    c-skeleton$ ./build/ex29 ./build/lib_not_there.so foo bar
    [ERROR] (./src/ex29.c:25:main: errno: No such file or directory) Failed to open the library ./build/lib_not_there.so: dlopen(./build/lib_not_there.so, 2): image not found

## run make
➜  c-skeleton git:(master) ✗ make
cc -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG  -fPIC   -c -o src/ex29.o src/ex29.c
clang: warning: argument unused during compilation: '-rdynamic'
cc -g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG  -fPIC   -c -o src/libex29.o src/libex29.c
clang: warning: argument unused during compilation: '-rdynamic'
src/libex29.c:36:33: warning: unused parameter 'msg' [-Wunused-parameter]
int fail_on_purpose(const char *msg)
                                ^
1 warning generated.
ar rcs build/libYOUR_LIBRARY.a src/ex29.o src/libex29.o
ranlib build/libYOUR_LIBRARY.a
cc -shared -o build/libYOUR_LIBRARY.so src/ex29.o src/libex29.o
# run shell script to run tests
sh ./tests/runtests.sh
Running unit tests:

## compile dynamic library on OS X
http://stackoverflow.com/questions/885451/makefile-for-shared-libraries?rq=1
http://stackoverflow.com/questions/2339679/what-are-the-differences-between-so-and-dylib-on-osx
http://stackoverflow.com/questions/14173260/creating-shared-libraries-in-c-for-osx

### -rdynamic flag not supported on OSX
http://lists.apple.com/archives/unix-porting/2005/Feb/msg00025.html
Answer:
Just drop the flag. On some systems it ensures that the executable has it's
global symbols put into the symbol table. This is already the default behavior on darwin.

