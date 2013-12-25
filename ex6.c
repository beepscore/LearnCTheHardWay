#include <stdio.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    int thingy = 65;
    char empty_string[] = "";

    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    printf("You are %d miles away.\n", distance);
    printf("You have %f levels of power.\n", power);
    printf("You have %f awesome super powers.\n", super_power);
    printf("I have an initial %c.\n", initial);
    printf("I have a first name %s.\n", first_name);
    printf("I have a last name %s.\n", last_name);
    printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

    // thingy decimal 65.
    printf("thingy decimal %d.\n", thingy);
    // thingy octal 101.
    printf("thingy octal %o.\n", thingy);
    // thingy hex 41.
    printf("thingy hex %x.\n", thingy);
    // thingy char A.
    // http://en.wikipedia.org/wiki/ASCII
    printf("thingy char %c.\n", thingy);

    // empty_string .
    printf("empty_string %s.\n", empty_string);

    return 0;
}
