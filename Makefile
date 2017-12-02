all: HelloWorld MyCat LoadTest GpioMgr Test CardGame

HelloWorld: hello_world.c
	gcc -Wall hello_world.c -o hello_world

MyCat: MyCat.c
	gcc -Wall MyCat.c -o MyCat

LoadTest: load.c
	gcc -Wall load.c -o LoadTest

GpioMgr: MyGpioMgr.c MyStruct.h
	gcc -Wall MyGpioMgr.c -o GpioMgr

CardGame: CardGame.c
	gcc -Wall CardGame.c -o CardGame

Test: test.c
	gcc -Wall test.c -o Test -fno-stack-protector
#~ 	gcc -Wall test.c -o Test -fno-stack-protector
