#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Logical_operators

    if (argc == 1) {
        printf("You didn't add any arguments. You suck.\n");
    } else if (argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for (i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
