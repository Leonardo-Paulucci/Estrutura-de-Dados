#ifndef FILA_H
#define FILA_H

#define MAX 10

typedef struct {
    int numero;
    int tamanho;
    int tempo;
} Pacote;

typedef struct {
    Pacote itens[MAX];
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila *f);
void adicionarPacote(Fila *f, Pacote p);
Pacote transmitirPacote(Fila *f);
void mostrarFila(Fila *f);

#endif