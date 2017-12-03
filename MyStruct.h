#define GPIO_IN 0
#define GPIO_OUT 1
struct gpio {
        short pin;
        short direction; //-1: INV, 0: IN, 1: OUT
        short value; //0 or 1
}; //gpio
