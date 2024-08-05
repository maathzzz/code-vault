# ==============================
# Decimal to Binary
# ==============================

decimal = int(input("Digite um número em base decimal para convertê-lo em binário: "))

typed_number = decimal

quotient = decimal
binary_numbers = []

while quotient >= 1:
    # salvando o resto da operação
    remainder = decimal % 2

    # criando variável remainder_str --> transformando o remainder(number) em string
    remainder_str = str(remainder)

    # primeiro parâmetro define a posição em que o valor será inserido
    # segundo parâmetro define o valor a ser inserido
    binary_numbers.insert(0, remainder_str)

    # operador // divide os números e arredonda para baixo
    quotient = decimal // 2
    decimal = quotient

# juntando todos o items do array (concatenação de strings)
binary = ''.join(binary_numbers)

print('O número {0} em binário é {1}.'.format(typed_number, binary))
# print(binary)