#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ponteiro para o início da fila
static No *inicio = NULL;



// INICIALIZAR FILA
void inicializarPrioridade() {
    inicio = NULL;
}


// VERIFICAR SE ESTÁ VAZIA
int prioridadeVazia() {
    return inicio == NULL;
}



// INSERIR COM PRIORIDADE
void inserirPrioridade(Paciente p) {

    // Cria novo nó dinamicamente
    No *novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        printf("ERRO: Falha na alocacao de memoria.\n");
        return;
    }

    // Guarda os dados do paciente
    novo->dados = p;
    novo->prox = NULL;

    // Caso 1: fila vazia
    if (prioridadeVazia()) {
        inicio = novo;
    }

    // Caso 2: maior prioridade que o primeiro
    else if (p.gravidade > inicio->dados.gravidade) {
        novo->prox = inicio;
        inicio = novo;
    }

    // Caso 3: inserir no meio/fim
    else {

        No *atual = inicio;

        while (
            atual->prox != NULL &&
            atual->prox->dados.gravidade >= p.gravidade
        ) {
            atual = atual->prox;
        }

        novo->prox = atual->prox;
        atual->prox = novo;
    }

    printf("Paciente %s adicionado na FILA DE PRIORIDADE\n", p.nome);
}


// REMOVER PACIENTE
Paciente removerPrioridade() {

    Paciente vazio = {"", 0, 0, 0};

    if (prioridadeVazia()) {
        printf("Fila de prioridade vazia.\n");
        return vazio;
    }

    // Guarda o primeiro nó
    No *temp = inicio;

    // Guarda os dados do paciente
    Paciente p = temp->dados;

    // Move o início para o próximo
    inicio = inicio->prox;

    // Libera memória
    free(temp);

    return p;
}



// MOSTRAR FILA
void mostrarPrioridade() {

    if (prioridadeVazia()) {
        printf("CONSULTAS: Vazia\n");
        return;
    }

    printf("\nCONSULTAS (Fila de Prioridade):\n");

    No *atual = inicio;
    int posicao = 1;

    while (atual != NULL) {

        printf("   %d - %s | Idade: %d | Gravidade: %d\n",
               posicao,
               atual->dados.nome,
               atual->dados.idade,
               atual->dados.gravidade);

        atual = atual->prox;
        posicao++;
    }
}