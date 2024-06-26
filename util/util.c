#include "util.h"

char* itoa(int value, char* str, int base) {
    char* rc;
    char* ptr;
    char* low;
    // Check for supported base.
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }
    rc = ptr = str;

    // Set '-' for negative decimals.
    if (value < 0 && base == 10) {
        *ptr++ = '-';
    }

    // Remember where the numbers start.
    low = ptr;

    // The actual conversion.
    do {
        // Modulo is negative for negative value. This trick makes abs() unnecessary.
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + value % base];
        value /= base;
    } while (value);

    // Terminating the string.
    *ptr-- = '\0';

    // Invert the numbers.
    while (low < ptr) {
        char tmp = *low;
        *low++ = *ptr;
        *ptr-- = tmp;
    }
    return rc;
}

char* itoa_simple(int value, char* str) {
    char* ptr = str;
    if (value < 0) {
        *ptr++ = '-';
        value = -value;
    }

    char* start = ptr;
    do {
        *ptr++ = '0' + (value % 10);
        value /= 10;
    } while (value);
    *ptr-- = '\0';

    // Reverse the number
    while (start < ptr) {
        char tmp = *start;
        *start = *ptr;
        *ptr = tmp;
        start++;
        ptr--;
    }
    return str;
}
