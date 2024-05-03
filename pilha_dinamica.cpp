#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


struct no {
	int valor;
	no *anterior;
};

int op;
int valordigitado;
no *topo;

void pilhavazia(){
	topo = NULL;
}

void empilha(int pvalor){
	no *novo;
	novo = (no*)malloc(sizeof(no));
	novo->valor=pvalor;
	novo->anterior=topo;
	topo=novo;
	printf("Elemento %d inserido com sucesso", novo);
	getch();
	system("cls");
}

void mostrar(){
	no *aux = topo;
	while(aux != NULL){
		printf("\n %d", aux->valor);
		aux=aux->anterior;
	}
	getch();
	system("cls");
}

void excluir(){
	no *aux = topo;
	while(aux != NULL){
		topo = aux->anterior;
		free(aux); 
		aux = topo;
	}
	printf("Pilha excluida com sucesso");
	getch();
	system("cls");
}

int menu() {
	printf("-= Pilha em C =- \n\n");
	printf("Digite '1' para adicionar um elemento na pilha \n");
	printf("Digite '2' para limpar a pilha \n");
	printf("Para '3' para mostrar os elementos da pilha \n\n");
	printf("Para sair digite 4 \n");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			printf("Digite o valor a ser inserido"); 
			scanf("%d", &valordigitado);
			empilha(valordigitado);
			break;
		case 2: excluir();
			break;
		case 3: mostrar();
			break;
		case 4: 
			break;
		default: printf("Numero invalido. Tente Novamente");
			break;	
	}
	
	return 0;
}
	
int main(int argc, char** argv) {
	while (op != 4){
		system("cls"); 
		menu();
	}
	return 0;
}
