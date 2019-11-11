#include "listadecc.h"
//LEIA OS COMENTÁRIOS E APAGUE-OS
int main (int argc, char *argv[]) {
	/*esse atoi é pra converter o número de arquivos 
	que é passado por linha de comando para inteiro*/
	int num_arquivos = atoi(argv[1]);

	/*I controlará a abertura de arquivos e , j andará no vetor da linha de comando, 
	atribuindo o nome de cada aquivo para a função de abertura*/
	int i=0, j = 2;
	FILE *arquivos[argc-2];
	char palavra[MAX];

	ldecc *lista;

	lista = cria_nova_ldecc();

	/*laço para abertura de arquivos através da linha de comando*/
	while(i < num_arquivos){
		if((arquivos[i] = fopen(argv[j], "r")) == NULL){
			printf("Entrada inválida!\n");
			return 0;
		}
		else{
			printf("arquivo %d aberto com sucesso!\n", i);
		}
		i++;
		j++;
	}
	//após isso, terá aberto todos os arquvos ou, terá encerrado

	imprime_ldecc(lista, num_arquivos);

	for(i=0; i < num_arquivos; i++){
		while(!feof(arquivos[i])){
			fscanf(arquivos[i], "%29[A-Za-zÀ-ú]%*[^A-Za-zÀ-ú]", palavra);
			cnvr_lw(palavra);
			insere_ordenado_ldecc(lista, palavra, num_arquivos, i);
		}
	}

	imprime_ldecc(lista, num_arquivos);

	return 0;
}
