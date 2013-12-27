#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frankenstein",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way, using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // setup pointers to the start of the arrays
    int *cur_age = ages;
    // cur_name type is char **, pointer to names.  names type is char *.
    // pointing to the first element of names is the same as pointing to names
    char **cur_name = names;

    // second way, using pointers
    for (i = 0; i < count; i++) {
        // dereference pointers to get values
        printf("%s is %d years old.\n",
                *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        // using cur_name and cur_age as arrays is confusing. Do it for teaching purposes.
        // ith index offsets address by i*sizeof(element)
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);

        printf("pointer addresses (cur_name + i): %d &cur_name[i]: %d\n",
                (int)(cur_name + i), (int)&cur_name[i]);
    }

    printf("---\n");

    // fourth way with pointers and a stupid complex way
    for (cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }

    return 0;
}
