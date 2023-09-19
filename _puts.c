#include "main.h"

int _puts(const char *str) {
    int count = 0;
    while (*str) {
        _putchar(*str);
        count++;
        str++;
    }
    _putchar('\n');
    count++;  
    return count;
}
