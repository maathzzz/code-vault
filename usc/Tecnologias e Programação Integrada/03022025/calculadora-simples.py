# 5️⃣ Mini-Projeto: Construindo uma Calculadora Simples

def calculadora():
    print("Escolha a operação:")
    print("1 - Soma")
    print("2 - Subtração")
    print("3 - Multiplicação")
    print("4 - Divisão")
    
    operacao = input("Digite a opção desejada: ")
    
    num1 = float(input("Digite o primeiro número: "))
    num2 = float(input("Digite o segundo número: "))
    
    if operacao == '1':
        resultado = num1 + num2
        print(f"Resultado: {resultado}")
    elif operacao == '2':
        resultado = num1 - num2
        print(f"Resultado: {resultado}")
    elif operacao == '3':
        resultado = num1 * num2
        print(f"Resultado: {resultado}")
    elif operacao == '4':
        if num2 != 0:
            resultado = num1 / num2
            print(f"Resultado: {resultado}")
        else:
            print("Erro: Divisão por zero não é permitida.")
    else:
        print("Operação inválida.")

calculadora()