#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "form.h"

#define TAM_CHAR 150

struct cad
{
    char nome[TAM_CHAR];
    char email[TAM_CHAR];
    int CPF_CNPJ;
    int telefone;
    int CEP;
    char logadouro[TAM_CHAR];
    int numero;
    char cidade[TAM_CHAR];
    char bairro[TAM_CHAR];
    char estado[TAM_CHAR];

    struct cad *prox;

};

Cadastro criaLista(void)
{
    return NULL;
}

Cadastro criaCad(char *nome, char *email, int cpf, int tel, int cep, char *log, int num, char *bairro, char *cid, char *estado)
{
    Cadastro lista = (Cadastro)malloc(sizeof(Cadastro));
    lista->CPF_CNPJ =cpf;
    strcpy(lista->nome, nome);
    strcpy(lista->email, email);
    strcpy(lista->logadouro, log);
    strcpy(lista->cidade, cid);
    strcpy(lista->bairro,bairro);
    strcpy(lista->estado,estado);
    lista->telefone = tel;
    lista->CEP = cep;
    lista->numero = num;

    lista->prox = NULL;

    return lista;
}

Cadastro insereFim(Cadastro lista, char *nome, char *email, int cpf, int tel, int cep, char *log, int num, char *bairro, char *cid, char *estado)
{
    Cadastro aux;
    Cadastro novo = criaCad(nome, email, cpf, tel, cep, log, num, bairro, cid, estado);

    if(lista == NULL)
    {
        lista = novo;
    }
    else
    {
        aux = lista;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return lista;


}

void Listar(Cadastro lista)
{
    Cadastro aux = lista;

    while(aux != NULL)
    {

            printf("Nome: %s", aux->nome);
            printf("\nEmail: %s", aux->email);
            printf("\nCPF/CNPJ: %i", aux->CPF_CNPJ);
            printf("\nTelefone: %i", aux->telefone);
            printf("\nCEP: %i", aux->CEP);
            printf("\nLogadouro: %s", aux->logadouro);
            printf("\nNumero: %i", aux->numero);
            printf("\nCidade: %s", aux->cidade);
            printf("\nBairro: %s", aux->bairro);
            printf("\nCidade: %s", aux->cidade);
            printf("\n\n");

            aux = aux->prox;
    }
}


Cadastro Remove(Cadastro lista, int cpf)
{

    if(lista == NULL) return NULL;

    Cadastro ant = lista;
    Cadastro aux = ant->prox;

    if(ant->CPF_CNPJ == cpf)
    {
        lista = aux;
        free(ant);
    }
    else
    {
        while(aux != NULL && aux->CPF_CNPJ != cpf)
        {
            ant = aux;
            aux = aux->prox;
        }
        if(aux != NULL)
        {
            ant->prox = aux->prox;
            free(aux);
        }
    }
    return lista;
}

int Busca(Cadastro lista, int cpf)
{

    if (lista == NULL)
    {
        return 0;
    }
    else
    {
        Cadastro aux = lista;
        while(aux != NULL && aux->CPF_CNPJ != cpf)
        {
            if (aux->prox == NULL)
            {
                return 0;
            }
            else
            {
                aux = aux->prox;
            }
        }
        if (aux->CPF_CNPJ == cpf)
        {

            return 1;
        }
        else
        {
            return 0;
        }
    }

}

Cadastro DestroiLista(Cadastro lista)
{

    Cadastro aux;

    while(lista != NULL)
    {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
    return NULL;
}
