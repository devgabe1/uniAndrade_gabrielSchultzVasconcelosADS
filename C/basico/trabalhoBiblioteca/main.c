#include <stdio.h>
#include "livro.h"

int main() {
    Livro livros[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // Inicializa com acervo padrão
    inicializarAcervoPadrao(livros, &totalLivros);

    do {
        mostrarCabecalho("SISTEMA DE EMPRÉSTIMOS");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Sair\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(livros, &totalLivros); break;
            case 2: listarLivros(livros, totalLivros); break;
            case 3: processarEmprestimo(livros, totalLivros); break;
            case 4: processarDevolucao(livros, totalLivros); break;
            case 5: mostrarCabecalho("Saindo do sistema..."); break;
            default: 
            mostrarCabecalho("Opção inválida");
            printf(ANSI_VERMELHO "Digite uma opção entre 1 e 5.\n" ANSI_RESET);
        }
        
        if(opcao != 5) {
            printf("\nPressione Enter para continuar...");
            while(getchar() != '\n');
            getchar();
        }
    } while (opcao != 5);

    return 0;
}