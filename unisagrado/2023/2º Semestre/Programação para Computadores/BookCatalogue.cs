using System;
using System.Collections.Generic;

class Program
{
    static List<Livro> lista_livros = new List<Livro>();

    class Livro
    {
        public string Nome { get; set; }
        public string Autor { get; set; }
        public string Genero { get; set; }
        public string Num_paginas { get; set; }
    }

    static void AdicionarLivro()
    {
        List<string> livro = new List<string>();

        Console.Write("Digite o nome do livro:");
        string nome_livro = Console.ReadLine();

        Console.Write("Digite o nome do autor:");
        string autor = Console.ReadLine();

        Console.Write("Digite gênero do livro:");
        string genero = Console.ReadLine();

        Console.Write("Digite o número de páginas do livro:");
        string num_paginas = Console.ReadLine();

        lista_livros.Add(new Livro { Nome = nome_livro, Autor = autor, Genero = genero, Num_paginas = num_paginas });
    }

    static void ListarLivros()
    {
        if (lista_livros.Count >= 1)
        {
            foreach (var livro in lista_livros)
            {
                Console.Write($"1 - Nome do livro: {livro.Nome} \n");
                Console.Write($"2 - Autor do livro: {livro.Autor} \n");
                Console.Write($"3 - Gênero do livro: {livro.Genero} \n");
                Console.Write($"4 - Número de páginas: {livro.Num_paginas} \n \n");
                Console.Write("=============================================== \n \n");
            }
        } else
        {
            Console.WriteLine("Nenhum livro cadastrado! \n");
        }
        
    }


    static void Main()
    {
        int opcao;

        do
        {
            Console.WriteLine("Menu (Escolha uma opção e aperte Enter para navegar)");
            Console.WriteLine("1 - Adicionar Livro:");
            Console.WriteLine("2 - Listar Livros:");
            Console.WriteLine("3 - Sair \n \n");

            opcao = Convert.ToInt32(Console.ReadLine());

            switch (opcao)
            {
                case 1:
                    AdicionarLivro();
                break;

                case 2:
                    ListarLivros();
                break;

                case 3:
                break;

                default:
                    Console.WriteLine("Opção inválida! Tente novamente");
                break;
            }
        } while (opcao != 3);
    }

}