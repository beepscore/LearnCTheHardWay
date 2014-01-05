#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

// Here static scopes the variable to this file.
// A static global variable or a function is "seen" only in the file it's declared in
// A static variable inside a function keeps its value between invocations.
// http://stackoverflow.com/questions/572547/what-does-static-mean-in-a-c-program
static int THE_AGE = 37;

// accessors
int get_age()
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}

double update_ratio(double new_ratio)
{
    // static is rarely used inside a function in modern C
    // difficult to keep thread safe.
    static double ratio = 1.0;

    double old_ratio = ratio;
    ratio = new_ratio;

    return old_ratio;
}

void print_size()
{
    log_info("I think size is: %d", THE_SIZE);
}

