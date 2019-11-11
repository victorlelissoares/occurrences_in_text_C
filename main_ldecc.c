#include "listadecc.h"
//LEIA OS COMENTÁRIOS E APAGUE-OS
int main (int argc, char *argv[]) {
	/*esse atoi é pra converter o número de arquivos 
	que é passado por linha de comando para inteiro*/
	int num_arquivos = atoi(argv[1]);

	/*I controlará a abertura de arquivos e , j andará no vetor da linha de comando, 
	atribuindo o nome de cada aquivo para a função de abertura*/
	int i=0, j = 2;
	no *p;
	FILE *arquivos[argc-2];
	char palavra[MAX];
	FILE *saida;
	ldecc *lista;

	lista = cria_nova_ldecc();

	/*laço para abertura de arquivos através da linha de comando*/
	while(i < num_arquivos){
		if((arquivos[i] = fopen(argv[j], "r")) == NULL){
			printf("Entrada inválida!\n");
			return 0;
		}
		i++;
		j++;
	}
	//após isso, terá aberto todos os arquvos ou, terá encerrado


	for(i=0; i < num_arquivos; i++){
		while(!feof(arquivos[i])){
			fscanf(arquivos[i], "%29[A-Za-zÀ-ú]%*[^A-Za-zÀ-ú]", palavra);
			cnvr_lw(palavra);
			insere_ordenado_ldecc(lista, palavra, num_arquivos, i);
		}
	}

	saida = fopen("meuresultado.out", "w+");

	for(p=lista->cabeca->prox; p != NULL; p = p->prox){
		fprintf(saida,"%s", p->chave);
		for(i=0; i<num_arquivos; i++){
			fprintf(saida, " %d", p->ocorrencias[i]);
		}
		fprintf(saida, "\n");
	}

	return 0;
}
