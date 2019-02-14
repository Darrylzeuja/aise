CC=gcc
CFLAGS=-O3 -g
LDFLAGS=-Wl,-rpath,$(PWD) 

TARGET=test
 
all: $(TARGET)

libppm.so : ppm.c
	$(CC) $(CFLAGS)  -fpic -shared $^ -o $@

test: test.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) -L. test.c -o $@ -lppm 

clean:
	rm -fr $(TARGET) *.so
