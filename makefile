all: result.out

result.out: main.c
	gcc main.c -o result.out

clean:
	rm -f result.out
