#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char name[4] = {'a'};
    // if you set one array element, C will fill remaining elements with 0
    int numbers[4] = {3};

    // first, print them out raw
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s\n", name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';
    // this is a bug, overwriting null terminator may not show up immediately
    // Sometimes changing order of variable declaration causes bug to show.
    // name[3] = 'B';

    // then print them out initialized.
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    // print numbers as chars
    numbers[0] = 'L';
    numbers[1] = 'a';
    numbers[2] = 'r';
    numbers[3] = '\0';
    printf("numbers: %c %c %c %c\n",
            numbers[0], numbers[1],
            numbers[2], numbers[3]);

    // print name as chars
    printf("name each: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    // print name as ints
    printf("name each: %d %d %d %d\n",
            name[0], name[1],
            name[2], name[3]);

    // print name like a string
    printf("name: %s\n", name);

    // another way to use name
    char *another = "Zed";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    // express name array as one integer
    // simple minded algorithm - shift bytes and add
    // this algorithm doesn't scale well for long strings
    int name_combined = (pow(2, 8) * name[1]) + name[0];
    // caution: if number is negative, sign of modulo remainder is implementation dependent!
    printf("name_combined: %d\n", name_combined);
    int name_combined0 = name_combined % 256;
    int name_combined1 = (name_combined - name_combined0) / 256;
    // print individual characters
    printf("name_combined0: %c\n", name_combined0);
    printf("name_combined1: %c\n", name_combined1);

    // C expresses array as one integer, the address of array element 0.
    // each subsequent element address is incremented by sizeof(element)
    // cast char to int to avoid compiler warning
    printf("&name as int: %d\n", (int)name);
    printf("&name[1]: %d\n", (int)(name + (sizeof(char)*1)));
    printf("&name[2]: %d\n", (int)(name + (sizeof(char)*2)));
    // dereference address to get value
    printf("name[0]: %c\n", *name);
    printf("name[1]: %c\n", *(name + (sizeof(char)*1)));
    printf("name[2]: %c\n", *(name + (sizeof(char)*2)));

    return 0;
}
