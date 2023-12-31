all: isingModel
	clang -o result.out -O3 main.c ./*.so
isingModel:
	gcc -o isingModel.so isingModel.c --shared -lm -fopenmp
clean:
	rm *.so
