//
//  main.c
//  LearnCTheHardWay
//
//  Created by Steve Baker on 12/24/13.
//  Copyright (c) 2013 Beepscore LLC. All rights reserved.
//

#include <stdio.h>
// http://en.wikipedia.org/wiki/Assert.h
#include <assert.h>
// include stlib for malloc
// http://en.wikipedia.org/wiki/C_standard_library
#include <stdlib.h>
// include string for strdup
#include <string.h>

#define MAX_NAME 20

// struct groups related variables and enables reference like joe->age
// http://en.wikipedia.org/wiki/Struct_(C_programming_language)
// typedef-ing structs is controversial, it "pollutes" global namespace
// http://stackoverflow.com/questions/252780/why-should-we-typedef-a-struct-so-often-in-c
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Bird {
    char name[MAX_NAME];
    int age;
    int wingspan;
    int weight;
};

/** returns a pointer to a Person struct created on the heap
 */
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // allocate enough memory to hold one Person struct and set who to point to it
    struct Person *who = malloc(sizeof(struct Person));

    // check malloc returned valid pointer, not unset or invalid pointer
    // if assert() is false, writes to stderr and calls abort()
    // e.g. Assertion failed: (who != NULL), function Person_create, file ex16.c, line 19.
    assert(who != NULL);

    // intialize
    // Ensure the struct owns name. Use strdup to allocate memory and duplicate string.
    // syntax who->name dereferences who and then accesses name
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

/** returns a Bird struct created on the stack
 *  http://stackoverflow.com/questions/10916799/how-to-create-a-struct-on-the-stack-in-c
 *  OS will free stack memory automatically
 */
struct Bird bird_create(char *name, int age, int wingspan, int weight)
{
    struct Bird a_bird;

    // intialize
    // Use strncpy to avoid allocating new memory on heap and eliminate need to call free() later in program
    // copy source to target up to n characters, fill any empties with '\0'
    // CAUTION: if source is as long or longer than n, strncpy doesn't set the last character null!
    // http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/
    // http://stackoverflow.com/questions/14950241/pointer-to-one-struct-in-another-writing-and-reading-it-from-file-gives-segfaul
    strncpy(a_bird.name, name, MAX_NAME);
    // Ensure last character is null.
    a_bird.name[sizeof(a_bird.name) - 1] = '\0';
    a_bird.age = age;
    a_bird.wingspan = wingspan;
    a_bird.weight = weight;

    return a_bird;
}

/** if argument is NULL, program will abort with message similar to
 * Assertion failed: (who != NULL), function Person_destroy, file ex16.c, line 40.
 */
void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    // free memory to avoid memory leak
    // if comment out free(who->name), Xcode Analyze doesn't warn
    // Xcode Instruments Profile leaks shows malloc 16 live bytes.
    free(who->name);
    free(who);
}

/** if argument is NULL, program will abort with message similar to
 * [1]    13866 segmentation fault  ./ex16
 */
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

void bird_print(struct Bird a_bird)
{
    printf("Name: %s\n", a_bird.name);
    printf("\tAge: %d\n", a_bird.age);
    printf("\tWingspan: %d\n", a_bird.wingspan);
    printf("\tWeight: %d\n", a_bird.weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
    "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
    "Frank Blank", 20, 72, 180);

    // make one bird structure
    // bill is a struct, not a pointer to a struct
    struct Bird bill = bird_create(
    "Bill Robin", 1, 11, 1);

    // print them out and where they are in memory
    printf("Joe is at memory location: %p\n", joe);
    Person_print(joe);

    printf("Frank is at memory location: %p\n", frank);
    Person_print(frank);

    printf("Bill is at memory location: %p\n", &bill);
    bird_print(bill);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    strncpy(bill.name, "billy", MAX_NAME);
    // Ensure last character is null.
    bill.name[sizeof(bill.name) - 1] = '\0';
    bill.age += 20;
    bill.wingspan += 1;
    bird_print(bill);

    // destroy every Person to clean up heap memory.
    // if comment out calls to Person_destroy, program runs.
    // Xcode Analyze reports
    // "Potential leak of memory pointed to by 'joe', same for frank
    // Xcode Instruments Profile leaks shows live bytes from malloc.
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}

