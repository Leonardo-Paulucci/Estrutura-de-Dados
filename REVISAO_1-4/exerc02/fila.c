#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void inicializarFila(Fila *f) {
f->inicio = NULL;
f->fim = NULL;
}

void abrirChamado(Fila *f, int ticket, char descricao[]) {

NoFila *novo = (NoFila*) malloc(sizeof(NoFila));

novo->chamado.ticket = ticket;
strcpy(novo->chamado.descricao, descricao);

novo->prox = NULL;

if (f->fim == NULL) {
    f->inicio = novo;
    f->fim = novo;
} else {
    f->fim->prox = novo;
    f->fim = novo;
}

printf("Chamado %d aberto.\n", ticket);

}

void atenderChamado(Fila *f) {

if (f->inicio == NULL) {
    printf("Nenhum chamado pendente.\n");
    return;
}

NoFila *aux = f->inicio;

printf("Atendendo Ticket %d - %s\n",
       aux->chamado.ticket,
       aux->chamado.descricao);

f->inicio = f->inicio->prox;

if (f->inicio == NULL)
    f->fim = NULL;

free(aux);

}

void listarChamados(Fila *f) {

NoFila *aux = f->inicio;

printf("\n--- Chamados Pendentes ---\n");

while (aux != NULL) {

    printf("Ticket: %d | Problema: %s\n",
           aux->chamado.ticket,
           aux->chamado.descricao);

    aux = aux->prox;
}

}