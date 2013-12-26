#include <stdio.h>

// OS sets argc to count of elements in argv array
int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // Why am I skipping argv[0]?
    // Answer: argv[0] is the name of the program
    printf("argv[0]: %s\n", argv[0]);

    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    // each char * string is an array, and states is an array of arrays
    // states index |  string index
    // ------------ |  ------------
    //            0 |  0123456789
    //              |  California
    //            1 |  012345
    //              |  Oregon
    //            2 |  0123456789
    //              |  Washington
    //            3 |  01234
    //              |  Texas
    //
    // char *states[] = { "California", "Oregon", "Washington", "Texas" };

    //     ➜  LearnCTheHardWay git:(master) ✗ ./ex10 'foo' 'bar'
    // argv[0]: ./ex10
    // arg 1: foo
    // arg 2: bar
    // state 0: California
    // state 1: Oregon
    // state 2: (null)
    // state 3: Texas

    char *states[] = {
        "California", "Oregon",
        NULL, "Texas"
    };

    // setting num_states too big causes
    // [1]    2539 segmentation fault  ./ex10 'foo' 'bar'
    // int num_states = 6;
    int num_states = 4;

    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
