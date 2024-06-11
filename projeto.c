/*****************************************
*  GABRIEL SKIBINSKI DE CARVALHO E SILVA *
*  GIOVANI MUNIZ ANDRIONI                *
*****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arvore{
	struct arvore *dir;
	struct arvore *esq;
	char nome[30];
} Arvore;

typedef struct no{
	struct no *prox;
	Arvore *lp;
	int np;
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
/* HEADER*/
int escreverArquivo(); /* TODO */
/* programa */
Fila *add_voos(Fila *); /* OK +- */
Arvore *add_nome(Arvore *); /* TODO */
Arvore *rem_nome(Arvore *); /* TODO */
void listar(Fila *); /* OK lista 1o voo sem os passageiros. */
Fila *aut_voo(Fila *); /* OK */
void listar_voos(Fila *); /* OK */
void listar_dados(Fila *); /* TODO */
void listar_passageiros(Fila*); /* TODO */
/* implementação arvores */
Arvore *add_arvore(Arvore *, char*); /* TODO */
Arvore *rem_arvore(Arvore *, char*); /* TODO */
void print_arvore(Arvore *); /* TODO */

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

	char *id;
	char *destino;
	char *empresa;
	char *modelo;
	
	printf("Entre com a empresa: ");
	scanf("%20s", empresa);
	printf("\nEntre com o modelo: ");
	scanf("%20s", modelo);
	printf("\nEntre com o ID: ");
	scanf("%8s", id);
	printf("\nEntre com o destino: ");
	scanf("%4s", destino);
		
	strcpy(aux->destino, destino);
	strcpy(aux->modelo, modelo);
	strcpy(aux->id, id);
	strcpy(aux->empresa, empresa);
	aux->np = -1;
	aux->lp = (Arvore*) NULL;
	
	/*TODO adicionar passageiros e lista. */
	
	if(voos == NULL){
		voos->comeco = aux;
		voos->fim = aux;
		voos->comeco->prox = aux;
		voos->fim->prox = aux;
		return voos;
	}
	
	voos->fim->prox = aux;
	aux->prox = (No*) NULL;
	voos->fim = aux;

	return voos;
	
}
Fila *aut_voo(Fila *voos){
	No *aux = (No*) malloc(sizeof(No));
	aux = voos->comeco;
	printf("Autorizando voo %s %s %s %s\n",aux->modelo, aux->id, aux->empresa, aux->destino );
	voos->comeco = aux->prox;
	free(aux);
	
	return voos;
}
void lista(Fila *voos){
	printf("Seguem as informações do 1o voo\n\tModelo: %s\n\tEmpresa: %s\n\tID: %s\n\tDestino: %s, No. de passageiros: %d\n", voos->comeco->modelo, voos->comeco->empresa, voos->comeco->destino, voos->comeco->id, voos->comeco->np);
}

void listar_voos(Fila *voos){
	No *aux = (No*) malloc(sizeof(Fila));

	aux = voos->comeco;
	int i;
	for(i = 0; aux != NULL; i++){
		aux = aux->prox;
	}
	printf("Há %d voos na fila\n", i);
}

/* ARVORES VSFFFFF */

Arvore *add_arvore(Arvore *arvore, char *nome){
	
	return arvore;
}
