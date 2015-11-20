default: build

build: test.c string.c string.h stringpile.c stringpile.h
	clang test.c string.c stringpile.c -o test -Wall -std=c99

test: build
	./test

clean:
	rm test
