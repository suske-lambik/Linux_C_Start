all:
	make bin/cardgame

bin/cardgame: src/cardgame.c | bin
	gcc -Wall -Iinclude -o bin/cardgame src/cardgame.c

bin: 
	mkdir -p $@