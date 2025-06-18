#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <sys/cdefs.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((__noreturn__))
void abort(void);

char* itoa(int value, char* str, int base);
char* ltoa(uint64_t value, char* str, int base);

#ifdef __cplusplus
}
#endif

#endif
