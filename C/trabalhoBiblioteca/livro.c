#include <stdio.h>
#include "livro.h"

void emprestarLivro(Livro *livro) {
    if (livro->status == DISPONIVEL) {
        if (livro->total_emprestimos < MAX_EMPRESTIMOS) {
            livro->status = EMPRESTADO;
            livro->total_emprestimos++;
            printf(ANSI_VERDE "Livro emprestado com sucesso!\n" ANSI_RESET);
        } else {
            printf(ANSI_VERMELHO "Não foi possível emprestar o livro.\n" ANSI_RESET);
            printf(ANSI_AMARELO "Motivo: Limite de empréstimos (%d) atingido.\n" ANSI_RESET, MAX_EMPRESTIMOS);
        }
    } else {
        printf(ANSI_VERMELHO "Não foi possível emprestar o livro.\n" ANSI_RESET);
        printf(ANSI_AMARELO "Motivo: Livro não está disponível.\n" ANSI_RESET);
    }
}

void devolverLivro(Livro *livro) {
    if (livro->status == EMPRESTADO) {
        livro->status = DISPONIVEL;
        printf(ANSI_VERDE "Livro devolvido com sucesso!\n" ANSI_RESET);
    } else {
        printf(ANSI_AMARELO "Não é possível devolver. Livro já está disponível.\n" ANSI_RESET);
    }
}


void imprimirLivro(const Livro *livro) {
    printf(ANSI_NEGRITO "Título: " ANSI_RESET ANSI_AZUL "%s\n" ANSI_RESET, livro->titulo);
    printf(ANSI_NEGRITO "Autor: " ANSI_RESET ANSI_CIANO "%s\n" ANSI_RESET, livro->autor);
    
    if(livro->status == DISPONIVEL) {
        printf(ANSI_NEGRITO "Status: " ANSI_RESET ANSI_VERDE "Disponível\n" ANSI_RESET);
    } else {
        printf(ANSI_NEGRITO "Status: " ANSI_RESET ANSI_VERMELHO "Emprestado\n" ANSI_RESET);
    }
    
    printf(ANSI_NEGRITO "Total de empréstimos: " ANSI_RESET ANSI_AMARELO "%d/%d\n" ANSI_RESET, 
           livro->total_emprestimos, MAX_EMPRESTIMOS);
    printf("--------------------\n");
}