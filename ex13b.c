#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        if ((int)letter >= 65 && (int)letter <= 90) {
            // convert to lowercase
            // http://en.wikipedia.org/wiki/ASCII
            letter += 32;
        }

        // if letter is a vowel, print it uppercase
        switch (letter) {
            case 'a':
                printf("%d: 'a'\n", i);
                break;

            case 'e':
                printf("%d: 'e'\n", i);
                break;

            case 'i':
                printf("%d: 'i'\n", i);
                break;

            case 'o':
                printf("%d: 'o'\n", i);
                break;

            case 'u':
                printf("%d: 'u'\n", i);
                break;

            case 'y':
                if (i > 2) {
                    // it's only sometimes y
                    printf("%d: 'y'\n", i);
                }
                break;

            default:
                printf("%d: %c is not a vowel\n", i, letter);
        }
    }

    return 0;
}
