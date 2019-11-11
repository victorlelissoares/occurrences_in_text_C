#include "no.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <limits.h>

//definição de uma lista duplamente encadeada, no caso, com cabeça
struct ldecc_st{
	no *cabeca;
};

typedef struct ldecc_st ldecc;

//definição de funções
ldecc *cria_nova_ldecc();
void imprime_ldecc(ldecc *lista, int num_arquivos);
void cnvr_lw(char frase[MAX]);
void insere_ordenado_ldecc(ldecc *lista, char palavra[MAX], int num_arquivos, int arq_atual);