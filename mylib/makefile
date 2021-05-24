CC=gcc
COMPILE=$(CC) -c
LINK=$(CC)

.c.o:
	$(COMPILE) -I. $< -o $@
	
a.out: mem_lib.h str_lib.h main.o mem_lib.o str_lib.o
	$(LINK) main.o mem_lib.o str_lib.o -o $@

all: a.out

clean:
	rm -f *.o
