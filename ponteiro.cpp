#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int valor = 110;
    int *ponteiro;
    
    ponteiro = &valor;
    
    printf("\n  Valor da variavel valor: %d", valor);
    printf("\n Endereço da variavel valor: %d", &valor);
    
    printf("\n Endereço da variavel ponteiro: %d", &ponteiro);
    printf("\n Valor da variavel ponteiro: %d", ponteiro);
}
