#ifndef LISTA_H
#define LISTA_H

typedef struct {
    char nome[50];
    char cpf[20];
    char telefone[20];
} Cadastro;

typedef struct NoLista {
    Cadastro paciente;
    struct NoLista *prox;
} NoLista;

typedef struct {
    NoLista *inicio;
} Lista;

void inicializarLista(Lista *l);
void cadastrarPaciente(Lista *l, char nome[], char cpf[], char telefone[]);
void buscarPaciente(Lista *l, char nome[]);
void removerPaciente(Lista *l, char nome[]);
void listarPacientes(Lista *l);

#endif