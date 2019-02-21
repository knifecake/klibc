CC      = gcc
CFLAGS  = -Wall -I include
LDFLAGS =

lib/libminitest.a: src/minitest.o
	ar rsv $@ $^

clean:
	rm -f src/*.o lib/*.a
