all: hello

hello: src/hello-world.asm
	as src/hello-world.asm -o out/hello-world.o
	ld -s -o bin/hello-world out/hello-world.o

