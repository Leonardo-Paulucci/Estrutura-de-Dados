#include "paciente.h"
#include <stdio.h>
#include <string.h>

#define MAX_EXAMES 8

static Paciente exames[MAX_EXAMES];
static int frente = -1;
static int tras = -1;

void inicializarExames() {
    frente = -1;
    tras = -1;
}

int examesVazia() { 
    return frente == -1;
}

int examesCheia() {
    return (frente == (tras + 1) % MAX_EXAMES);
}

void adicionarExame(Paciente p) {
    if (examesCheia()) {
        // Remove o mais antigo automaticamente
        Paciente removido = removerExame();
        printf(" Fila de exames cheia. Paciente %s foi removido automaticamente\n", removido.nome);
    }
    
    if (examesVazia()) {
        frente = 0;
    }
    
    tras = (tras + 1) % MAX_EXAMES;
    exames[tras] = p;
    printf(" Paciente %s adicionado a fila de EXAMES\n", p.nome);
}

Paciente removerExame() {
    Paciente vazio = {"", 0, 0, 0};
    if (examesVazia()) {
        return vazio;
    }
    
    Paciente p = exames[frente];
    
    if (frente == tras) {
        frente = -1;
        tras = -1;
    } else {
        frente = (frente + 1) % MAX_EXAMES;
    }
    
    return p;
}

void mostrarExames() {
    if (examesVazia()) {
        printf("EXAMES: Vazia\n");
        return;
    }
    
    printf("\nEXAMES (Fila Circular - capacidade 8):\n");
    int count = 0;
    int i = frente;
    while (1) {
        count++;
        printf("      %d - %s | Idade: %d | Gravidade: %d\n", 
               count, exames[i].nome, exames[i].idade, exames[i].gravidade);
        if (i == tras) break;
        i = (i + 1) % MAX_EXAMES;
    }
    printf("Total: %d paciente(s)\n", count);
}