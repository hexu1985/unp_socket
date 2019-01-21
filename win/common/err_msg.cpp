#include "err_msg.hpp"

#include <stdarg.h>
#include <stdio.h>

void err_msg(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    fflush(stdout);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    fflush(stderr);
    va_end(args);
}

