all: isingModel
	clang -o result.out -g3 main.c ./*.so
isingModel:
	clang -o isingModel.so isingModel.c --shared -lm
clean:
	rm *.so
