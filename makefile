CC=gcc
HEADERS=raylib/include
LIBS=raylib/lib

all: result.out

result.out: main.c
	$(CC) \
		-I $(HEADERS) \
		-L $(LIBS) \
		main.c -o result.out \
		-lraylib

clean:
	rm -f result.out
