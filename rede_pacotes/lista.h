#ifndef LISTA_H
#define LISTA_H

typedef struct No {

    int id;
    char origem[50];
    char destino[50];
    char status[20];

    struct No *prox;

} No;

void inserirPacote(No **lista,
                   int id,
                   char origem[],
                   char destino[],
                   char status[]);

void listarPacotes(No *lista);

void removerPacote(No **lista, int id);

#endif