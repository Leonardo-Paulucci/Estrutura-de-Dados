#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

void registrarAtendimento(Pilha *p, char nome[], char especialidade[]) {
    NoPilha *novo = (NoPilha*) malloc(sizeof(NoPilha));

    strcpy(novo->atendimento.nome, nome);
    strcpy(novo->atendimento.especialidade, especialidade);

    novo->prox = p->topo;
    p->topo = novo;

    printf("Atendimento registrado.\n");
}

void desfazerAtendimento(Pilha *p) {
    if (p->topo == NULL) {
        printf("Nenhum atendimento para desfazer.\n");
        return;
    }

    NoPilha *aux = p->topo;

    printf("Desfazendo atendimento de %s\n",
           aux->atendimento.nome);

    p->topo = p->topo->prox;

    free(aux);
}

void exibirHistorico(Pilha *p) {
    NoPilha *aux = p->topo;

    printf("\n--- Historico de Atendimentos ---\n");

    while (aux != NULL) {
        printf("Paciente: %s | Especialidade: %s\n",
               aux->atendimento.nome,
               aux->atendimento.especialidade);

        aux = aux->prox;
    }
}