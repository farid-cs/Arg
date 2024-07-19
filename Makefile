all: libarg.a
libarg.a: arg.o
	ar rcs libarg.a arg.o
arg.o: arg.c arg.h
	clang -g -c $<
sample: sample.o libarg.a
	clang -L. -larg -o $@ $^
sample.o: sample.c arg.h
	clang -c $<
clean:
	rm -f *.o libarg.a sample
.PHONY: clean all
