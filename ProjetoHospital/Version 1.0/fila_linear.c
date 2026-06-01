#include "paciente.h"
#include <stdio.h>
#include <string.h>

#define MAX_CONSULTA 50

static Paciente fila[MAX_CONSULTA];
static int frente = 0;
static int tras = -1;

void inicializarConsulta() {
    frente = 0;
    tras = -1;
}

int consultaVazia() {
    return frente > tras;
}

int consultaCheia() {
    return tras == MAX_CONSULTA - 1;
}

void enfileirarConsulta(Paciente p) {
    if (consultaCheia()) {
        printf("ERRO: Fila de consulta lotada.\n");
        return;
    }
    tras++;
    fila[tras] = p;
    printf("Paciente %s adicionado a fila de CONSULTAS\n", p.nome);
}

Paciente desenfileirarConsulta() {
    Paciente vazio = {"", 0, 0, 0};
    if (consultaVazia()) {
        printf("Fila de consulta vazia.\n");
        return vazio;
    }
    Paciente p = fila[frente];
    frente++;
    return p;
}

void mostrarConsulta() {
    if (consultaVazia()) {
        printf("CONSULTAS: Vazia\n");
        return;
    }
    printf("\nCONSULTAS (Fila - primeiro a chegar e o primeiro):\n");
    printf("   Total: %d paciente(s)\n", tras - frente + 1);
    printf("   Ordem de atendimento:\n");
    for (int i = frente; i <= tras; i++) {
        printf("      %d - %s | Idade: %d | Gravidade: %d\n", 
               i - frente + 1, fila[i].nome, fila[i].idade, fila[i].gravidade);
    }
}