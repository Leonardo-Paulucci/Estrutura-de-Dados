#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"
#include "lista.h"

int main() {

    Fila fila;
    Pilha pilha;
    No *lista = NULL;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao;

    do {

        printf("\n========= MENU =========\n");

        printf("1 - Adicionar pacote na fila\n");
        printf("2 - Transmitir pacote\n");
        printf("3 - Mostrar fila\n");

        printf("4 - Mostrar pilha de erros\n");

        printf("5 - Retransmitir pacote com erro\n");

        printf("6 - Mostrar pacotes ativos\n");

        printf("7 - Entregar pacote\n");

        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);

        // =====================================
        // ADICIONAR PACOTE
        // =====================================

        if (opcao == 1) {

            Pacote p;

            printf("Numero: ");
            scanf("%d", &p.numero);

            printf("Tamanho KB: ");
            scanf("%d", &p.tamanho);

            printf("Tempo: ");
            scanf("%d", &p.tempo);

            adicionarPacote(&fila, p);
        }

        // =====================================
        // TRANSMITIR PACOTE
        // =====================================

        else if (opcao == 2) {

            Pacote p = transmitirPacote(&fila);

            if (p.numero != 0) {

                // adiciona na lista encadeada
                inserirPacote(
                    &lista,
                    p.numero,
                    "Origem_A",
                    "Destino_B",
                    "Em_Transito"
                );

                int erro;

                printf("O pacote apresentou erro? (1=Sim / 0=Nao): ");
                scanf("%d", &erro);

                // =================================
                // SE DEU ERRO
                // =================================

                if (erro == 1) {

                    registrarErro(&pilha, p);

                    removerPacote(&lista, p.numero);

                    printf("Pacote movido para pilha de erros.\n");
                }
            }
        }

        // =====================================
        // MOSTRAR FILA
        // =====================================

        else if (opcao == 3) {

            mostrarFila(&fila);
        }

        // =====================================
        // MOSTRAR PILHA
        // =====================================

        else if (opcao == 4) {

            mostrarPilha(&pilha);
        }

        // =====================================
        // RETRANSMITIR PACOTE
        // =====================================

        else if (opcao == 5) {

            Pacote p = retransmitirPacote(&pilha);

            if (p.numero != 0) {

                inserirPacote(
                    &lista,
                    p.numero,
                    "Origem_A",
                    "Destino_B",
                    "Em_Transito"
                );

                printf("Pacote retransmitido com sucesso.\n");
            }
        }

        // =====================================
        // MOSTRAR LISTA ENCADEADA
        // =====================================

        else if (opcao == 6) {

            listarPacotes(lista);
        }

        // =====================================
        // ENTREGAR PACOTE
        // =====================================

        else if (opcao == 7) {

            int id;

            printf("ID do pacote entregue: ");
            scanf("%d", &id);

            removerPacote(&lista, id);

            printf("Pacote entregue com sucesso.\n");
        }

    } while(opcao != 0);

    return 0;
}