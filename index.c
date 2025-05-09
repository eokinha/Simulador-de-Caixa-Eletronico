// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     float conta = 0, saldo = 0;
//     int senha = 0, opcao;
//     char nomeUsuario[50] = "";

//     do
//     {
//         printf("\n==== MENU PRINCIPAL ====\n");
//         printf("1. Criar nova conta\n");
//         printf("2. Acessar conta existente\n");
//         printf("3. Sair\n");
//         printf("Escolha uma opção: ");
//         scanf("%d", &opcao);

//         switch (opcao)
//         {
//         case 1:
//         {
//             float novaConta;
//             int novaSenha;
//             char novoNome[50];

//             do
//             {
//                 printf("Digite o número da conta (7 dígitos): ");
//                 scanf("%f", &novaConta);
//             } while (novaConta < 1000000 || novaConta > 9999999);

//             if (novaConta == conta)
//             {
//                 printf("Essa conta já foi usada. Escolha outro número.\n");
//                 break;
//             }

//             do
//             {
//                 printf("Crie sua senha (4 dígitos): ");
//                 scanf("%d", &novaSenha);
//             } while (novaSenha < 1000 || novaSenha > 9999);

//             printf("Digite seu nome: ");
//             scanf("%s", novoNome);

//             printf("Digite o saldo inicial da conta: R$ ");
//             scanf("%f", &saldo);

//             conta = novaConta;
//             senha = novaSenha;
//             strcpy(nomeUsuario, novoNome);

//             printf("Conta criada com sucesso!\n");
//             break;
//         }

//         case 2:
//         {
//             if (conta == 0)
//             {
//                 printf("Nenhuma conta criada ainda.\n");
//                 break;
//             }

//             float tentativaConta;
//             int tentativaSenha, tentativas = 0;

//             printf("Digite o número da conta: ");
//             scanf("%f", &tentativaConta);

//             if (tentativaConta != conta)
//             {
//                 printf("Conta não encontrada.\n");
//                 break;
//             }

//             while (tentativas < 3)
//             {
//                 printf("Digite a senha: ");
//                 scanf("%d", &tentativaSenha);

//                 if (tentativaSenha == senha)
//                 {
//                     int operacao;
//                     float valor;

//                     do
//                     {
//                         printf("\n==== CAIXA ELETRÔNICO ====\n");
//                         printf("Conta: %.0f | Usuário: %s\n", conta, nomeUsuario);
//                         printf("1. Ver saldo\n2. Depositar\n3. Sacar\n4. Sair\n");
//                         printf("Escolha uma opção: ");
//                         scanf("%d", &operacao);

//                         switch (operacao)
//                         {
//                         case 1:
//                             printf("Saldo atual: R$ %.2f\n", saldo);
//                             break;
//                         case 2:
//                             printf("Valor para depositar: R$ ");
//                             scanf("%f", &valor);
//                             if (valor > 0)
//                             {
//                                 saldo += valor;
//                                 printf("Depósito realizado.\n");
//                             }
//                             else
//                             {
//                                 printf("Valor inválido.\n");
//                             }
//                             break;
//                         case 3:
//                             printf("Valor para sacar: R$ ");
//                             scanf("%f", &valor);
//                             if (valor > 0 && valor <= saldo)
//                             {
//                                 saldo -= valor;
//                                 printf("Saque realizado.\n");
//                             }
//                             else
//                             {
//                                 printf("Saldo insuficiente ou valor inválido.\n");
//                             }
//                             break;
//                         case 4:
//                             printf("Saindo da conta...\n");
//                             break;
//                         default:
//                             printf("Opção inválida.\n");
//                         }
//                     } while (operacao != 4);
//                     break;
//                 }
//                 else
//                 {
//                     printf("Senha incorreta.\n");
//                     tentativas++;
//                 }
//             }

//             if (tentativas == 3)
//             {
//                 printf("Número de tentativas excedido.\n");
//             }
//             break;
//         }

//         case 3:
//             printf("Encerrando programa. Até logo!\n");
//             break;

//         default:
//             printf("Opção inválida.\n");
//         }

//     } while (opcao != 3);

//     return 0;
// }