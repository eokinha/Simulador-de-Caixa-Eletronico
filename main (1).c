
#include <stdio.h>
#include "banco.h"

int main() {
    int opcao;

    do {
        printCabecalho("MENU PRINCIPAL");
        printf("1. Criar nova conta\n");
        printf("2. Acessar conta existente\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            criarConta();
            break;
        case 2:
            acessarConta();
            break;
        case 3:
            printf("Encerrando programa. Até logo!\n");
            break;
        default:
            printf(RED "Opção inválida.\n" RESET);
            pausar();
        }

    } while (opcao != 3);

    return 0;
}
