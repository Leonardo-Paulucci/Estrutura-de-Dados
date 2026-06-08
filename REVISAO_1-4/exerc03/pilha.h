#ifndef PILHA_H
#define PILHA_H

typedef struct {
int pid;
char motivo[100];
} ProcessoEncerrado;

typedef struct NoPilha {
ProcessoEncerrado processo;
struct NoPilha *prox;
} NoPilha;

typedef struct {
NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *p);

void registrarEncerramento(Pilha *p,
int pid,
char motivo[]);

void desfazerEncerramento(Pilha *p);

void mostrarHistorico(Pilha *p);

#endif