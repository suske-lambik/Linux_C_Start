#ifndef GALOIS_H
#define GALOIS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct GF{
    uint8_t value;
} GF;

bool equal(GF first, GF second);
GF create(uint8_t value);
GF add(GF first, GF second);
GF negate(GF first);
GF substract(GF first, GF second);
GF multiply(GF first, GF second);
GF invert(GF first);
GF division(GF first, GF second);

#endif