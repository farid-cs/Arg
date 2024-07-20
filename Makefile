all: libarg.a
test: presence_test
%_test: %_test.c libarg.a
	clang -o $@ $< libarg.a
	./$@
	rm $@
libarg.a: arg.o
	ar rcs libarg.a arg.o
arg.o: arg.c arg.h
	clang -g -c $<
clean:
	rm -f *.o libarg.a
.PHONY: test clean all
