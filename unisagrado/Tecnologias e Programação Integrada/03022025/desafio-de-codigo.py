# 3️⃣ Desafios de Código - Teste sua Lógica!

# Desafio 1
ano_nascimento = int(input("Digite seu ano de nascimento: "))
idade = 2023 - ano_nascimento  # Considerando o ano atual como 2023
print(f"Sua idade é: {idade} anos.")

# Desafio 2
nome = input("Digite seu nome: ")
quantidade_letras = len(nome)
print(f"O seu nome tem {quantidade_letras} letras.")

# Desafio 3
numero = int(input("Digite um número: "))
if numero % 2 == 0:
    print(f"O número {numero} é par.")
else:
    print(f"O número {numero} é ímpar.")

# Desafio 4
celsius = float(input("Digite a temperatura em Celsius: "))
fahrenheit = (celsius * 9/5) + 32
print(f"A temperatura em Fahrenheit é: {fahrenheit}°F")