#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(FilaPrioridade *f) {
f->inicio = NULL;
}

void adicionarProcesso(FilaPrioridade *f,
int pid,
char nome[],
int prioridade) {

NoFila *novo = (NoFila*) malloc(sizeof(NoFila));

novo->processo.pid = pid;

strcpy(novo->processo.nome, nome);

novo->processo.prioridade = prioridade;

novo->prox = NULL;

if (f->inicio == NULL ||
    prioridade > f->inicio->processo.prioridade) {

    novo->prox = f->inicio;
    f->inicio = novo;

} else {

    NoFila *aux = f->inicio;

    while (aux->prox != NULL &&
           aux->prox->processo.prioridade >= prioridade) {

        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
}

printf("Processo %s adicionado.\n", nome);

}

void executarProcesso(FilaPrioridade *f) {

if (f->inicio == NULL) {
    printf("Nenhum processo aguardando.\n");
    return;
}

NoFila *aux = f->inicio;

printf("Executando processo: %s | Prioridade: %d\n",
       aux->processo.nome,
       aux->processo.prioridade);

f->inicio = f->inicio->prox;

free(aux);

}

void listarFila(FilaPrioridade *f) {

NoFila *aux = f->inicio;

printf("\n--- Fila de Prioridade ---\n");

while (aux != NULL) {

    printf("PID: %d | Processo: %s | Prioridade: %d\n",
           aux->processo.pid,
           aux->processo.nome,
           aux->processo.prioridade);

    aux = aux->prox;
}

}