#ifndef FILA_H
#define FILA_H

typedef struct {
int ticket;
char descricao[100];
} Chamado;

typedef struct NoFila {
Chamado chamado;
struct NoFila *prox;
} NoFila;

typedef struct {
NoFila *inicio;
NoFila *fim;
} Fila;

void inicializarFila(Fila *f);
void abrirChamado(Fila *f, int ticket, char descricao[]);
void atenderChamado(Fila *f);
void listarChamados(Fila *f);

#endif