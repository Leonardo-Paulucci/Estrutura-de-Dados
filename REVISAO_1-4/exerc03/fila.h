#ifndef FILA_H
#define FILA_H

typedef struct {
int pid;
char nome[50];
int prioridade;
} ProcessoFila;

typedef struct NoFila {
ProcessoFila processo;
struct NoFila *prox;
} NoFila;

typedef struct {
NoFila *inicio;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *f);

void adicionarProcesso(FilaPrioridade *f,
int pid,
char nome[],
int prioridade);

void executarProcesso(FilaPrioridade *f);

void listarFila(FilaPrioridade *f);

#endif