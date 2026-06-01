#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ==========================================
// ANALISE DE DESEMPENHO E ESTRESSE
// ==========================================

int main() {

    // Inicializa a fila de prioridade
    inicializarPrioridade();

    // Variáveis para medir tempo
    clock_t inicio, fim;

    // Quantidade de pacientes do teste
    int totalPacientes = 10000;

    printf("========================================\n");
    printf(" ANALISE DE DESEMPENHO E ESTRESSE\n");
    printf("========================================\n");

    printf("\nInserindo %d pacientes...\n", totalPacientes);

    // Início da contagem de tempo
    inicio = clock();

    // ==========================================
    // TESTE DE INSERCAO
    // ==========================================

    for(int i = 0; i < totalPacientes; i++) {

        Paciente p;

        // Nome automático
        sprintf(p.nome, "Paciente_%d", i);

        // Dados aleatórios
        p.idade = rand() % 100;

        // Gravidade entre 1 e 5
        p.gravidade = rand() % 5 + 1;

        // Consulta
        p.tipo = 2;

        // Inserção na fila de prioridade
        inserirPrioridade(p);
    }

    printf("Insercao concluida.\n");

    // ==========================================
    // TESTE DE REMOCAO
    // ==========================================

    printf("\nRemovendo pacientes...\n");

    while(!prioridadeVazia()) {
        removerPrioridade();
    }

    printf("Remocao concluida.\n");

    // Fim da contagem
    fim = clock();

    // Calcula tempo total
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // ==========================================
    // RESULTADOS
    // ==========================================

    printf("\n========================================\n");
    printf(" RESULTADOS DA ANALISE\n");
    printf("========================================\n");

    printf("Total de pacientes processados: %d\n", totalPacientes);

    printf("Tempo total gasto: %.4f segundos\n", tempo);

    printf("\nTeste finalizado com sucesso.\n");

    printf("\nOBSERVACOES:\n");
    printf("- Teste realizado com alocacao dinamica\n");
    printf("- Utilizacao de ponteiros e lista encadeada\n");
    printf("- Insercoes em fila de prioridade\n");
    printf("- Remocoes com liberacao de memoria\n");

    return 0;
}