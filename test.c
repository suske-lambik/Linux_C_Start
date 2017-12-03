#include <stdio.h>
#include <string.h>

int main(){
        char str[5];
        char topSecret[5];
        strncpy(&topSecret, "TOPS!\n", 6);
        printf("str: %p\n", str);
        printf("TOP: %p\n", topSecret);
        printf("DIFF: %p\n", (void *) (topSecret - str));
        printf("Enter password: ");
        gets(str);
        printf("str: %p\n", str);
        printf("TOP: %p\n", topSecret);
        printf("DIFF: %p\n", (void *) (topSecret - str));
        printf(topSecret);
        printf("You entered: %s\n", str);
        if (strcmp(str, "lala")){
                printf("wrong\n");
                printf(topSecret);
        }
        
        
        return 0;
}
