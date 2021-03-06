#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    // WARNING: On some systems you may have to change the
    // %ld in this code to a %u since it will use unsigned ints
    // sizeof returns number of bytes
    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n",
            sizeof(areas));
    printf("The number of ints in areas: %ld\n",
            sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d.\n",
            areas[0], areas[1]);
    areas[0] = 100;
    printf("The first area is %d.\n", areas[0]);
    // 'Z' ascii code is 90
    areas[0] = 'Z';
    printf("The first area is %d.\n", areas[0]);
    // printf("The eleventh area is %d.\n", areas[10]);

    printf("The size of a char: %ld\n", sizeof(char));
    // sizeof name is 4, "Zed" plus null terminator '\0'
    printf("The size of name (char[]): %ld\n",
            sizeof(name));
    printf("The number of chars: %ld\n",
            sizeof(name) / sizeof(char));

    printf("The size of full_name (char[]): %ld\n",
            sizeof(full_name));
    printf("The number of chars: %ld\n",
            sizeof(full_name) / sizeof(char));

    printf("name=\"%s\" and full_name=\"%s\"\n",
            name, full_name);
    name[1] = 'o';
    printf("name=\"%s\"\n", name);
    full_name[9] = 'i';
    printf("full_name=\"%s\"\n", full_name);

    return 0;
}
