#ifndef PILHA_H
#define PILHA_H

typedef struct {
    char nome[50];
    char especialidade[50];
} Atendimento;

typedef struct NoPilha {
    Atendimento atendimento;
    struct NoPilha *prox;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *p);
void registrarAtendimento(Pilha *p, char nome[], char especialidade[]);
void desfazerAtendimento(Pilha *p);
void exibirHistorico(Pilha *p);

#endif