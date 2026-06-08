#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicializarLista(Lista *l) {
    l->inicio = NULL;
}

void cadastrarPaciente(Lista *l, char nome[], char cpf[], char telefone[]) {
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));

    strcpy(novo->paciente.nome, nome);
    strcpy(novo->paciente.cpf, cpf);
    strcpy(novo->paciente.telefone, telefone);

    novo->prox = l->inicio;
    l->inicio = novo;

    printf("Paciente cadastrado.\n");
}

void buscarPaciente(Lista *l, char nome[]) {
    NoLista *aux = l->inicio;

    while (aux != NULL) {
        if (strcmp(aux->paciente.nome, nome) == 0) {
            printf("\nPaciente encontrado:\n");
            printf("Nome: %s | CPF: %s | Telefone: %s\n",
                   aux->paciente.nome,
                   aux->paciente.cpf,
                   aux->paciente.telefone);
            return;
        }
        aux = aux->prox;
    }

    printf("Paciente nao encontrado.\n");
}

void removerPaciente(Lista *l, char nome[]) {
    NoLista *aux = l->inicio;
    NoLista *ant = NULL;

    while (aux != NULL && strcmp(aux->paciente.nome, nome) != 0) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Paciente nao encontrado.\n");
        return;
    }

    if (ant == NULL)
        l->inicio = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux);

    printf("Paciente removido.\n");
}

void listarPacientes(Lista *l) {
    NoLista *aux = l->inicio;

    printf("\n--- Lista de Pacientes ---\n");

    while (aux != NULL) {
        printf("Nome: %s | CPF: %s | Telefone: %s\n",
               aux->paciente.nome,
               aux->paciente.cpf,
               aux->paciente.telefone);

        aux = aux->prox;
    }
}