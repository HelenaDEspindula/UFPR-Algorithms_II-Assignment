// Aluna: Helena Regina Salomé D'Espindula - hrsde16
// GRR: 20161445

// Aluna: Louise Knauber - lk16
// GRR: 20161471

#ifndef __BIBLIOTECA__
#define __BIBLIOTECA__
#include <stdio.h>

/* --- Estrutura global --- */

typedef struct conjunto
{
	unsigned int num_elementos;
	unsigned int * conjunto;
	struct conjunto * anterior;
	struct conjunto * proximo;
} t_conjunto ;
	
unsigned int num_conjuntos;
t_conjunto * psentinela;
t_conjunto * * ppindice;
unsigned int tamanho_maximo;


/* --- Funções --- */

void leitura_arquivo();

void opera(char operacao, unsigned int num_itens, unsigned int vetor[] );

void cria_sent();

void libera_mallocs();

char add_conjunto_antes(t_conjunto *pbusca, unsigned int num_itens, unsigned int vetor[] );

char imprimir_lista();

void inicializa_indice();

t_conjunto * procura_conjunto (char *achou, unsigned int num_itens, unsigned int vetor[] );

char remover_conjunto(t_conjunto *pbusca, unsigned int num_itens, unsigned int vetor[] );

#endif
