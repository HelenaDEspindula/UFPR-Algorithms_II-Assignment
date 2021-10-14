CFLAGS = -Wall -g -DDEBUG
LDFLAGS = -lm

objs = biblioteca.o programa.o

# Regra default

all: programa $(objs)

# Regras de ligação

programa: programa.c biblioteca.c
	gcc programa.c biblioteca.c -o programa $(CFLAGS) $(LDFLAGS)

# Regras de compilação

programa.o: programa.c biblioteca.h
	gcc -c programa.c $(CFLAGS)

biblioteca.o: biblioteca.c biblioteca.h
	gcc -c biblioteca.c $(CFLAGS)


