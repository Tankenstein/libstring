default: test

test: test.c string.c string.h
	clang test.c string.c -o test -Wall -std=c99
	./test
