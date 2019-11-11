//definição de uma string
//typedef char[100] string;
#define MAX 100
//definição de uma lista duplamente encadeada, cuja chave é uma palavra
struct no_st{
	struct no_st *ant;
	int *ocorrencias;
	char chave[MAX];
	struct no_st *prox;
};

typedef struct no_st no;