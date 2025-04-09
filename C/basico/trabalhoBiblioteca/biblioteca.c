#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

#ifdef _WIN32
    #define LIMPAR_TELA system("cls")
#else
    #define LIMPAR_TELA system("clear")
#endif

void mostrarCabecalho(const char *titulo) {
    LIMPAR_TELA;
    printf(ANSI_MAGENTA ANSI_NEGRITO "\n=== %s ===\n\n" ANSI_RESET, titulo);
}

void inicializarAcervoPadrao(Livro livros[], int *totalLivros) {
    Livro acervoInicial[ACERVO_PADRAO] = {
        {"George Orwell", "1984", 0, DISPONIVEL},
        {"J.R.R. Tolkien", "O Senhor dos Anéis", 0, DISPONIVEL},
        {"Machado de Assis", "Dom Casmurro", 0, DISPONIVEL},
        {"J.K. Rowling", "Harry Potter e a Pedra Filosofal", 0, DISPONIVEL},
        {"Isaac Asimov", "Fundação", 0, DISPONIVEL},
        {"Sun Tzu", "A Arte da Guerra", 0, DISPONIVEL},
        {"Antoine de Saint-Exupéry", "O Pequeno Príncipe", 0, DISPONIVEL},
        {"Fiódor Dostoiévski", "Crime e Castigo", 0, DISPONIVEL}
    };
    
    for(int i = 0; i < ACERVO_PADRAO; i++) {
        livros[i] = acervoInicial[i];
    }
    *totalLivros = ACERVO_PADRAO;
}

void cadastrarLivro(Livro livros[], int *totalLivros) {
    mostrarCabecalho("CADASTRO DE LIVRO");
    
    if (*totalLivros >= MAX_LIVROS) {
        printf("Limite de livros cadastrados atingido (%d)!\n", MAX_LIVROS);
        return;
    }

    Livro novoLivro;
    printf("Título do livro: ");
    scanf(" %[^\n]", novoLivro.titulo);
    printf("Autor: ");
    scanf(" %[^\n]", novoLivro.autor);
    
    novoLivro.total_emprestimos = 0;
    novoLivro.status = DISPONIVEL;

    livros[*totalLivros] = novoLivro;
    (*totalLivros)++;
    printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros(Livro livros[], int totalLivros) {
    mostrarCabecalho("ACERVO DE LIVROS");
    
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalLivros; i++) {
        printf("\nLivro %d:\n", i + 1);
        imprimirLivro(&livros[i]);
    }
}

void processarEmprestimo(Livro livros[], int totalLivros) {
    mostrarCabecalho("EMPRÉSTIMO DE LIVRO");
    
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado para empréstimo.\n");
        return;
    }
    
    listarLivros(livros, totalLivros);
    
    int escolha;
    printf("\nDigite o número do livro para emprestar: ");
    scanf("%d", &escolha);
    
    if (escolha > 0 && escolha <= totalLivros) {
        emprestarLivro(&livros[escolha - 1]);
    } else {
        printf("Número de livro inválido!\n");
    }
}

void processarDevolucao(Livro livros[], int totalLivros) {
    mostrarCabecalho("DEVOLUÇÃO DE LIVRO");
    
    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado para devolução.\n");
        return;
    }
    
    listarLivros(livros, totalLivros);
    
    int escolha;
    printf("\nDigite o número do livro para devolver: ");
    scanf("%d", &escolha);
    
    if (escolha > 0 && escolha <= totalLivros) {
        devolverLivro(&livros[escolha - 1]);
    } else {
        printf("Número de livro inválido!\n");
    }
}