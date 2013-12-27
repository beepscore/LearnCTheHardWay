#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// forward declarations
bool can_print_it(char ch);
void print_letters(char arg[]);
void print_letter(char ch);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for (i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
}

/** for each character in string argument,
 *  prints character and ASCII integer code
 */
void print_letters(char arg[])
{
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++) {
        print_letter(arg[i]);
    }
    printf("\n");
}

/** return true if ch is alpha or blank
 *  else return false
 */
bool can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

/** print letter if it is alpha or blank
 *  else don't print
 */
void print_letter(char ch)
{
    if (can_print_it(ch)) {
        printf("'%c' == %d ", ch, ch);
    }
}

int main(int argc, char *argv[]) {
    // note syntax is argv not argv[]
    print_arguments(argc, argv);
    return 0;
}
