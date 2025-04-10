// Cores ANSI
#define ANSI_RESET   "\x1b[0m"
#define ANSI_VERDE   "\x1b[32m"
#define ANSI_VERMELHO "\x1b[31m"
#define ANSI_AMARELO "\x1b[33m"
#define ANSI_AZUL    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CIANO   "\x1b[36m"
#define ANSI_NEGRITO "\x1b[1m"

#ifndef LIVRO_H
#define LIVRO_H

#define MAX_EMPRESTIMOS 3
#define TAMANHO_TEXTO 100
#define MAX_LIVROS 50
#define ACERVO_PADRAO 8

typedef enum {
    DISPONIVEL,
    EMPRESTADO
} StatusLivro;

typedef struct {
    char autor[TAMANHO_TEXTO];
    char titulo[TAMANHO_TEXTO];
    int total_emprestimos;
    StatusLivro status;
} Livro;

// Funções básicas de livro
void emprestarLivro(Livro *livro);
void devolverLivro(Livro *livro);
void imprimirLivro(const Livro *livro);

// Funções de interface
void listarLivros(Livro livros[], int totalLivros);
void processarEmprestimo(Livro livros[], int totalLivros);
void processarDevolucao(Livro livros[], int totalLivros);
void mostrarCabecalho(const char *titulo);
void cadastrarLivro(Livro livros[], int *totalLivros);
void inicializarAcervoPadrao(Livro livros[], int *totalLivros);

#endif