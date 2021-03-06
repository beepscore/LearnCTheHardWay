#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    printf("What's your First Name? ");
    // get string from stdin, make sure to not overflow buffer
    // don't use gets, it doesn't know buffer size and can easily corrupt memory.
    // in = gets(you.first_name);
    // OS X terminal warns-
    // warning: this program uses gets(), which is unsafe.
    // running program shows
    // errno: Inappropriate ioctl for device
    in = fgets(you.first_name, MAX_DATA-1, stdin);
    // check macro requires function must have error: label
    check(NULL != in, "Failed to read first name.");

    printf("What's your Last Name? ");
    in = fgets(you.last_name, MAX_DATA-1, stdin);
    check(NULL != in, "Failed to read last name.");

    printf("How old are you? ");
    // fscanf first argument specifies an input stream, e.g. stdin
    // last argument is a pointer so fscanf can set the value of you.age
    // int rc = fscanf(stdin, "%d", &you.age);
    // alternatively, can use scanf.
    // scanf is more specialized, it always reads from stdin
    int rc = scanf("%d", &you.age);
    // check return code
    check(rc > 0, "You have to enter a number.");


    printf("What color are your eyes?\n");
    for (i = 0; i <= OTHER_EYES; i++) {
        // display 1 based indices, even though array is 0 based
        printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    check(rc > 0, "You have to enter a number.");

    // convert answer from 1 based display index to 0 based array index
    you.eyes = eyes - 1;
    // check index is within array bounds
    check(((you.eyes >= 0) && (you.eyes <= OTHER_EYES)), "Do it right, that's not an option.");

    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number.");

    printf("----- RESULTS -----\n");

    printf("First Name: %s", you.first_name);
    printf("Last Name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;

error:
    return -1;
}
