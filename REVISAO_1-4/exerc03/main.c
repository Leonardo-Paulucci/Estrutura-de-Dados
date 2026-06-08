#include <stdio.h>
#include "fila.h"
#include "pilha.h"
#include "lista.h"

int main() {

    // FILA DE PRIORIDADE
    FilaPrioridade fila;
    inicializarFila(&fila);

    adicionarProcesso(&fila,
                      1,
                      "Navegador",
                      3);

    adicionarProcesso(&fila,
                      2,
                      "Editor",
                      2);

    adicionarProcesso(&fila,
                      3,
                      "Antivirus",
                      10);

    listarFila(&fila);

    executarProcesso(&fila);

    listarFila(&fila);

    // PILHA
    Pilha pilha;
    inicializarPilha(&pilha);

    registrarEncerramento(&pilha,
                           10,
                           "Finalizado pelo usuario");

    registrarEncerramento(&pilha,
                           20,
                           "Erro do sistema");

    mostrarHistorico(&pilha);

    desfazerEncerramento(&pilha);

    mostrarHistorico(&pilha);

    // LISTA
    Lista lista;
    inicializarLista(&lista);

    adicionarAtivo(&lista,
                    101,
                    "Chrome",
                    "Executando");

    adicionarAtivo(&lista,
                    102,
                    "VSCode",
                    "Suspenso");

    listarProcessos(&lista);

    buscarProcesso(&lista, 101);

    removerProcesso(&lista, 102);

    listarProcessos(&lista);

    return 0;
}