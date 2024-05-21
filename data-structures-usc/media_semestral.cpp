#include <stdio.h>

struct Aluno 
{
	int id;
	float P1;
	float P2;
	float Q;
	float Ot;
};

int main() 
{	
	struct Aluno aluno;
	
	printf("Digite o seu ID da Unisagrado: ");
	scanf("%d", &aluno.id);
	
	printf("Digite a nota da P1: ");
	scanf("%f", &aluno.P1);
	
	printf("Digite a nota da P2: ");
	scanf("%f", &aluno.P2);
	
	printf("Digite a nota de Quiz: ");
	scanf("%f", &aluno.Q);
	
	printf("Digite a nota de Outros: ");
	scanf("%f", &aluno.Ot);
	
	float MF = (aluno.P1 * 0.3) + (aluno.P2 * 0.3) + (aluno.Q * 0.2) + (aluno.Ot * 0.2);
	
	printf("A nota final do ID %d ?: %2.f\n", aluno.id, MF);
	
	return 0;
}