all: loadcheck loader

loadcheck: src/loadcheck.c
	gcc -Wall -Iinclude -o bin/loadcheck src/loadcheck.c

loader: src/loader.c
	gcc -Wall -o bin/loader src/loader.c