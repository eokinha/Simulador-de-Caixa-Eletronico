#include <stdio.h>
#include <string.h>
#include "conta.h"

// Função para criar uma nova conta
void criarConta(float contas[], int senhas[], char nomes[][50], float saldos[], int *total) {
    float conta, valor;
    int senha, i;
    char nome[50];

    // Solicita o número da conta
    printf(CYAN "Número da conta (7 dígitos): " RESET);
    scanf("%f", &conta);

    // Verifica se a conta já existe
    for (i = 0; i < *total && contas[i] != conta; i++);
    if (i < *total) {
        printf(RED "Conta já existe.\n" RESET);
        return;
    }

    // Solicita os dados do usuário
    printf(CYAN "Senha (4 dígitos): " RESET);
    scanf("%d", &senha);
    printf(CYAN "Nome: " RESET);
    scanf("%s", nome);
    printf(CYAN "Saldo inicial: R$ " RESET);
    scanf("%f", &valor);

    // Salva os dados no vetor de contas
    contas[*total] = conta;
    senhas[*total] = senha;
    strcpy(nomes[*total], nome);
    saldos[*total] = valor;

    (*total)++; // Incrementa o total de contas
    printf(GREEN "Conta criada com sucesso!\n" RESET);
}

// Função para acessar uma conta já existente
void acessarConta(float contas[], int senhas[], char nomes[][50], float saldos[], int total) {
    float conta, valor;
    int senha, i, j, opcao;

    // Solicita número da conta
    printf(CYAN "Número da conta: " RESET);
    scanf("%f", &conta);

    // Procura a conta pelo número
    for (i = 0; i < total && contas[i] != conta; i++);
    if (i == total) {
        printf(RED "Conta não encontrada.\n" RESET);
        return;
    }

    // Permite até 3 tentativas de senha
    for (j = 0; j < 3; j++) {
        printf(CYAN "Senha: " RESET);
        scanf("%d", &senha);
        if (senha == senhas[i]) break;
        printf(RED "Senha incorreta.\n" RESET);
    }
    if (j == 3) {
        printf(RED "Tentativas excedidas.\n" RESET);
        return;
    }

    // Menu de operações após o login bem-sucedido
    do {
        printf(YELLOW "\n==== MENU CONTA (%s) ====" RESET "\n", nomes[i]);
        printf("1. Saldo\n2. Depositar\n3. Sacar\n4. Transferir\n5. Sair\nOpção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf(GREEN "Saldo: R$ %.2f\n" RESET, saldos[i]);

        } else if (opcao == 2) {
            printf("Valor para depósito: R$ ");
            scanf("%f", &valor);
            if (valor > 0) {
                saldos[i] += valor;
                printf(GREEN "Depósito realizado.\n" RESET);
            } else {
                printf(RED "Valor inválido.\n" RESET);
            }

        } else if (opcao == 3) {
            printf("Valor para saque: R$ ");
            scanf("%f", &valor);
            if (valor > 0 && valor <= saldos[i]) {
                saldos[i] -= valor;
                printf(GREEN "Saque realizado.\n" RESET);
            } else {
                printf(RED "Saldo insuficiente ou valor inválido.\n" RESET);
            }

        } else if (opcao == 4) {
            printf("Conta destino: ");
            scanf("%f", &conta);
            for (j = 0; j < total && contas[j] != conta; j++);
            if (j == total) {
                printf(RED "Conta destino inválida.\n" RESET);
                continue;
            }
            printf("Valor para transferência: R$ ");
            scanf("%f", &valor);
            if (valor > 0 && valor <= saldos[i]) {
                saldos[i] -= valor;
                saldos[j] += valor;
                printf(GREEN "Transferência realizada.\n" RESET);
            } else {
                printf(RED "Saldo insuficiente ou valor inválido.\n" RESET);
            }

        } else if (opcao != 5) {
            printf(RED "Opção inválida.\n" RESET);
        }

    } while (opcao != 5);
}
