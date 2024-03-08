#include <iostream>
#include <stdlib.h>
#define max 5
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int arr[max];
int top = 0;
int op;

void list(void){
	printf("\n");
	for (int temp=top-1; temp >=0; temp--) {
		printf("Na posicao %d temos %d \n", temp, arr[temp]);
	}
	printf("\n");
	system("PAUSE");
}

void insert(void){
	if (top == max){
		printf("A pilha está cheia. \n\n");
	} 
	else {
		printf("Digite o valor para entrar na pilha: \n");
		scanf("%d", &arr[top]);
		top++;
	}
	list();
}

void remover(void){
	if (top == 0){
		printf("A pilha esta vazia. \n\n");
	} 
	else {
		printf("Retirado o valor %d da pilha \n", arr[top-1]);
		top--;
	}
	list();
}

int menu() {
	printf("-= Pilha em C =- \n\n");
	printf("Para inserir pressione 1 \n");
	printf("Para remover pressione 2 \n");
	printf("Para exibir digite 3 \n\n");
	printf("Para sair digite 4 \n");
	scanf("%d", &op);
	
	switch(op){
		case 1: insert();
			break;
		case 2: remover();
			break;
		case 3: list();
			break;
		case 4: 
			break;
		default: printf("Numero invalido. Tente Novamente");
			break;
			
	}
	
	return 0;
}

int main() {
	while (op != 4){
		system("cls"); 
		menu();
	}
	return 0;
}
