
/* 
 * File:   main.c
 * Author: paulo 
 *
 * Created on 21 de Junho de 2016, 18:56
 */
#include <stdio.h>
#include <stdlib.h>

struct Arvore {
    int num;
    struct Arvore *esq;
    struct Arvore *dir;
};

struct Arvore *inserir(struct Arvore *raiz, int num) {

    if (raiz == NULL) {

        raiz = malloc(sizeof(struct Arvore));

	raiz->num = num;
        raiz->esq = NULL;
	raiz->dir = NULL;
    }
    else if (num < raiz->num) {

	raiz->esq = inserir(raiz->esq,num);
    }
    else {
        raiz->dir = inserir(raiz->dir,num);
    }

    return raiz;
}

void imprimir(struct Arvore *raiz) {

    if (raiz != NULL) {

	imprimir(raiz->esq);
        printf("%d |",raiz->num);
	imprimir(raiz->dir);
    }

}
void consultar(struct Arvore *raiz, int num) {

    if (raiz != NULL)
    {
    	if (raiz->num == num) {

            printf("\n Achou o numero : %d ", raiz->num);
	}
	else if (num < raiz->num)
	{
            consultar(raiz->esq, num);
	}
	else if (num > raiz->num) {
 
            consultar(raiz->dir, num);
	}
    }
    else {

	   printf("\n Número não encontrado ");
    }
}
struct Arvore *deletar(struct Arvore *raiz) {

    if (raiz != NULL) {

	raiz->dir = deletar(raiz->dir);
	raiz->esq = deletar(raiz->esq);
        free(raiz);
       
    }
    return NULL;
}

int main()
{
    int menu = 0;
    struct Arvore *raiz = NULL;

    while (menu!=5)
    {
    	printf("\e[H\e[2J");
    	printf("**// Arvore Binária //** \n");
	printf("\n1 - Inserir");
	printf("\n2 - imprimir");
	printf("\n3 - Consultar numero");
	printf("\n4 - Deletar arvore");
	scanf("%i",&menu);

	if (menu == 1)
	{
            printf("\e[H\e[2J");
            for (int i = 0; i < 5; i++) {
		int x;
		printf("\n Digite o numero a ser inserido");
		scanf("%i",&x);
                
		raiz = inserir(raiz,x);

            }
            printf("\n Números inseridos com sucesso");
            getchar();
            getchar();
	}
        else if (menu == 2)
        {
            imprimir(raiz);
            
            getchar();
            getchar();
	}
	else if (menu == 3)
	{
            int x;
            printf("Informe o numero a ser consultado");
            scanf("%i",&x);
            consultar(raiz, x);
            getchar();
            getchar();
	}
	else if (menu == 4) {
            raiz = deletar(raiz);
            printf("Deletado con sucesso");
            getchar();
            getchar();
	}
    }
}