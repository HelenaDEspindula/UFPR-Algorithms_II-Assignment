# Aluna: Helena Regina Salomé D'Espindula - hrsde16
# GRR: 20161445

# Aluna: Louise Knauber - lk16
# GRR: 20161471

CFLAGS = -Wall -g
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

#remove arquivos temporários
clean:
	-rm $(objs) *~

#remove tudo o que não for código fonte
purge: clean
		-rm programa


