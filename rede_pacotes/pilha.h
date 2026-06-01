#ifndef PILHA_H
#define PILHA_H

#include "fila.h"

#define MAX 10

typedef struct {
    Pacote itens[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
void registrarErro(Pilha *p, Pacote pacote);
Pacote retransmitirPacote(Pilha *p);
void mostrarPilha(Pilha *p);

#endif