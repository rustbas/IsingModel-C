run: compile
	./result.out --temperature 1e-4 -nc 75 -nr 25 -nm 25000
compile: isingModel
	clang -o result.out -O3 main.c ./*.so
test: isingModel
	clang -o result.out -g3 main.c ./*.so -DTESTING
isingModel:
	gcc -O3 -o isingModel.so isingModel.c --shared -lm -fopenmp
clean:
	rm *.so
