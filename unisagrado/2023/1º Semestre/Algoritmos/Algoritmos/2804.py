# criar duas listas vazias: uma para os nomes e outra para as notas
nomes = []
notas = []

# pedir ao usuário para digitar o nome e a nota de cada aluno e adicionar à lista correspondente
for i in range(3):
    nome = input("Digite o nome do aluno: ")
    nota = float(input("Digite a nota do aluno: "))
    nomes.append(nome)
    notas.append(nota)

# imprimir a lista de nomes e notas
print("Nomes:", nomes)
print("Notas:", notas)