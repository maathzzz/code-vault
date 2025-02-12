// Variáveis que o programa utiliza
int n, escolha = 0, cont = 0;

// Objeto Random para gerar números aleatórios de 1 até 10
Random segredo = new Random();

// Variável n recebe o objeto Random convertido em um inteiro de 32 bits
n = Convert.ToInt32(segredo.Next(1, 10));

// Bloco informativo para o usuário
Console.WriteLine("***Jogo de Advinhação");
Console.WriteLine("Advinhe o número que eu pensei! \n" + ("Dica o número está entre 1 e 10"));

/* Um bloc Try é usado por programadores para particionar o código
 * que pode ser afetado por uma exceção.
 * Os blocos catch associados são usados para tratar qualquer exceção resultante
 * Um bloco Finally contém código que será e79xecutado indepentente de uma exceção 
 * ser ou não lançada no bloco Try, como a liberação de recursos que estão alocados no bloco Try.
 * Um bloco Try exige um ou mais blocos catch associados
 * ou um bloco finally ou ambos.
 * */

try
{
    while (escolha != n)
    {
        /* Variável "escolha" recebe o valor digitado pelo usuário convertido 
         * em um inteiro de 32 bits */
        escolha = Convert.ToInt32(Console.ReadLine());
        // Se o usuário digitar um valor maior do que n...
        if (escolha > n)
            // O programa informa isso
            Console.WriteLine("Errado! o número é menor.");
        else if (escolha < n)
            // ...o programa informa isso
            Console.WriteLine("Errado. O número é maior.");
        else if (escolha == n && cont == 0)
            Console.WriteLine("Incrível! Você acertou na primeira!");
        else
            Console.WriteLine("Acertou! " + n + " é o número!");

        cont++;
    }
    Console.WriteLine("Número de tentativas: " + cont);
    Console.ReadKey();
}
catch
{
    Console.WriteLine("Sinto muito, você perdeu:\n" + "Não deixe em branco e digite apenas uma tecla!");

    // Deixa as informações na tela até o usuário pressionar alguma tecla 
    Console.ReadKey();
} 