Console.WriteLine("Calculadora de IMC (Índice de Massa Corporal) \n");

Console.WriteLine("Digite seu peso em kilogramas (kg) \n");
float peso = float.Parse(Console.ReadLine());

Console.WriteLine("Digite sua altura em metros (m) \n \n");
float altura = float.Parse(Console.ReadLine());

float imc = peso / (altura * altura);

Console.WriteLine($"Seu IMC é de {imc} \n");
if (imc < 18.5)
{
    Console.WriteLine("Abaixo do Peso! Você está Abaixo do peso considerado saudável para sua altura! \n");
} 
else if (imc < 24.9)
{
    Console.WriteLine("Peso Saudável! Esta faixa é considerada saudável e está associada a menor risco de problemas de saúde. \n");
}
else if (imc < 29.9)
{
    Console.WriteLine("Sobrepeso! Isso indica que a pessoa está com sobrepeso, o que pode aumentar o risco de certas condições de saúde. \n");
}
else if (imc < 34.9)
{
    Console.WriteLine("Obesidade (Classe I). Esta é uma categoria de obesidade leve. \n");
}
else if (imc < 39.9)
{
    Console.WriteLine("Obesidade (Classe II). Indica obesidade moderada. \n");
}
else if (imc > 40)
{
    Console.WriteLine("Obesidade (Classe III). Esta é uma categora de obesidade grave, também chamada de obesidade mórbida. \n");
}