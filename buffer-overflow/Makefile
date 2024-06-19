all:
	make bin/bufferoverflow
	make bin/stacksmashing

bin/bufferoverflow: src/buffer-overflow.c | bin
	gcc -Wall -Iinclude -fno-stack-protector -o bin/bufferoverflow src/buffer-overflow.c

bin/stacksmashing: src/buffer-overflow.c | bin
	gcc -Wall -Iinclude -o bin/stacksmashing src/buffer-overflow.c

bin: 
	mkdir -p $@