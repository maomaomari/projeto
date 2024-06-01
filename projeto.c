/*****************************************
*  GABRIEL SKIBINSKI DE CARVALHO E SILVA *
*  GIOVANI MUNIZ ANDRIONI                *
*****************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct arvore{
	struct arvore *dir;
	struct arvore *esq;
	char nome[30];
} Arvore;

typedef struct no{
	struct no *prox;
	Arvore *lp;
	int Np;
	char id[8];
	char destino[4];
	char empresa[20];
	char modelo[20];
} No;

typedef struct fila{
	No *comeco;
	No *fim;
} Fila;

Fila *voos;
/* arranjos tecnicos */
int escreverArquivo();
/* programa */
Fila *add_voos(Fila *);
Arvore *add_nome(Arvore *);
Arvore *rem_nome(Arvore *);
void listar(Fila *);
Fila *aut_voo(Fila *);
void listar_voos(Fila *);
void listar_dados(Fila *);
void listar_passageiros(Fila*);
/* implementação filas */
Fila *add_fila(Fila *, No*);
Fila *rem_fila(Fila *);
int cont_fila(Fila *);
/* implementação arvores */
Arvore *add_arvore(Arvore *);
Arvore *rem_arvore(Arvore *);
void print_arvore(Arvore *);

/* TODO tudo.. */
int main(int argc, char** argv){


	escreverArquivo();
	return 0;
}
int escreverArquivo(){

	char *arquivo = "lista.txt";
	
	FILE *ARQUIVO = fopen(arquivo, "w");
	if(!ARQUIVO){
		printf("erro ao abrir o arquivo");
		return -1;
			}
	
	fclose(ARQUIVO);
	return 0;
}
Fila *add_voos(Fila* voos){
	
	No *aux = (No*) malloc(sizeof(No));
	
	if(voos == NULL){
		voos->comeco = aux;
		voos->fim = aux;
		voos->comeco->prox = aux;
		voos->fim->prox = aux;
		return voos;
	}
	
	voos->fim->prox = aux;
	aux->prox = voos->comeco;
	voos->fim = aux;

	return voos;
	
}
