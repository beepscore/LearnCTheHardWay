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
