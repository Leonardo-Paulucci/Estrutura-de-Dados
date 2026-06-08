#ifndef PILHA_H
#define PILHA_H

typedef struct {
char acao[100];
} Log;

typedef struct NoPilha {
Log log;
struct NoPilha *prox;
} NoPilha;

typedef struct {
NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *p);
void registrarAcao(Pilha *p, char acao[]);
void desfazerAcao(Pilha *p);
void mostrarHistorico(Pilha *p);

#endif