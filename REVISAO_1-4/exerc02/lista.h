#ifndef LISTA_H
#define LISTA_H

typedef struct {
int patrimonio;
char tipo[50];
char localizacao[50];
} Equipamento;

typedef struct NoLista {
Equipamento equipamento;
struct NoLista *prox;
} NoLista;

typedef struct {
NoLista *inicio;
} Lista;

void inicializarLista(Lista *l);
void adicionarEquipamento(Lista *l, int patrimonio,
char tipo[],
char localizacao[]);

void buscarEquipamento(Lista *l, int patrimonio);
void removerEquipamento(Lista *l, int patrimonio);
void listarEquipamentos(Lista *l);

#endif