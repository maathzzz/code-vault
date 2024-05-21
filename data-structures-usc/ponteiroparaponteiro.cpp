#include <iostream>

int main() {
    int c, valor = 10;
    int *p;
    int **r;
    
    p = &valor;
    r = &p;
    c = **r + valor;
    
    printf("\n Resultado: %d", c);

}
