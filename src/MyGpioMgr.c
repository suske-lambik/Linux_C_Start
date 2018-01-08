#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>

#include "MyStruct.h"

int main()
{
        struct gpio testPin;
        memset(&testPin, 0, sizeof(testPin));
        testPin.pin = 21;
        testPin.direction = GPIO_OUT;
        
        //export pin
        //todo
        
        //write value
        int value = open("/home/philippe/gpio21/value", O_WRONLY);
        if (value < 0){
                perror("Error opening file:");
                printf("pin %d not exported yet\n", value);
                return -1;
        }
        
        write(value, "1", 1);
}
