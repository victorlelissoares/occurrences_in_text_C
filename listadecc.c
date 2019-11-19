#include "listadecc.h"

/*cria nova lista duplamente encadeada vazia, e retorna um ponteiro para a mesma*/
ldecc *cria_nova_ldecc(){
	ldecc *lista;

	lista = (ldecc*) malloc(sizeof(ldecc));
	lista->cabeca = (no*) malloc(sizeof(no));
	lista->cabeca->prox = lista->cabeca->ant = NULL;

	return lista;
}

/*imprime uma lista duplamente encadeada, apenas para testes*/
/*void imprime_ldecc(ldecc *lista, int num_arquivos){
	no *p;
	int i=0;

	if(lista->cabeca->prox == NULL)
		printf("Lista vazia\n");

	for(p=lista->cabeca->prox; p != NULL; p = p->prox){
		printf("%s", p->chave);
		for(i=0; i<num_arquivos; i++){
			printf(" %d", p->ocorrencias[i]);
		}
		printf("\n");
	}
}*/

/*converte uma palavra de sua versão maiúscula para minúscula*/
char *converte_lw(char nova_chave[MAX]){
	int i=0;
	/*A cada verificação, compara-se o bit atual e o próximo, ou seja 2 bits, com uma string de 2 bits, por exemplo "Á", caso sejam iguais
	é feita troca entre os dois bits da nova_chave com sua versão minúscula, por exemplo "á".*/
	while(nova_chave[i] != '\0'){

		/*Por algum motivo, strcmp e strcpy geravam warning, imagino que seja porque
		não necessáriamente todas as cadeias terminam em /0, e como memcmp compara buffers de bytes binários de N bytes,
		memcmp e memcpy resolveram o problema*/
		if(memcmp(nova_chave+i, "Á", 2)==0){
			/*também gerava um warning na hora de passar quantos bits serão substituidos, a solução foi usar um sizeof*/
			memcpy(nova_chave+i, "á", sizeof("á"));
		}
		else if(memcmp(nova_chave+i, "É", 2)==0){
			memcpy(nova_chave+i, "é", sizeof("é"));
		}
		else if(memcmp(nova_chave+i, "Í", 2)==0){
			memcpy(nova_chave+i, "í", sizeof("í"));
		}
		else if(memcmp(nova_chave+i, "Ó", 2)==0){
			memcpy(nova_chave+i, "ó", sizeof("ó"));
		}
		else if(memcmp(nova_chave+i, "Ú", 2)==0){
			memcpy(nova_chave+i, "ú", sizeof("ú"));
		}

		else if(memcmp(nova_chave+i, "À", 2)==0){
			memcpy(nova_chave+i, "à", sizeof("à"));
		}
		else if(memcmp(nova_chave+i, "Â", 2)==0){
			memcpy(nova_chave+i, "â", sizeof("â"));
		}
		else if(memcmp(nova_chave+i, "Ê", 2)==0){
			memcpy(nova_chave+i, "ê", sizeof("ê"));
		}
		else if(memcmp(nova_chave+i, "Ô", 2)==0){
			memcpy(nova_chave+i, "ô", sizeof("ô"));
		}


		else if(memcmp(nova_chave+i, "Ã", 2)==0){
			memcpy(nova_chave+i, "ã", sizeof("ã"));
		}
		else if(memcmp(nova_chave+i, "Õ", 2)==0){
			memcpy(nova_chave+i, "õ", sizeof("õ"));
		}
		else if(memcmp(nova_chave+i, "Ç", 2)==0){
			memcpy(nova_chave+i, "ç", sizeof("ç"));
		}

		/*como palavras acentuadas não são afetadas pelo tolower, conversão de palavras não acentuadas, caractere a caractere*/
		nova_chave[i] = tolower(nova_chave[i]);
		i++;
	}
	/*retorna a nova_chave já convertida para sua versão lower*/
	return nova_chave;
}

void insere_ordenado_ldecc(ldecc *lista, char palavra[MAX], int num_arquivos, int arq_atual){
	no *novo;
	no *p, *q;

	/*aloca novo nó*/
	novo = (no*) malloc(sizeof(no));
	/*copia palavra para a chave do novo nó*/
	strcpy(novo->chave, palavra);
	/*aloca o vetor de ocorrencias de cada nó*/
	novo->ocorrencias = (int*) malloc(num_arquivos * sizeof(int));
	/*agora tenho que buscar um nó, ou inserir como é predefinido
	ou, incrementar caso já exista o nó*/

	/*p estará na cabeça e q, estará no primeiro nó*/
	/*enquanto a string do novo nó for maior que as demais, andarei na lista
	a condição de parada é quando achar um elemento maior ou igual ao novo*/
	for(p=lista->cabeca, q=p->prox; q!=NULL && strcmp(novo->chave, q->chave) > 0; p=q, q=q->prox)
		;

	/*caso o nó em que o q parou tenha a chave igual a que quer que seja inserida*/
	/*incrementa o num de ocorrencias na posição do vetor correspondente*/
	if(q!= NULL && strcmp(novo->chave, q->chave)  == 0){
		q->ocorrencias[arq_atual]++;
	}else{
		novo->prox = q;
		novo->ant = p;
		p->prox = novo;
		novo->ocorrencias[arq_atual]++;
		/*se a lista não estiver vazia, posso acessar o campo ant de q*/
		if(q!=NULL){
			q->ant=novo;
		}
	}
}


//função para verificar o tamanho do arquivo.
int get_size(char* file_name){
    FILE *file = fopen(file_name, "r");
	//se file == NULL, o arquivo nao foi encontrado.
    if(file == NULL)
        return 0;
	//fseek reposiciona o ponteiro para o fim do arquivo, verifica o deslocamento do ponteiro.
    fseek(file, 0, SEEK_END);
	//retorna a posição atual do ponteiro transformando em inteiro.    
	int size = ftell(file);
	//fecha o arquivo.    
	//retorna o tamanho do arquivo em inteiro.
    return size;
}
