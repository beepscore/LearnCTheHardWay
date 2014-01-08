#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

// function pointer type
typedef int (*lib_function)(const char *data);

int main(int argc, char *argv[])
{
    int rc = 0;
    check(4 == argc, "USAGE: ex29 libex29.so function data");

    // argument libfile is a dynamic library.
    // Dynamic library file extension is typically .so or .dll.
    // On OS X, file extension may be .dylib, .bundle, .framework.
    // static library file extension is typically .a (not used here)
    char *lib_file = argv[1];

    char *func_to_run = argv[2];
    char *data = argv[3];

    // open library, similar to opening a file
    void *lib = dlopen(lib_file, RTLD_NOW);
    // call dlerror() to find library related error
    check(NULL != lib, "Failed to open the library %s: %s", lib_file, dlerror());

    // dlsym argument lib is the library to search
    // dlsym argument func_to_run is the string name of the function
    // dlsym returns function pointer
    lib_function func = dlsym(lib, func_to_run);
    check(NULL != func, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

    // use function pointer func to call the function with argument data
    rc = func(data);
    check(0 == rc, "Function %s return %d for data: %s", func_to_run, rc, data);

    // close library, similar to closing a file
    rc = dlclose(lib);
    check(0 == rc, "Failed to close %s", lib_file);

    return 0;

error:
    return 1;
}
