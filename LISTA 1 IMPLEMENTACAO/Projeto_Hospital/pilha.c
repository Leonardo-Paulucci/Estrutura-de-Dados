#include "paciente.h"
#include <stdio.h>
#include <string.h>

#define MAX_EMERGENCIA 100

static Paciente pilha[MAX_EMERGENCIA];
static int topo = -1;

void inicializarEmergencia() {
    topo = -1;
}

int emergenciaVazia() {
    return topo == -1;
}

int emergenciaCheia() {
    return topo == MAX_EMERGENCIA - 1;
}

void empilharEmergencia(Paciente p) {
    if (emergenciaCheia()) {
        printf("ERRO: Emergencia lotada.\n");
        return;
    }
    topo++;
    pilha[topo] = p;
    printf("Paciente %s (Gravidade %d) encaminhado para EMERGENCIA\n", p.nome, p.gravidade);
}

Paciente desempilharEmergencia() {
    Paciente vazio = {"", 0, 0, 0};
    if (emergenciaVazia()) {
        printf("Emergencia vazia.\n");
        return vazio;
    }
    Paciente p = pilha[topo];
    topo--;
    return p;
}

void mostrarEmergencia() {
    if (emergenciaVazia()) {
        printf("EMERGENCIA: Vazia\n");
        return;
    }
    printf("\n EMERGENCIA (Pilha - ultimo a chegar e o primeiro):\n");
    printf("   Total: %d paciente(s)\n", topo + 1);
    printf("   Ordem de atendimento (do primeiro ao ultimo):\n");
    for (int i = topo; i >= 0; i--) {
        printf("      %d - %s | Idade: %d | Gravidade: %d\n", 
               topo - i + 1, pilha[i].nome, pilha[i].idade, pilha[i].gravidade);
    }
}