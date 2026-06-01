#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar tela (funciona no Windows)
static void limparTela() {
    system("cls");
}

// Função para pausar
static void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// Função para cadastrar novo paciente
static Paciente cadastrarPaciente() {

    Paciente p;
    int opcao;

    printf("\n CADASTRO DE PACIENTE \n");

    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = 0;

    printf("Idade: ");
    scanf("%d", &p.idade);

    printf("Gravidade (1 a 5, sendo 5 mais grave): ");
    scanf("%d", &p.gravidade);

    // Valida gravidade
    while (p.gravidade < 1 || p.gravidade > 5) {
        printf("Gravidade invalida. Digite entre 1 e 5: ");
        scanf("%d", &p.gravidade);
    }

    // REGRA DE NEGÓCIO:
    // Gravidade 4 ou 5 vai direto para Emergência
    if (p.gravidade >= 4) {

        p.tipo = 1;

        printf("\nPACIENTE COM GRAVIDADE %d - Encaminhado automaticamente para EMERGENCIA!\n",
               p.gravidade);

    } else {

        printf("\nTipo de Atendimento:\n");
        printf("1 - Emergencia (grave)\n");
        printf("2 - Consulta\n");
        printf("3 - Exame/Laboratorio\n");
        printf("Opcao: ");

        scanf("%d", &opcao);

        while (opcao < 1 || opcao > 3) {
            printf("Opcao invalida. Digite 1, 2 ou 3: ");
            scanf("%d", &opcao);
        }

        p.tipo = opcao;
    }

    return p;
}


// Direciona paciente ao setor correto
static void direcionarPaciente(Paciente p) {

    switch(p.tipo) {

        case 1:
            empilharEmergencia(p);
            break;

        case 2:
            inserirPrioridade(p);
            break;

        case 3:
            adicionarExame(p);
            break;
    }
}


