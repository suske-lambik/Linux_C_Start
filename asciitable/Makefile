all:
	make bin/asciitable

bin/asciitable: src/asciitable.c | bin
	gcc -Wall -Iinclude -o bin/asciitable src/asciitable.c

bin: 
	mkdir -p $@