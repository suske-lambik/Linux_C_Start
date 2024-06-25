all:
	make bin/euro24

bin/euro24: src/euro24.c | bin
	gcc -Wall -Iinclude -o bin/euro24 src/euro24.c

bin: 
	mkdir -p $@