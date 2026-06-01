#include <stdio.h>
#include "fila.h"

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

void adicionarPacote(Fila *f, Pacote p) {
    f->itens[f->fim] = p;
    f->fim++;

    printf("Pacote %d adicionado na fila.\n", p.numero);
}

Pacote transmitirPacote(Fila *f) {

    Pacote vazio = {0,0,0};

    if (f->inicio == f->fim) {
        printf("Fila vazia.\n");
        return vazio;
    }

    Pacote p = f->itens[f->inicio];
    f->inicio++;

    printf("Transmitindo pacote %d\n", p.numero);

    return p;
}

void mostrarFila(Fila *f) {

    printf("\nFILA DE ESPERA:\n");

    for (int i = f->inicio; i < f->fim; i++) {
        printf("Pacote %d - %dKB\n",
               f->itens[i].numero,
               f->itens[i].tamanho);
    }
}