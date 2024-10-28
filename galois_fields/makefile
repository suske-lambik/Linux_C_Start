all: galois galois_poly

galois: src/galois.c src/galois.h src/main.c
	gcc -Wall -Iinclude -O3 -march=native -o bin/galois -save-temps src/galois.c src/galois.h src/main.c

galois_poly: src/galois_poly.c
	gcc -Wall -Iinclude -O3 -march=native -o bin/galois_poly -save-temps src/galois_poly.c
