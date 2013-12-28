#include <stdio.h>

int main(int argc, char *argv[])
{
    // References
    // C / Arrays and Array-pointer interchangeability
    // http://en.wikipedia.org/wiki/C_(programming_language)
    //
    // http://c-faq.com/aryptr/aryptrequiv.html
    // http://c-faq.com/aryptr/practdiff.html
    // http://c-faq.com/aryptr/aryptr2.html
    // http://stackoverflow.com/questions/10186765/char-array-vs-char-pointer-in-c

    // create two arrays we care about
    // ages is array of int
    int ages[] = {23, 43, 12, 89, 2};
    // names is array of strings, i.e. array of char *
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
    // cur_age is a pointer to ages, i.e. pointer to array of int.
    int *cur_age = ages;
    // cur_name is a pointer to names, i.e. pointer array of char *.
    // pointing to the first element of names is the same as pointing to names
    char **cur_name = names;

    // second way, using pointers
    for (i = 0; i < count; i++) {
        // dereference pointers to get values
        printf("%s is %d years old.\n",
                *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // third way.
    // Even though pointers are different from arrays, can sometimes use array syntax with a pointer.
    for (i = 0; i < count; i++) {
        // using cur_name and cur_age as arrays is confusing. Do it for teaching purposes.
        // ith index offsets address by i*sizeof(element)
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);

        // %p is format specifier for pointer.
        // Prints hex address, doesn't require cast to (long int)
        printf("pointer addresses (cur_name + i): %p &cur_name[i]: %p\n",
                (cur_name + i), &cur_name[i]);

        // %ld and cast to (long int) prints decimal address
        printf("pointer addresses (cur_name + i): %ld &cur_name[i]: %ld\n",
                (long int)(cur_name + i), (long int)&cur_name[i]);

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