int main() {

    int opcao;
    Paciente pacienteAtendido;

    // Inicializa os setores
    inicializarEmergencia();
    inicializarPrioridade();
    inicializarExames();

    do {

        limparTela();

        printf("   HOSPITAL UNIVASSOURAS\n");
        printf("   GERENCIAMENTO DE PACIENTES\n");
        printf("========================================\n");
        printf("1 - Cadastrar novo paciente\n");
        printf("2 - Atender paciente\n");
        printf("3 - Mostrar pacientes em cada setor\n");
        printf("4 - Transferir paciente entre setores\n");
        printf("5 - Relatorios\n");
        printf("0 - Sair\n");
        printf("========================================\n");

        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {

           
            // CADASTRAR PACIENTE
            case 1: {

                Paciente novo = cadastrarPaciente();
                direcionarPaciente(novo);

                pausar();
                break;
            }

            
            // ATENDER PACIENTE 
            case 2:

                limparTela();

                printf("\nATENDIMENTO POR SETOR\n");
                printf("1 - Atender Emergencia\n");
                printf("2 - Atender Consulta\n");
                printf("3 - Atender Exame\n");
                printf("Opcao: ");

                scanf("%d", &opcao);

                switch(opcao) {

                    // Emergência
                    case 1:

                        if (!emergenciaVazia()) {

                            pacienteAtendido = desempilharEmergencia();

                            printf("\nPACIENTE ATENDIDO NA EMERGENCIA:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);

                        } else {

                            printf("\nEmergencia vazia.\n");
                        }

                        break;


                    // Consulta (Fila de Prioridade)
                    case 2:

                        if (!prioridadeVazia()) {

                            pacienteAtendido = removerPrioridade();

                            printf("\nPACIENTE ATENDIDO NA CONSULTA:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);

                        } else {

                            printf("\nFila de prioridade vazia.\n");
                        }

                        break;


                    // Exame
                    case 3:

                        if (!examesVazia()) {

                            pacienteAtendido = removerExame();

                            printf("\nPACIENTE ATENDIDO NO EXAME:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);

                        } else {

                            printf("\nFila de exames vazia.\n");
                        }

                        break;

                    default:
                        printf("\nOpcao invalida.\n");
                }

                pausar();
                break;


            
            // MOSTRAR PACIENTES
          
            case 3:

                limparTela();

                mostrarEmergencia();

                printf("\n");

                mostrarPrioridade();

                printf("\n");

                mostrarExames();

                pausar();

                break;


            
            // TRANSFERÊNCIAS
            
            case 4: {

                limparTela();

                printf("\nTRANSFERENCIA DE PACIENTE\n");
                printf("1 - Da Consulta para Emergencia\n");
                printf("2 - Da Emergencia para Consulta\n");
                printf("3 - Da Consulta para Exame\n");
                printf("Opcao: ");

                scanf("%d", &opcao);
                getchar();

                Paciente transferido;

                switch(opcao) {

                    // Consulta -> Emergência
                    case 1:

                        if (!prioridadeVazia()) {

                            int confirm;

                            printf("ATENCAO: removera o paciente da consulta.\n");
                            printf("Confirmar? (1-Sim / 0-Nao): ");

                            scanf("%d", &confirm);

                            if (confirm == 1) {

                                transferido = removerPrioridade();

                                transferido.tipo = 1;
                                transferido.gravidade = 5;

                                empilharEmergencia(transferido);

                                printf("\nPaciente %s transferido para EMERGENCIA\n",
                                       transferido.nome);
                            }

                        } else {

                            printf("\nFila de prioridade vazia.\n");
                        }

                        break;


                    // Emergência -> Consulta
                    case 2:

                        if (!emergenciaVazia()) {

                            int confirm;

                            printf("ATENCAO: removera o paciente da emergencia.\n");
                            printf("Confirmar? (1-Sim / 0-Nao): ");

                            scanf("%d", &confirm);

                            if (confirm == 1) {

                                transferido = desempilharEmergencia();

                                transferido.tipo = 2;
                                transferido.gravidade = 2;

                                inserirPrioridade(transferido);

                                printf("\nPaciente %s transferido para CONSULTA\n",
                                       transferido.nome);
                            }

                        } else {

                            printf("\nEmergencia vazia.\n");
                        }

                        break;


                    // Consulta -> Exame
                    case 3:

                        if (!prioridadeVazia()) {

                            int confirm;

                            printf("Confirmar? (1-Sim / 0-Nao): ");
                            scanf("%d", &confirm);

                            if (confirm == 1) {

                                transferido = removerPrioridade();

                                transferido.tipo = 3;

                                adicionarExame(transferido);

                                printf("\nPaciente %s transferido para EXAME\n",
                                       transferido.nome);
                            }

                        } else {

                            printf("\nFila de prioridade vazia.\n");
                        }

                        break;

                    default:
                        printf("\nOpcao invalida.\n");
                }

                pausar();
                break;
            }


            // RELATÓRIOS
            
            case 5:

                limparTela();

                printf("\nRELATORIOS DO HOSPITAL\n\n");

                printf("ESTATISTICAS:\n");

                // Emergência
                printf("Emergencia (Pilha): ");

                if (emergenciaVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }

                // Consulta
                printf("Consultas (Fila de Prioridade): ");

                if (prioridadeVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }

                // Exames
                printf("Exames (Fila Circular): ");

                if (examesVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }

                printf("\nREGRAS DO SISTEMA:\n");

                printf("- Gravidade 4 ou 5 -> Emergencia automatica\n");
                printf("- Emergencia funciona como PILHA\n");
                printf("- Consulta funciona como FILA DE PRIORIDADE\n");
                printf("- Maior gravidade possui prioridade\n");
                printf("- Exames usam FILA CIRCULAR\n");

                pausar();

                break;

            
            // SAIR
            
            case 0:

                printf("\nEncerrando sistema...\n");

                break;


            default:

                printf("\nOpcao invalida.\n");

                pausar();
        }

    } while(opcao != 0);

    return 0;
}