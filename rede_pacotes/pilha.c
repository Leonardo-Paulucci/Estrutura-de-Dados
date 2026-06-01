#include <stdio.h>
#include "pilha.h"

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

void registrarErro(Pilha *p, Pacote pacote) {

    p->topo++;
    p->itens[p->topo] = pacote;

    printf("Pacote %d registrado com erro.\n",
           pacote.numero);
}

Pacote retransmitirPacote(Pilha *p) {

    Pacote vazio = {0,0,0};

    if (p->topo == -1) {
        printf("Pilha vazia.\n");
        return vazio;
    }

    Pacote pacote = p->itens[p->topo];

    printf("Retransmitindo pacote %d\n",
           pacote.numero);

    p->topo--;

    return pacote;
}

void mostrarPilha(Pilha *p) {

    printf("\nPILHA DE ERROS:\n");

    for (int i = p->topo; i >= 0; i--) {

        printf("Pacote %d\n",
               p->itens[i].numero);
    }
}