all: isingModel
	clang -o result.out main.c ./*.so
isingModel:
	clang -o isingModel.so isingModel.c --shared -lm
clean:
	rm *.so
