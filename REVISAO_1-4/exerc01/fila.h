#ifndef FILA_H
#define FILA_H

typedef struct {
    char nome[50];
    int idade;
} Paciente;

typedef struct NoFila {
    Paciente paciente;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
} Fila;

void inicializarFila(Fila *f);
void enfileirar(Fila *f, char nome[], int idade);
void chamarPaciente(Fila *f);
void exibirFila(Fila *f);

#endif
