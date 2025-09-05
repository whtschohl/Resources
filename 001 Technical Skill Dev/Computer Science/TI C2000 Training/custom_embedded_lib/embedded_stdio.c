
#include <stdint.h>
#include "embedded_stdio.h"

void uint16_to_str(uint16_t value, char *buf)
{
    char temp[6];
    int i = 0, j = 0;

    do {
        temp[i++] = (value % 10) + '0';
        value /= 10;
    } while (value > 0);

    while (i > 0) {
        buf[j++] = temp[--i];
    }
    buf[j] = '\0';
}
