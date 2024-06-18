/*****************************************
*  GABRIEL SKIBINSKI DE CARVALHO E SILVA *
*  GIOVANI MUNIZ ANDRIONI                *
*****************************************/

/*
  ANOTAÇÕES
  * testar MAX ao invez de maximo dps, maximo pode dar zika na stack.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX(X,Y) \\
	(X > Y) ? X : Y

typedef struct arvore{
	struct arvore *dir;
	struct arvore *esq;
	int altura;
	char *nome;
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
Fila *add_voos(Fila *); /* OK */
void listar(Fila *); /* OK lista 1o voo sem os passageiros. */
Fila *aut_voo(Fila *); /* OK */
void listar_voos(Fila *); /* OK */
void listar_dados(Fila *); /* TODO FORMATAÇÃO */
void listar_passageiros(Fila*); /* OK */
/* implementação arvores */
Arvore *criar_arvore(void); /* OK */
int fator_balanceamento(Arvore *); /* OK */
int altura_no(Arvore *); /* OK */
int maior(int, int);     /* OK, substituir por MAX dps */
int insere_arvore(Arvore *, char*); /* OK */
int rem_arvore(Arvore *, char *); /* TODO +- */
Arvore *procura_menor(Arvore*); /* TODO +- */
void print_arvore(Arvore *);    /* OK */
int total_arvore(Arvore *); /* OK */
void rotacaoLL(Arvore *); /* OK */
void rotacaoRR(Arvore *); /* OK */
void rotacaoRL(Arvore *); /* OK */
void rotacaoLR(Arvore *); /* OK */


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
	char *nome;

	
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

	printf("Adicione os passageiros: (0 para sair)");
	do{
		scanf("%30s", nome);
		insere_arvore(aux->lp, nome);
		printf("\nnome adicionado!\n");
	}while (nome[0] != '0');

	aux->np = total_arvore(aux->lp);
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

Arvore *criar_arvore(){

	Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
	arvore = (Arvore*) NULL;
	
	return arvore;
}


int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int altura_no(Arvore *arvore) { return arvore ? arvore->altura : -1; }

int fator_balanceamento(Arvore *arvore){ return labs(altura_no(arvore->esq) - altura_no(arvore->dir)); }

void rotacaoLL(Arvore *arvore){
    Arvore *B;
    B = arvore->esq;
    arvore->esq = B->dir;
    B->dir = arvore;
    arvore->altura = maior(altura_no(arvore->esq), altura_no(arvore->dir)) + 1;
    B->altura = maior(altura_no(B->esq), arvore->altura) + 1;
    arvore = B;
}
void rotacaoRR(Arvore *arvore){
    Arvore *B;
    B = arvore->dir;
    arvore->esq = B->esq;
    B->esq = arvore;
    arvore->altura = maior(altura_no(arvore->esq), altura_no(arvore->dir)) + 1;
    B->altura = maior(altura_no(B->dir), arvore->altura) + 1;
    arvore = B;
}
void rotacaoLR(Arvore *arvore){
    rotacaoRR(arvore->esq);
    rotacaoLL(arvore);
}

void rotacaoRL(Arvore *arvore){
    rotacaoLL(arvore->dir);
    rotacaoRR(arvore);
}

