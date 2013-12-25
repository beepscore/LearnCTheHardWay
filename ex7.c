#include <stdio.h>

int main(int argc, char *argv[])
{

    int bugs = 100;
    double bug_rate = 1.2;

    printf("You have %d bugs at the imaginary rate of %f.\n",
            bugs, bug_rate);

    // long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L;
    // %ld long decimal
    // http://stackoverflow.com/questions/7152759/what-happens-when-i-assign-a-negative-value-to-an-unsigned-int?rq=1
    // http://en.wikipedia.org/wiki/Two's_complement
    unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L;
    unsigned long u_minus1 = universe_of_defects - 1;
    unsigned long u_plus1 = universe_of_defects + 1;
    printf("The entire universe has %u bugs.\n", universe_of_defects);
    printf("u_minus1 %u.\n", u_minus1);
    printf("u_plus1 %u.\n", u_plus1);

    double expected_bugs = bugs * bug_rate;
    printf("You are expected to have %f bugs.\n",
            expected_bugs);

    double part_of_universe = expected_bugs / universe_of_defects;
    // %e scientific notation
    printf("That is only a %e portion of the universe.\n",
            part_of_universe);

    // this makes no sense, just a demo of something weird
    char nul_byte = '\0';
    int care_percentage = bugs * nul_byte;
    // %% escape %
    printf("Which means you should care %d%%.\n",
            care_percentage);

    printf("nul_byte as char %c.\n", nul_byte);
    // printf("nul_byte as string %s.\n", nul_byte);

    return 0;
}
