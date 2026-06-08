#ifndef LISTA_H
#define LISTA_H

typedef struct {
int pid;
char nome[50];
char estado[30];
} ProcessoAtivo;

typedef struct NoLista {
ProcessoAtivo processo;
struct NoLista *prox;
} NoLista;

typedef struct {
NoLista *inicio;
} Lista;

void inicializarLista(Lista *l);

void adicionarAtivo(Lista *l,
int pid,
char nome[],
char estado[]);

void buscarProcesso(Lista *l, int pid);

void removerProcesso(Lista *l, int pid);

void listarProcessos(Lista *l);

#endif