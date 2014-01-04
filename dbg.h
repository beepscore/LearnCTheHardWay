#ifndef __dbg_h__
#define __dbg_h__

// http://c.learncodethehardway.org/book/ex20.html
// http://en.wikipedia.org/wiki/Variadic_macro

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
// preprocessor will eliminate all debug() messages
#define debug(M, ...)
#else
// log to stderr
// Use a variadic macro to wrap printf and handle variable number of arguments.
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (0 == errno ? "None" : strerror(errno))

// work like debug, but won't be ifdef'ed out
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d:) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// "best macro ever"
// if A isn't true, log error and jump function's to error: label for cleanup
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// "second best macro ever"
// put this in any part of a function that shouldn't run, such as in if or switch exceptional cases
// logs error and jumps to function's to error: label for cleanup
#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// check pointer is valid
#define check_mem(A) check((A), "Out of memory.")

// if not A, calls debug() and jumps to error: label
// use with NDEBUG to skip debug print and still jump to error: label
#define check_debug(A, M, ...) if (!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
