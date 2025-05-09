#include <stdio.h>
#include "conta.h"

int main() {
    // Declaração de variáveis principais
    float contas[MAX], saldos[MAX];
    int senhas[MAX], total = 0, opcao;
    char nomes[MAX][50];

    // Menu principal do programa
    do {
        printf(YELLOW "\n==== MENU PRINCIPAL ====" RESET "\n");
        printf("1. Criar conta\n2. Acessar conta\n3. Sair\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarConta(contas, senhas, nomes, saldos, &total);
                break;
            case 2:
                acessarConta(contas, senhas, nomes, saldos, total);
                break;
            case 3:
                printf(GREEN "Encerrando programa. Até logo!\n" RESET);
                break;
            default:
                printf(RED "Opção inválida.\n" RESET);
        }

    } while (opcao != 3);

    return 0;
}
