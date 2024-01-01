all: isingModel
	clang -o result.out -g3 main.c ./*.so
isingModel:
	gcc -g3 -o isingModel.so isingModel.c --shared -lm -fopenmp
clean:
	rm *.so
