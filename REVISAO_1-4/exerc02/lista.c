#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicializarLista(Lista *l) {
l->inicio = NULL;
}

void adicionarEquipamento(Lista *l,
int patrimonio,
char tipo[],
char localizacao[]) {

NoLista *novo = (NoLista*) malloc(sizeof(NoLista));

novo->equipamento.patrimonio = patrimonio;

strcpy(novo->equipamento.tipo, tipo);
strcpy(novo->equipamento.localizacao, localizacao);

novo->prox = l->inicio;
l->inicio = novo;

printf("Equipamento adicionado.\n");

}

void buscarEquipamento(Lista *l, int patrimonio) {

NoLista *aux = l->inicio;

while (aux != NULL) {

    if (aux->equipamento.patrimonio == patrimonio) {

        printf("\nEquipamento encontrado:\n");

        printf("Patrimonio: %d\n",
               aux->equipamento.patrimonio);

        printf("Tipo: %s\n",
               aux->equipamento.tipo);

        printf("Localizacao: %s\n",
               aux->equipamento.localizacao);

        return;
    }

    aux = aux->prox;
}

printf("Equipamento nao encontrado.\n");

}

void removerEquipamento(Lista *l, int patrimonio) {

NoLista *aux = l->inicio;
NoLista *ant = NULL;

while (aux != NULL &&
       aux->equipamento.patrimonio != patrimonio) {

    ant = aux;
    aux = aux->prox;
}

if (aux == NULL) {
    printf("Equipamento nao encontrado.\n");
    return;
}

if (ant == NULL)
    l->inicio = aux->prox;
else
    ant->prox = aux->prox;

free(aux);

printf("Equipamento removido.\n");

}

void listarEquipamentos(Lista *l) {

NoLista *aux = l->inicio;

printf("\n--- Lista de Equipamentos ---\n");

while (aux != NULL) {

    printf("Patrimonio: %d | Tipo: %s | Localizacao: %s\n",
           aux->equipamento.patrimonio,
           aux->equipamento.tipo,
           aux->equipamento.localizacao);

    aux = aux->prox;
}

}