#include "galois.h"

#include <assert.h>
#define P 5

bool equal(GF first, GF second){
    return first.value == second.value;
}

GF create(uint8_t value){
    assert(value < P);
    GF gf;
    gf.value = value;
    return gf;
}


GF add(GF first, GF second){
    uint16_t f, s, r;
    f = first.value; s = second.value;
    r = f + s;
    return create(r % P);
}


GF negate(GF first){
    return create(P - first.value % P);
}


GF substract(GF first, GF second){
    return add(first, negate(second));
}


GF multiply(GF first, GF second){
    uint16_t f, s, r;
    f = first.value; s = second.value;
    r = f * s;
    return create(r % P);
}


GF invert(GF first){
    assert(first.value != 0 && "Zero has no inverse!");
    for(uint8_t candidate = 0; candidate < P; candidate ++){
        if(equal(multiply(create(candidate), first), create(1))){
            return create(candidate);
        }
    }
    assert(false && "Every non-zero number has an inverse!");
}


GF division(GF first, GF second){
    return multiply(first, invert(second));
}