#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = 0;
    while (i < argc) {
        printf("arg %d: %s\n", i, argv[i]);
        i++;
    }

    // let's make our own array of strings
    char *states[] = { "California", "Oregon", "Washington", "Texas" };

    int num_states = 4;
    // i = 0; // watch for this
    // while (i < num_states) {
    //     printf("state %d: %s\n", i, states[i]);
    //     i++;
    // }

    i = num_states - 1;
    while (i >= 0) {

        // don't use argv[0]
        if (i <= (argc-1)) {
            states[i] = argv[i+1];
            // both variables point to same address
            printf("&states[i] %d, &argv[i+1] %d\n", (int)states[i], (int)argv[i+1]);
        }
        printf("state %d: %s\n", i, states[i]);

        i--;
    }

    return 0;

    // sample output
    // ➜  LearnCTheHardWay git:(master) ✗ ./ex11 a b c d e
    // arg 0: ./ex11
    // arg 1: a
    // arg 2: b
    // arg 3: c
    // arg 4: d
    // arg 5: e
    // &states[i] 1493273013, &argv[i+1] 1493273013
    // state 3: d
    // &states[i] 1493273011, &argv[i+1] 1493273011
    // state 2: c
    // &states[i] 1493273009, &argv[i+1] 1493273009
    // state 1: b
    // &states[i] 1493273007, &argv[i+1] 1493273007
    // state 0: a
}
