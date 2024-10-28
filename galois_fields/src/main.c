#include <stdio.h>
#include "galois.h"


int main(void){
    printf("Hello\n");
    GF a = create(3);
    GF b = create(1);
    GF c = create(2);
    printf("3+3: %d\n", add(a, a).value);
    printf("3+2: %d\n", add(a, c).value);
    printf("3-1: %d\n", substract(a, b).value);
    printf("3*1: %d\n", multiply(a, b).value);
    printf("3*2: %d\n", multiply(a, c).value);
    printf("1/3: %d\n", invert(a).value);
    printf("3/2: %d\n", division(a, c).value);
    return 0;
}