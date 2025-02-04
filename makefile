CC=gcc
HEADERS=raylib/build/raylib/include
LIBS=raylib/build/raylib

all: result.out

result.out: main.c
	$(CC) \
		-I $(HEADERS) \
		-L $(LIBS) \
		main.c -o result.out \
		-lraylib -lm

clean:
	rm -f result.out
