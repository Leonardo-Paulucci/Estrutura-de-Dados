#include <stdio.h>
#include "fila.h"
#include "pilha.h"
#include "lista.h"

int main() {

    // Fila
    Fila f;
    inicializarFila(&f);

    enfileirar(&f, "Joao", 25);
    enfileirar(&f, "Maria", 40);
    enfileirar(&f, "Carlos", 31);
    enfileirar(&f, "Ana", 28);

    exibirFila(&f);

    chamarPaciente(&f);
    chamarPaciente(&f);

    exibirFila(&f);

    // Pilha
    Pilha p;
    inicializarPilha(&p);

    registrarAtendimento(&p, "Joao", "Cardiologia");
    registrarAtendimento(&p, "Maria", "Pediatria");

    exibirHistorico(&p);
    desfazerAtendimento(&p);

    exibirHistorico(&p);

    // Lista
    Lista l;
    inicializarLista(&l);

    cadastrarPaciente(&l, "Carlos", "12345678900", "22999999999");
    cadastrarPaciente(&l, "Ana", "98765432100", "22888888888");

    listarPacientes(&l);

    buscarPaciente(&l, "Ana");

    removerPaciente(&l, "Carlos");

    listarPacientes(&l);

    return 0;
}