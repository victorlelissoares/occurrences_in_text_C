#include "listadecc.h"

int main (int argc, char *argv[]) {
	/*esse atoi é pra converter o número de arquivos 
	que é passado por linha de comando para inteiro*/
	int num_arquivos = atoi(argv[1]);

	/*I controlará a abertura de arquivos e , j andará no vetor da linha de comando, 
	atribuindo o nome de cada aquivo para a função de abertura*/
	int i=0, j = 2;
	no *p, *q;
	FILE *arquivos[num_arquivos];
	char nova_chave[MAX];
	FILE *saida;
	ldecc *lista;

	lista = cria_nova_ldecc();

	/*laço para abertura de arquivos através da linha de comando*/
	while(i < num_arquivos){
		/*caso na tentativa de abrir um arquivo returne null, quer dizer que não houve sucesso, 
		então o programa será encerrado sem processar nada*/
		if((arquivos[i] = fopen(argv[j], "r")) == NULL){
			printf("Entrada inválida!\n");
			return 0;
		}
		i++;
		j++;
	}
	/*após isso, terá aberto todos os arquvos ou terá encerrado*/

	j=2;
	for(i=0; i < num_arquivos; i++){
		/*caso o arquivo exista e nao contenha nada,getsize que retorna o tamanho do arquivo, retornará 0 e nem entrara no while. */
		if(get_size(argv[j++]) != 0){
			/*enquanto não chegar ao fim do arquivo, o percorrerá procurando cada string 
			e alocando de forma ordenada na ldecc*/
			while(!feof(arquivos[i])){
				fscanf(arquivos[i], "%29[A-Za-zÀ-ú]%*[^A-Za-zÀ-ú]", nova_chave);
				insere_ordenado_ldecc(lista, converte_lw(nova_chave), num_arquivos, i);			
			}	
		}
		/*após processar todas as strings de um arquivo, o mesmo será fechado*/
		fclose(arquivos[i]);
	}

	saida = fopen("resultado.out", "w+");

	for(p=lista->cabeca->prox; p != NULL; p = p->prox){
		fprintf(saida,"%s", p->chave);
		for(i=0; i<num_arquivos; i++){
			fprintf(saida, " %d", p->ocorrencias[i]);
		}
		fprintf(saida, "\n");
	}

	p=lista->cabeca->prox;
	while(p!=NULL){
		q = p->prox;
		free(p);
		p=q;
	}
	free(lista);

	return 0;
}