/* TODO reimplementar pra aceitar char* e andar pela string quando a 1a letra for repetida */
int insere_arvore(Arvore *arvore, char* dado){
    int res;
    if(arvore == NULL){
        Arvore *novo;
        novo = (Arvore*) malloc(sizeof(Arvore));
        if(novo == NULL)
            return 0;

        novo->nome = dado;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        arvore = novo;
        return 1;
    }
    Arvore *atual = arvore;
    if(dado < atual->nome){
        if((res = insere_arvore(atual->esq, dado)) == 1){
            if(fator_balanceamento(atual) >= 2){
                if(dado < arvore->esq->nome){
                    rotacaoLL(arvore);
                }else{
                    rotacaoLR(arvore);
                }
            }
        }
    }else{
        if(dado > atual->nome){
            if((res = insere_arvore(atual->dir, dado)) == 1){
                if(fator_balanceamento(atual) >= 2){
                    if(arvore->dir->nome < dado){
                        rotacaoRR(arvore);
                    }else{
                        rotacaoRL(arvore);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }
    atual->altura = maior(altura_no(atual->esq),altura_no(atual->dir)) + 1;
    return res;
}

int rem_arvore(Arvore *raiz, char* valor){
	if(raiz == NULL){
	    printf("Valor n�o encontrado!\n");
	    return 0;
	}
    int res;
	if(valor < raiz->nome){
	    if((res = rem_arvore(raiz->esq,valor)) == 1){
            if(fator_balanceamento(raiz) >= 2){
                if(altura_no(raiz->dir->esq) <= altura_no(raiz->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
	    }
	}
	if(raiz->nome < valor){
	    if((res = rem_arvore(raiz->dir, valor)) == 1){
            if(fator_balanceamento(raiz) >= 2){
                if(altura_no(raiz->esq->dir) <= altura_no(raiz->esq->esq) )
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
	    }
	}
	if(raiz->nome == valor){
	    if((raiz->esq == NULL || raiz->dir == NULL)){
			Arvore *oldNode = raiz;
			if(raiz->esq != NULL){
                raiz = raiz->esq;
			} else{
                raiz = raiz->dir;
			}
			free(oldNode);
		} else {
			Arvore* temp = procura_menor(raiz->dir);
			raiz->nome = temp->nome;
			rem_arvore(raiz->dir, raiz->nome);
            if(fator_balanceamento(raiz) >= 2){
				if(altura_no(raiz->esq->dir) <= altura_no(raiz->esq->esq))
					rotacaoLL(raiz);
				else
					rotacaoLR(raiz);
			}
		}
		if (raiz != NULL)
            raiz->altura = maior(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
		return 1;
	}
	raiz->altura = maior(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
	return res;
}

Arvore* procura_menor(Arvore* atual){
    Arvore *no1 = atual;
    Arvore *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_arvore(Arvore *raiz, char *dado){ 
	if(raiz == NULL){
	    printf("Valor n�o encontrado!\n");
	    return 0;
	}
    int res;
	if(dado < raiz->nome){
	    if((res = remove_arvore(raiz->esq,dado)) == 1){
            if(fator_balanceamento(raiz) >= 2){
                if(altura_no(raiz->dir->esq) <= altura_no(raiz->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
	    }
	}
	if(raiz->nome < dado){
	    if((res = remove_arvore(raiz->dir, dado)) == 1){
            if(fator_balanceamento(raiz) >= 2){
                if(altura_no(raiz->esq->dir) <= altura_no(raiz->esq->esq) )
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
	    }
	}
	if(raiz->nome == dado){
	    if((raiz->esq == NULL || raiz->dir == NULL)){
			Arvore *oldNode = raiz;
			if(raiz->esq != NULL){
                raiz = raiz->esq;
			} else {
                raiz = raiz->dir;
			}
			free(oldNode);
		} else {
			Arvore* temp = procura_menor(raiz->dir);
			raiz->nome = temp->nome;
			remove_arvore(raiz->dir, raiz->nome);
            if(fator_balanceamento(raiz) >= 2){
				if(altura_no(raiz->esq->dir) <= altura_no(raiz->esq->esq))
					rotacaoLL(raiz);
				else
					rotacaoLR(raiz);
			}
		}
		if (raiz != NULL)
            raiz->altura = maior(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
		return 1;
	}
	raiz->altura = maior(altura_no(raiz->esq),altura_no(raiz->dir)) + 1;
	return res;
}
int total_arvore(Arvore *raiz){
    if (raiz == NULL)
        return 0;
    int alt_esq = total_arvore(raiz->esq);
    int alt_dir = total_arvore(raiz->dir);
    return(alt_esq + alt_dir + 1);
}
void listar_dados(Fila *voos) {
	No *aux = (No*) malloc(sizeof(No));
	aux = voos->comeco;
	printf("ID do voo | Destino | Empresa | Modelo | No.passageiros");
	do{
		printf("%s\t%s\t%s\t%s\t%d", aux->id, aux->destino, aux->empresa, aux->modelo, aux->np );
		aux = aux->prox;
	}while(aux != NULL);
	
}

void print_arvore(Arvore *arvore){
	
	if (!arvore)
		return;
	print_arvore(arvore->esq);
	printf("%s ", arvore->nome);
	print_arvore(arvore->dir);
}


void listar_passageros(Fila* voos){
	No *aux = (No*) malloc(sizeof(No));
	int q = 1;
	aux = voos->comeco;
	do{
		printf("%d: %s %s",q, aux->empresa, aux->id );
		q++;
		aux = aux->prox;
	} while(aux != NULL);
	aux = voos->comeco;
	
	printf("Escolha o voo:");
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
		aux = aux->prox;
	printf("\n");
	print_arvore(aux->lp);
}
