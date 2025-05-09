#ifndef CONTA_H
#define CONTA_H

#define MAX 10 // número máximo de contas permitidas

// Códigos ANSI para cores no terminal para melhorar o feedback visual
#define RED     "\033[1;31m"  // Vermelho para erros
#define GREEN   "\033[1;32m"  // Verde para sucesso
#define YELLOW  "\033[1;33m"  // Amarelo para avisos
#define CYAN    "\033[1;36m"  // Ciano para destaques
#define RESET   "\033[0m"     // Resetar cor padrão

// Protótipos das funções (declarações)
void criarConta(float contas[], int senhas[], char nomes[][50], float saldos[], int *total);
void acessarConta(float contas[], int senhas[], char nomes[][50], float saldos[], int total);

#endif
