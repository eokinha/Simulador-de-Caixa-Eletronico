#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"

// ANSI para cores
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

Conta contas[MAX_CONTAS];
int totalContas = 0;

void limparTela() {
    system("clear || cls");
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void printCabecalho(const char *titulo) {
    limparTela();
    printf(CYAN "=============================\n" RESET);
    printf(CYAN "   %s\n" RESET, titulo);
    printf(CYAN "=============================\n" RESET);
}

int buscarConta(int numero) {
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero)
            return i;
    }
    return -1;
}

void criarConta() {
    printCabecalho("CRIAR NOVA CONTA");

    if (totalContas >= MAX_CONTAS) {
        printf(RED "Limite máximo de contas atingido.\n" RESET);
        pausar();
        return;
    }

    Conta nova;
    printf("Digite o número da conta (7 dígitos): ");
    scanf("%d", &nova.numero);

    if (buscarConta(nova.numero) != -1) {
        printf(RED "Essa conta já existe.\n" RESET);
        pausar();
        return;
    }

    printf("Crie sua senha (4 dígitos): ");
    scanf("%d", &nova.senha);

    printf("Digite seu nome: ");
    scanf(" %[^\n]", nova.nome);

    printf("Digite o saldo inicial: R$ ");
    scanf("%f", &nova.saldo);

    contas[totalContas++] = nova;
    printf(GREEN "Conta criada com sucesso!\n" RESET);
    pausar();
}

void acessarConta() {
    printCabecalho("ACESSAR CONTA");

    int numero, senha, index, tentativas = 0;
    printf("Digite o número da conta: ");
    scanf("%d", &numero);

    index = buscarConta(numero);
    if (index == -1) {
        printf(RED "Conta não encontrada.\n" RESET);
        pausar();
        return;
    }

    while (tentativas < 3) {
        printf("Digite a senha: ");
        scanf("%d", &senha);

        if (senha == contas[index].senha) {
            int opcao;
            float valor;
            do {
                printCabecalho("MENU DA CONTA");
                printf("Bem-vindo(a), %s!\n", contas[index].nome);
                printf("1. Ver saldo\n2. Depositar\n3. Sacar\n4. Transferir\n5. Sair\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                    printf("Saldo atual: R$ %.2f\n", contas[index].saldo);
                    break;
                case 2:
                    printf("Valor para depositar: R$ ");
                    scanf("%f", &valor);
                    if (valor > 0) {
                        contas[index].saldo += valor;
                        printf(GREEN "Depósito realizado.\n" RESET);
                    } else {
                        printf(RED "Valor inválido.\n" RESET);
                    }
                    break;
                case 3:
                    printf("Valor para sacar: R$ ");
                    scanf("%f", &valor);
                    if (valor > 0 && valor <= contas[index].saldo) {
                        contas[index].saldo -= valor;
                        printf(GREEN "Saque realizado.\n" RESET);
                    } else {
                        printf(RED "Saldo insuficiente ou valor inválido.\n" RESET);
                    }
                    break;
                case 4: {
                    int destino;
                    printf("Número da conta destino: ");
                    scanf("%d", &destino);
                    int idxDestino = buscarConta(destino);
                    if (idxDestino == -1 || idxDestino == index) {
                        printf(RED "Conta destino inválida.\n" RESET);
                        break;
                    }
                    printf("Valor da transferência: R$ ");
                    scanf("%f", &valor);
                    if (valor > 0 && valor <= contas[index].saldo) {
                        contas[index].saldo -= valor;
                        contas[idxDestino].saldo += valor;
                        printf(GREEN "Transferência realizada com sucesso!\n" RESET);
                    } else {
                        printf(RED "Saldo insuficiente ou valor inválido.\n" RESET);
                    }
                    break;
                }
                case 5:
                    printf("Saindo da conta...\n");
                    break;
                default:
                    printf(RED "Opção inválida.\n" RESET);
                }

                if (opcao != 5) pausar();

            } while (opcao != 5);
            return;
        } else {
            printf(RED "Senha incorreta.\n" RESET);
            tentativas++;
        }
    }

    if (tentativas == 3) {
        printf(RED "Número de tentativas excedido.\n" RESET);
        pausar();
    }
}
