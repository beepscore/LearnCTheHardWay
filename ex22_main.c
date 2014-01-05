#include "ex22.h"
#include "dbg.h"

// To compile on command line without make:
// $ cc -Wall -g -DNDEBUG   -c -o ex22.o ex22.c
// $ cc -Wall -g -DNDEBUG ex22_main.c ex22.o -o ex22_main
// To run
// $ ./ex22_main

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
    log_info("count parameter is: %d", count);

    if (count > 10) {
        // best practice- don't "shadow" a function argument
        // by declaring a local variable with the same name.
        int count = 100; // BAD! BUGS!
        log_info("count local variable in this scope is %d", count);
    }

    log_info("count parameter is at exit: %d", count);

    // This changes function parameter value locally, but not for caller.
    // If function scope_demo had a parameter that pointed to count "count_ptr",
    // then it could dereference the pointer and set the value of count in the caller's scope.
    count = 3000;
    log_info("count parameter after assign: %d", count);
}

int main(int argc, char *argv[])
{
    // test out THE_AGE accessors
    log_info("My name: %s, age: %d", MY_NAME, get_age());
    set_age(100);
    log_info("My age is now: %d", get_age());
    printf("\n");

    // test out THE_SIZE extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();
    THE_SIZE = 9;
    log_info("THE_SIZE is now: %d", THE_SIZE);
    print_size();
    printf("\n");

    // test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(300.0));
    printf("\n");

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("count after calling scope_demo: %d", count);

    return 0;
}
