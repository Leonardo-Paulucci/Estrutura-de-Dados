#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
p->topo = NULL;
}

void registrarEncerramento(Pilha *p,
int pid,
char motivo[]) {

NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));

novo->processo.pid = pid;

strcpy(novo->processo.motivo, motivo);

novo->prox = p->topo;
p->topo = novo;

printf("Processo encerrado registrado.\n");

}

void desfazerEncerramento(Pilha *p) {

if (p->topo == NULL) {
    printf("Nenhum encerramento para desfazer.\n");
    return;
}

NoPilha *aux = p->topo;

printf("Desfazendo encerramento do PID %d\n",
       aux->processo.pid);

p->topo = p->topo->prox;

free(aux);

}

void mostrarHistorico(Pilha *p) {

NoPilha *aux = p->topo;

printf("\n--- Historico de Encerramentos ---\n");

while (aux != NULL) {

    printf("PID: %d | Motivo: %s\n",
           aux->processo.pid,
           aux->processo.motivo);

    aux = aux->prox;
}

}