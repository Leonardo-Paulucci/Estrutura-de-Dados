#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicializarLista(Lista *l) {
l->inicio = NULL;
}

void adicionarAtivo(Lista *l,
int pid,
char nome[],
char estado[]) {

NoLista *novo = (NoLista*) malloc(sizeof(NoLista));

novo->processo.pid = pid;

strcpy(novo->processo.nome, nome);
strcpy(novo->processo.estado, estado);

novo->prox = l->inicio;
l->inicio = novo;

printf("Processo ativo adicionado.\n");

}

void buscarProcesso(Lista *l, int pid) {

NoLista *aux = l->inicio;

while (aux != NULL) {

    if (aux->processo.pid == pid) {

        printf("\nProcesso encontrado:\n");

        printf("PID: %d\n", aux->processo.pid);
        printf("Nome: %s\n", aux->processo.nome);
        printf("Estado: %s\n", aux->processo.estado);

        return;
    }

    aux = aux->prox;
}

printf("Processo nao encontrado.\n");

}

void removerProcesso(Lista *l, int pid) {

NoLista *aux = l->inicio;
NoLista *ant = NULL;

while (aux != NULL &&
       aux->processo.pid != pid) {

    ant = aux;
    aux = aux->prox;
}

if (aux == NULL) {
    printf("Processo nao encontrado.\n");
    return;
}

if (ant == NULL)
    l->inicio = aux->prox;
else
    ant->prox = aux->prox;

free(aux);

printf("Processo removido.\n");

}

void listarProcessos(Lista *l) {

NoLista *aux = l->inicio;

printf("\n--- Processos Ativos ---\n");

while (aux != NULL) {

    printf("PID: %d | Nome: %s | Estado: %s\n",
           aux->processo.pid,
           aux->processo.nome,
           aux->processo.estado);

    aux = aux->prox;
}

}