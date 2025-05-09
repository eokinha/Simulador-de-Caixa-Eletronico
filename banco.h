#ifndef BANCO_H
#define BANCO_H

#define MAX_CONTAS 10

// CORES ANSI
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

typedef struct {
    int numero;
    int senha;
    float saldo;
    char nome[50];
} Conta;

extern Conta contas[MAX_CONTAS];
extern int totalContas;

int buscarConta(int numero);
void criarConta();
void acessarConta();
void limparTela();
void pausar();
void printCabecalho(const char *titulo);

#endif
