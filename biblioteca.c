// Aluna: Helena Regina Salomé D'Espindula - hrsde16
// GRR: 20161445

// Aluna: Louise Knauber - lk16
// GRR: 20161471

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#define TAM 2000


/* ---- Função que inicializa sentinela/lista ---- */ 

void cria_sent()
{
	num_conjuntos = 0;
	psentinela = malloc (sizeof(t_conjunto));
	if (psentinela == 0) 
	{
		perror ("Problema com Malloc") ; // Teste de malloc
		exit (2) ;
	}

	(*psentinela).anterior = psentinela; // equivale a ULTIMO
	
	(*psentinela).proximo = psentinela; //equivale a PRIMEIRO
}

/* ---- Função que lê as entradas---- */ 

void leitura_arquivo()
{
	char operacao;
	unsigned int num_itens = 0;
	unsigned int i;
	unsigned int temporario;
	unsigned int *vetor;

	vetor = (unsigned int*) malloc( sizeof(unsigned int) * (num_itens+2) );

	scanf("%u\n", &tamanho_maximo);

	inicializa_indice();

	scanf("%c ", &operacao);

	while (operacao != '0')
	{
		if (operacao != '*')
		{
			scanf("%u ", &num_itens);

			free(vetor);
			vetor = (unsigned int*) malloc( sizeof(unsigned int) * (num_itens+2) );

			if (ppindice == 0) 
			{
				perror ("Problema com Malloc") ; // Teste de malloc
				exit (7) ;
			}

			for(i = 0; i<(num_itens-1); i++)
			{
				scanf("%u ", &temporario);
				vetor[i] = temporario;
			}

			scanf("%u\n", &temporario);
			vetor[i] = temporario;
		}

		opera(operacao, num_itens, vetor);
		
		scanf("%c ", &operacao);
	}
	free (vetor);
}

/* ---- Função que determina a operação a ser executada com conjunto lido ---- */ 

void opera (char operacao, unsigned int num_itens, unsigned int vetor[] )
{
	char achou = 'n';
	char retornos = '0';
	t_conjunto * pbusca = NULL;

	if ( (operacao != '>') && (operacao != '<') && (operacao != '/') )
	{
		if (operacao == '*')
		{
			if (num_conjuntos > 0)
			{
				retornos = imprimir_lista();
			}
			printf("%c\n", retornos);
		}
		else
		{
			if (num_conjuntos == 0)
			{
				pbusca = psentinela;
			}
			else
			{
				pbusca = procura_conjunto (&achou, num_itens, vetor);
			}


			if (operacao == '=')
			{
				if (achou == 'n')
				{
					printf("E\n");
				}
				printf("0\n");
			}
			if (operacao == '+')
			{
				if (achou == 'n')
				{
					retornos = add_conjunto_antes(pbusca, num_itens, vetor);
				}
				else
				{
					printf("E\n"); // Já tem esse conjunto
				}
				printf("%c\n", retornos);
			}
			if (operacao == '-')
			{
				if (achou == 's')
				{
					retornos = remover_conjunto(pbusca, num_itens, vetor);
					printf("%c\n", retornos);
				}
				else
				{
					printf("E\n0\n");
				}
				
			}
		}
	}
	else
	{
		// Espaço para parte 2 do trabalho
	}

}

/* ---- Função que libera malloc da lista ---- */ 

void libera_mallocs()
{
	t_conjunto * libera = (*psentinela).proximo;
	t_conjunto * prox_libera;

	while (num_conjuntos > 0)
	{
		prox_libera = (*libera).proximo;
		free(libera);
		num_conjuntos--;
		libera = prox_libera;
	}
	free(psentinela);
	free(ppindice);
}

/* ---- Função que adiciona um conjunto a lista ---- */ 

