#include <stdio.h>
#include "fila.h"
#include "pilha.h"
#include "lista.h"

int main() {

    // FILA DE CHAMADOS
    Fila fila;
    inicializarFila(&fila);

    abrirChamado(&fila, 101, "Internet caiu");
    abrirChamado(&fila, 102, "Impressora nao funciona");
    abrirChamado(&fila, 103, "Computador nao liga");

    listarChamados(&fila);

    atenderChamado(&fila);

    listarChamados(&fila);

    // PILHA DE LOGS
    Pilha pilha;
    inicializarPilha(&pilha);

    registrarAcao(&pilha, "Reiniciou servidor");
    registrarAcao(&pilha, "Alterou IP");
    registrarAcao(&pilha, "Resetou switch");

    mostrarHistorico(&pilha);

    desfazerAcao(&pilha);

    mostrarHistorico(&pilha);

    // LISTA DE EQUIPAMENTOS
    Lista lista;
    inicializarLista(&lista);

    adicionarEquipamento(&lista,
                         1001,
                         "Computador",
                         "Sala 1");

    adicionarEquipamento(&lista,
                         1002,
                         "Switch",
                         "CPD");

    listarEquipamentos(&lista);

    buscarEquipamento(&lista, 1002);

    removerEquipamento(&lista, 1001);

    listarEquipamentos(&lista);

    return 0;
}