all: sample
sample: sample.o arg.o
	clang -o $@ $^
arg.o: arg.c arg.h
	clang -c $<
sample.o: sample.c arg.h
	clang -c $<
clean:
	rm -f *.o sample
.PHONY: clean all
