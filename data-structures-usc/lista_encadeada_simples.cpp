#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#define MAX 1000

int vet[MAX];

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;

/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
	return NULL;
}

/* função imprime: imprime valores dos elementos */
void imprime(Lista* l) {
    Lista* p; /* variável auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

Lista* busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL; /* não achou o elemento */
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia (Lista* l)
{
	if (l == NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

/* função retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/
	
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
	{
		return l; /* não achou: retorna lista original */
	}
	
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		l = p->prox;
	}
	else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	
	free(p);
	
	return l;
}

void libera (Lista* l)
{
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
}


void menu() {
	printf("-= Lista Encadeada em C =- \n\n");
	printf("1 - Inserir elemento \n");
	printf("2 - Remover elemento \n");
	printf("3 - Exibir elementos da lista \n");
	printf("4 - Limpar a lista \n");
	printf("5 - Sair \n");

	printf("\n\n");
}

main() {

	int opcao,valor;
	bool i=true;
	
	Lista* l; /* declara uma lista não inicializada */
	l = inicializa(); /* inicializa lista como vazia */
	
	menu();

	do {
		opcao = getche()-'0';

		switch(opcao) {
			case 1:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", &valor);
				l = insere(l, valor);
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 2:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser removido ");
				scanf("%d", &valor);
				l= retira(l, valor);
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 3:
				system ("cls");
				menu();
				imprime(l);
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 4:
				system ("cls");
				menu();
				libera(l);
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 5:
				system ("cls");
				i=false;
				break;
		}
	}
	while(i==true);

	system ("pause");
}
