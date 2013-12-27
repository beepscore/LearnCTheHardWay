#include <stdio.h>
#include <ctype.h>

// forward declarations
void print_digits(char arg[]);
void print_letters(char arg[]);
void print_letter(char ch);
void print_digit(char ch);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    printf("print letters\n");
    for (i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }

    printf("\n");

    printf("print digits\n");
    for (i = 0; i < argc; i++) {
        print_digits(argv[i]);
    }
}

/** for each letter in string argument,
 *  prints letter and ASCII integer code
 */
void print_letters(char arg[])
{
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++) {
        print_letter(arg[i]);
    }
    printf("\n");
}

/** for each digit in string argument,
 *  prints digit and ASCII integer code
 */
void print_digits(char arg[])
{
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++) {
        print_digit(arg[i]);
    }
    printf("\n");
}

/** print character if it is alpha or blank
 *  else don't print
 */
void print_letter(char ch)
{
    if (isalpha(ch) || isblank(ch)) {
        printf("'%c' == %d ", ch, ch);
    }
}

/** print character if it is a digit
 *  else don't print
 */
void print_digit(char ch)
{
    if (isdigit(ch)) {
        printf("'%c' == %d ", ch, ch);
    }
}

int main(int argc, char *argv[]) {
    // note syntax is argv not argv[]
    print_arguments(argc, argv);

    return 0;
}
