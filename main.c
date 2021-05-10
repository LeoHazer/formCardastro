#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "form.h"

#define TAM_CHAR 150

int main()
{

    Cadastro lista = criaLista();
    char nome[TAM_CHAR], email[TAM_CHAR], logadouro[TAM_CHAR], cidade[TAM_CHAR], bairro[TAM_CHAR], estado[TAM_CHAR];
    int CPF_CNPJ, telefone, numero, CEP, opcao=1;

    while(opcao =! 0)
    {
        printf("1 - Inserir cliente\n2 - Remover cliente\n3 - Listar Clientes\n0 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%i",&opcao);

        switch(opcao)
        {
        case 1:
            system("cls");
            printf("Digite o CPF ou CNPJ:\n");
            scanf("%d", &CPF_CNPJ);
            if(Busca(lista, CPF_CNPJ) == 1)
            {
                printf("Cadastro ja existente!\n");
                exit(1);
            }
            else
            {
                printf("\nNome: ");
                scanf("%s", nome);
                printf("\nE-mail: ");
                scanf("%s", email);
                printf("\nTelefone: ");
                scanf("%d", &telefone);
                printf("\nCEP: ");
                scanf("%d", &CEP);
                printf("\nLogadouro: ");
                scanf("%s", logadouro);
                printf("\nNumero: ");
                scanf("%d", &numero);
                printf("\nCidade: ");
                scanf("%s", cidade);
                printf("\nBairro: ");
                scanf("%s", bairro);
                printf("\nEstado: ");
                scanf("%s", estado);
                lista = insereFim(lista, nome, email, CPF_CNPJ, telefone, CEP, logadouro, numero, bairro, cidade, estado);

                printf("\n\nCliente inserido com sucesso!\n ");
                Listar(lista);
                system("pause");
                system("cls");
                break;

            }
        case 2:
            printf("Informe o CPF/CNPJ do cliente: \n");
            scanf("%d", &CPF_CNPJ);
            if(!(lista = Remove(lista, CPF_CNPJ)))
            {
                printf("Cliente removido com sucesso!\n");
            }
            else
            {
                printf("Erro ao excluir!\n");
                exit(2);
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            printf("\n\n\tClientes:\n");
            Listar(lista);
            system("pause");
            system("cls");
            break;

        case 0:
            opcao = 0;
            DestroiLista(lista);
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Digite um valor valido!\n");
            break;



        }
    }

    return 0;
}
