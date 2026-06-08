#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileirar(Fila *f, char nome[], int idade) {
    NoFila *novo = (NoFila*) malloc(sizeof(NoFila));

    strcpy(novo->paciente.nome, nome);
    novo->paciente.idade = idade;
    novo->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("Paciente %s entrou na fila.\n", nome);
}

void chamarPaciente(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    NoFila *aux = f->inicio;

    printf("Chamando paciente: %s\n", aux->paciente.nome);

    f->inicio = f->inicio->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(aux);
}

void exibirFila(Fila *f) {
    NoFila *aux = f->inicio;

    printf("\n--- Fila de Espera ---\n");

    while (aux != NULL) {
        printf("Nome: %s | Idade: %d\n",
               aux->paciente.nome,
               aux->paciente.idade);

        aux = aux->prox;
    }
}