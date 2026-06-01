#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void inserirPacote(No **lista,
                   int id,
                   char origem[],
                   char destino[],
                   char status[]) {

    No *novo = malloc(sizeof(No));

    novo->id = id;

    strcpy(novo->origem, origem);
    strcpy(novo->destino, destino);
    strcpy(novo->status, status);

    novo->prox = *lista;
    *lista = novo;

    printf("Pacote %d inserido na rede.\n", id);
}

void listarPacotes(No *lista) {

    printf("\nPACOTES NA REDE:\n");

    while (lista != NULL) {

        printf("ID:%d | Origem:%s | Destino:%s | Status:%s\n",
               lista->id,
               lista->origem,
               lista->destino,
               lista->status);

        lista = lista->prox;
    }
}

void removerPacote(No **lista, int id) {

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->id != id) {

        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Pacote nao encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *lista = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);

    printf("Pacote %d removido.\n", id);
}