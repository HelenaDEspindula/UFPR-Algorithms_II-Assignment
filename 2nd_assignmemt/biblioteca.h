// Aluna: Helena Regina Salomé D'Espindula
// GRR: 20161445

#ifndef __BIBLIOTECA__
#define __BIBLIOTECA__
#include <stdio.h>

/* --- Estrutura global --- */

typedef struct Conjunto_t
{
	unsigned int mum_elementos;
	unsigned int * conjunto;
} Conjunto_t ;

typedef struct Lista_t
{
	Conjunto_t * ant;
	Conjunto_t elementos;
	Conjunto_t * prox;
	
} Lista_t ;

/* --- Funções --- */

void le_arquivo();

int teste(int x);

#endif
