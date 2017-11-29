all: HelloWorld MyCat

HelloWorld: hello_world.c
	gcc -Wall hello_world.c -o hello_world

MyCat: MyCat.c
	gcc -Wall MyCat.c -o MyCat
