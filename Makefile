debug:
	clang src/info/os/*.c 		-c
	clang src/info/user/*.c 	-c
	clang src/info/system/*.c	-c
	clang src/main.c -c
	clang *.o -o bin/cfetch
	rm *.o

release:
	clang -O3 src/info/os/*.c 		-c
	clang -O3 src/info/user/*.c 	-c
	clang -O3 src/info/system/*.c -c
	clang -O3 src/main.c -c
	clang -O3 *.o -o bin/cfetch
	rm *.o
