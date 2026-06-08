#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
p->topo = NULL;
}

void registrarAcao(Pilha *p, char acao[]) {

NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));

strcpy(novo->log.acao, acao);

novo->prox = p->topo;
p->topo = novo;

printf("Acao registrada.\n");

}

void desfazerAcao(Pilha *p) {

if (p->topo == NULL) {
    printf("Nenhuma acao para desfazer.\n");
    return;
}

NoPilha *aux = p->topo;

printf("Desfazendo: %s\n",
       aux->log.acao);

p->topo = p->topo->prox;

free(aux);

}

void mostrarHistorico(Pilha *p) {

NoPilha *aux = p->topo;

printf("\n--- Historico de Logs ---\n");

while (aux != NULL) {

    printf("Acao: %s\n",
           aux->log.acao);

    aux = aux->prox;
}

}