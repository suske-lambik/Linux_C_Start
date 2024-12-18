#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#define P 2  // Galois order
#define K 9  // Polynomial order
#define Q 256 // Irreducible polynomial: 10 base 3 = (1, 0, 1) = x^2 + 1
#define FIELD_SIZE (uint32_t) pow(P, K)

#define CASSERT(predicate, file) _impl_CASSERT_LINE(predicate,__LINE__,file)
#define _impl_PASTE(a,b) a##b
#define _impl_CASSERT_LINE(predicate, line, file) \
    typedef char _impl_PASTE(assertion_failed_##file##_,line)[2*!!(predicate)-1];

CASSERT(P < 256, galois_poly_c)
//CASSERT(P < 10, galois_poly_c)
//CASSERT(K < 10, galois_poly_c)

typedef struct GF{
    uint16_t values[K];
} GF;

GF create(uint32_t value){
    assert(value < FIELD_SIZE);
    GF gf;

    for(uint16_t i = 0; i < K; i++){
        gf.values[i] = (uint16_t) value % P;
        value /= P;
    }
    return gf;
}

uint32_t dump(GF value){
    uint32_t out = 0;
    for(uint16_t i = K; i > 0; i--){
        out = out * P + value.values[i - 1];
    }
    return out;
}

void print(GF value){
    for(uint16_t i = 0; i < K; i++){
        printf("%d ", value.values[i]);
    }
    printf("\n");
}

void pretty_print(GF value){
    for(uint16_t idx = 0; idx < K; idx++){
        uint16_t i = K - idx - 1;
        if(i == 0){
            printf("%d", value.values[i]);
        }
        else if(i==1){
            printf("%d*x", value.values[i]);
        }else{
            printf("%d*x^%d", value.values[i], i);
        }
        if(i > 0){
            printf(" + ");
        }
    }
    printf("\n");
}

void pretty_print2(uint8_t values[2*K-1]){
    for(uint16_t idx = 0; idx < (2*K-1); idx++){
        uint16_t i = 2*K - idx - 2;
        if(i == 0){
            printf("%d", values[i]);
        }
        else if(i==1){
            printf("%d*x", values[i]);
        }else{
            printf("%d*x^%d", values[i], i);
        }
        if(i > 0){
            printf(" + ");
        }
    }
    printf("\n");
}

bool equal(GF first, GF second){
    for(uint16_t i = 0; i < K; i++){
        if(first.values[i] != second.values[i]){
            return false;
        }
    }
    return true;
}

uint16_t coef_add(uint16_t first, uint16_t second){
    return ((uint32_t) first + (uint32_t) second) % P;
}

uint16_t coef_multiply(uint16_t first, uint16_t second){
    return ((uint32_t) first * (uint32_t) second) % P;
}

uint16_t coef_negate(uint16_t first){
    return (P - first) % P;
}

GF add(GF first, GF second){
    GF result;
    for(int i = 0; i < K; i++){
        result.values[i] = coef_add(first.values[i], second.values[i]);
    }
    return result;
}

GF negate(GF first){
    GF result;
    for(int i = 0; i < K; i++){
        result.values[i] = coef_negate(first.values[i]);
    }
    return result;
}

GF substract(GF first, GF second){
    return add(first, negate(second));
}

GF modulo(uint16_t first[2*K - 1], GF second){
    for(uint16_t i = (2*K-2); i > (K - 2); i--){
        uint16_t scale = coef_negate(first[i]);
        uint16_t shift = i - K + 1;
        for(uint16_t j = 0; j < K; j++){
            uint16_t val = coef_multiply(scale, second.values[j]);
            first[j + shift] = coef_add(first[j + shift], val);
        }

        assert(first[i] == 0);
    }

    GF result;
    for(uint16_t i = 0; i < K; i++){
        result.values[i] = first[i];
    }
    return result;
}

GF multiply(GF first, GF second){
    uint16_t temp[2*K-1];

    for(uint16_t i = 0; i < 2*K -1; i++){
        temp[i] = 0;
        for(uint16_t j = 0; j < K; j++){
            if(j > i || i - j >= K){
                continue;
            }
            uint16_t t = coef_multiply(first.values[i - j], second.values[j]);
            temp[i] = coef_add(temp[i], t);
            
        }
    }
    return modulo(temp, create(Q));
}

GF invert(GF first){
    assert(!equal(first, create(0)) && "Zero has no inverse!");
    for(uint8_t c = 0; c < FIELD_SIZE; c++){
        GF candidate = create(c);
        GF m = multiply(candidate, first);
        if(equal(m, create(1))){
            return candidate;
        }
    }
    assert(false && "Every non-zero number has an inverse!");
}

GF division(GF first, GF second){
    return multiply(first, invert(second));
}

int main(void){
    printf("Hello\n");
    printf("Params: P: %d, K: %d, Q:%d, FIELD_SIZE: %d\n", P, K, Q, FIELD_SIZE);
    //add
    assert(equal(add(create(0), create(1)), create(1)));
    assert(equal(add(create(1), create(1)), create(0)));
    assert(equal(add(create(1), create(2)), create(3)));
    assert(equal(add(create(2), create(2)), create(0)));
    assert(equal(add(create(1), create(3)), create(2)));
    assert(equal(add(create(8), create(8)), create(0)));
    //mul
    assert(equal(multiply(create(0), create(1)), create(0)));
    assert(equal(multiply(create(0), create(2)), create(0)));
    assert(equal(multiply(create(1), create(2)), create(2)));
    //div
    assert(equal(division(create(0), create(1)), create(0)));
    //division(create(1), create(0));
    assert(equal(division(create(1), create(1)), create(1)));
    return 0;
}