char add_conjunto_antes(t_conjunto *pbusca, unsigned int num_itens, unsigned int vetor[] )
{
	unsigned int i;
	t_conjunto * ptemporario;
	
	ptemporario = malloc (sizeof(t_conjunto));
	if (ptemporario == 0) 
	{
		perror ("Problema com Malloc") ; // Teste de malloc
		exit (3) ;
	}

	(*ptemporario).num_elementos = num_itens;

	(*ptemporario).conjunto = malloc( sizeof(unsigned int) * num_itens );
	if ((*ptemporario).conjunto == 0) 
	{
		perror ("Problema com Malloc") ; // Teste de malloc
		exit (4) ;
	}
	for(i = 0; i < num_itens; i++)
	{
		(*ptemporario).conjunto[i] = vetor[i];
	}

	(*ptemporario).proximo = pbusca;

	(*ptemporario).anterior = (*pbusca).anterior;

	(*pbusca).anterior = ptemporario;

	(*(*ptemporario).anterior).proximo = ptemporario;
	
	num_conjuntos++;

	if ( ( (*(*ptemporario).anterior).num_elementos < (*ptemporario).num_elementos) || ((*ptemporario).anterior == psentinela) )
	{
		ppindice[((*ptemporario).num_elementos)] = ptemporario;
	}

	return('0');
}

/* ---- Função que imprime a lista ---- */ 

char imprimir_lista()
{
	unsigned int i, j;
	t_conjunto * ptemporario = (*psentinela).proximo;

	for(i = 0; i < num_conjuntos; i++)
	{
		printf("%u ", (*ptemporario).num_elementos);
		for(j = 0; j < ((*ptemporario).num_elementos - 1); j++)
		{
			printf("%u ", (*ptemporario).conjunto[j]);
		}
		printf("%u\n", (*ptemporario).conjunto[j]);

		ptemporario = (*ptemporario).proximo;
	}

	if (ptemporario == psentinela)
	{
		return('0');	
	}
	else
	{
		return('1');
	}

}

/* ---- Função que inicializa o indice da lista ---- */ 

void inicializa_indice()
{
	unsigned int i;

	ppindice = (t_conjunto**) malloc( sizeof(t_conjunto*) * (tamanho_maximo+2) );
	if (ppindice == 0) 
	{
		perror ("Problema com Malloc") ; // Teste de malloc
		exit (6) ;
	}
	
	for (i = 0; i<tamanho_maximo+2; i++)
	{
		ppindice[i] = NULL;
	}

	(*psentinela).num_elementos = tamanho_maximo * 2;
}

/* ---- Função que procura por um conjunto na lista ---- */ 

t_conjunto * procura_conjunto (char *achou, unsigned int num_itens, unsigned int vetor[] )
{
	unsigned int i = 0;
	t_conjunto * pbusca = ppindice[num_itens];

	if (pbusca == NULL)
	{
		pbusca = (*psentinela).proximo;
	}

	while  ( (*pbusca).num_elementos < num_itens)
	{
		pbusca = (*pbusca).proximo;
	}

	if ( (*pbusca).num_elementos > num_itens)
	{
		(*achou) = 'n';
		return(pbusca);
	}
	else // mesmo numero elementos
	{
		i = 0;
		while  ( ( (*pbusca).num_elementos == num_itens) && (i < num_itens) )
		{
			if ( (*pbusca).conjunto[i] < vetor[i] )
			{
				pbusca = (*pbusca).proximo;
				i = 0;
			}
			else if ( (*pbusca).conjunto[i] == vetor[i] )
			{
				i++;
			}
			else if ( (*pbusca).conjunto[i] > vetor[i] )
			{
				(*achou) = 'n';
				return(pbusca);
			}
		}
		if (i >= num_itens)
		{
			(*achou) = 's';
			return(pbusca);
		}
		else
		{
			(*achou) = 'n';
			return(pbusca);
		}
	}	
}

/* ---- Função que remove um conjunto da lista ---- */ 

char remover_conjunto(t_conjunto *pbusca, unsigned int num_itens, unsigned int vetor[] )
{
	if ( ppindice[(*pbusca).num_elementos] == pbusca )
	{
		if ( (*(*pbusca).proximo).num_elementos == (*pbusca).num_elementos )
		{
			ppindice[(*pbusca).num_elementos] = (*pbusca).proximo;
		}
		else
		{
			ppindice[(*pbusca).num_elementos] = NULL;
		}
	}

	(*(*pbusca).anterior).proximo = (*pbusca).proximo;
	(*(*pbusca).proximo).anterior = (*pbusca).anterior;

	num_conjuntos--;

	free((*pbusca).conjunto);
	free(pbusca);
	pbusca = NULL;
	
	return('0');
}


