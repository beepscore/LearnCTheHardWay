#include <stdio.h>
// http://en.wikipedia.org/wiki/Assert.h
#include <assert.h>
// include stlib for malloc
// http://en.wikipedia.org/wiki/C_standard_library
#include <stdlib.h>
// include string for strdup
#include <string.h>

// struct groups related variables and enables reference like joe->age
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    // allocate memory to hold struct
    struct Person *who = malloc(sizeof(struct Person));

    // check malloc returned valid pointer, not unset or invalid pointer
    // if assert() is false, writes to stderr and calls abort()
    // e.g. Assertion failed: (who != NULL), function Person_create, file ex16.c, line 19.
    assert(who != NULL);

    // intialize
    // Ensure the struct owns name. Use strdup to allocate memory and duplicate string.
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

/** if argument is NULL, program will abort with message similar to
 * Assertion failed: (who != NULL), function Person_destroy, file ex16.c, line 40.
 */
void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    // free memory to avoid memory leak
    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
    "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
    "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location: %p\n", joe);
    Person_print(joe);

    printf("Frank is at memory location: %p\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
