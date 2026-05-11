#include "paciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar tela (funciona no Windows)
void limparTela() {
    system("cls");
}

// Função para pausar
void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

// Função para cadastrar novo paciente
Paciente cadastrarPaciente() {
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
    
    // REGRA DE NEGÓCIO: Gravidade 4 ou 5 vai direto para Emergência
    if (p.gravidade >= 4) {
        p.tipo = 1; // Emergência
        printf("\nPACIENTE COM GRAVIDADE %d - Encaminhado automaticamente para EMERGENCIA!\n", p.gravidade);
    } else {
        printf("\nTipo de Atendimento:\n");
        printf("1 - Emergencia (grave)\n");
        printf("2 - Consulta Agendada\n");
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

// Função para direcionar paciente para o setor correto
void direcionarPaciente(Paciente p) {
    switch(p.tipo) {
        case 1: // Emergência
            empilharEmergencia(p);
            break;
        case 2: // Consulta
            enfileirarConsulta(p);
            break;
        case 3: // Exame
            adicionarExame(p);
            break;
    }
}

int main() {
    int opcao;
    Paciente pacienteAtendido;
    
    // Inicializa os setores
    inicializarEmergencia();
    inicializarConsulta();
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
        getchar(); // Limpa o buffer
        
        switch(opcao) {
            case 1: // Cadastrar
                {
                    Paciente novo = cadastrarPaciente();
                    direcionarPaciente(novo);
                    pausar();
                }
                break;
                
            case 2: // Atender paciente
                limparTela();
                printf("\nATENDIMENTO POR SETOR\n");
                printf("1 - Atender Emergencia\n");
                printf("2 - Atender Consulta\n");
                printf("3 - Atender Exame\n");
                printf("Opcao: ");
                scanf("%d", &opcao);
                
                switch(opcao) {
                    case 1: // Atender Emergência
                        if (!emergenciaVazia()) {
                            pacienteAtendido = desempilharEmergencia();
                            printf("\nPACIENTE ATENDIDO NA EMERGENCIA:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);
                        } else {
                            printf("\nEmergencia vazia. Nenhum paciente para atender.\n");
                        }
                        break;
                        
                    case 2: // Atender Consulta
                        if (!consultaVazia()) {
                            pacienteAtendido = desenfileirarConsulta();
                            printf("\nPACIENTE ATENDIDO NA CONSULTA:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);
                        } else {
                            printf("\n Fila de consulta vazia. Nenhum paciente para atender.\n");
                        }
                        break;
                        
                    case 3: // Atender Exame
                        if (!examesVazia()) {
                            pacienteAtendido = removerExame();
                            printf("\n PACIENTE ATENDIDO NO EXAME:\n");
                            printf("   Nome: %s\n", pacienteAtendido.nome);
                            printf("   Idade: %d\n", pacienteAtendido.idade);
                            printf("   Gravidade: %d\n", pacienteAtendido.gravidade);
                        } else {
                            printf("\n Fila de exames vazia. Nenhum paciente para atender.\n");
                        }
                        break;
                        
                    default:
                        printf("\nOpcao invalida.\n");
                }
                pausar();
                break;
                
            case 3: // Mostrar pacientes
                limparTela();
                mostrarEmergencia();
                printf("\n");
                mostrarConsulta();
                printf("\n");
                mostrarExames();
                pausar();
                break;
                
            case 4: // Transferir paciente
                limparTela();
                printf("\nTRANSFERENCIA DE PACIENTE\n");
                printf("1 - Da Consulta para Emergencia (piorou)\n");
                printf("2 - Da Emergencia para Consulta (melhorou)\n");
                printf("3 - Da Consulta para Exame\n");
                printf("Opcao: ");
                scanf("%d", &opcao);
                getchar();
                
                Paciente transferido;
                
                switch(opcao) {
                    case 1: // Consulta -> Emergência
                        if (!consultaVazia()) {
                            printf(" ATENCAO: Isso removera o paciente da consulta!\n");
                            printf("Confirmar transferencia? (1-Sim/0-Nao): ");
                            int confirm;
                            scanf("%d", &confirm);
                            if (confirm == 1) {
                                transferido = desenfileirarConsulta();
                                transferido.tipo = 1; // Emergência
                                transferido.gravidade = 5; // Gravidade alta
                                empilharEmergencia(transferido);
                                printf("\n Paciente %s transferido da CONSULTA para EMERGENCIA\n", transferido.nome);
                            }
                        } else {
                            printf("\n Fila de consulta vazia!\n");
                        }
                        break;
                        
                    case 2: // Emergência -> Consulta
                        if (!emergenciaVazia()) {
                            printf(" ATENCAO: Isso removera o paciente da emergencia.\n");
                            printf("Confirmar transferencia? (1-Sim/0-Nao): ");
                            int confirm;
                            scanf("%d", &confirm);
                            if (confirm == 1) {
                                transferido = desempilharEmergencia();
                                transferido.tipo = 2; // Consulta
                                transferido.gravidade = 2; // Gravidade baixa
                                enfileirarConsulta(transferido);
                                printf("\n Paciente %s transferido da EMERGENCIA para CONSULTA\n", transferido.nome);
                            }
                        } else {
                            printf("\nEmergencia vazia.\n");
                        }
                        break;
                        
                    case 3: // Consulta -> Exame
                        if (!consultaVazia()) {
                            printf("Confirmar transferencia? (1-Sim/0-Nao): ");
                            int confirm;
                            scanf("%d", &confirm);
                            if (confirm == 1) {
                                transferido = desenfileirarConsulta();
                                transferido.tipo = 3; // Exame
                                adicionarExame(transferido);
                                printf("\n Paciente %s transferido da CONSULTA para EXAME\n", transferido.nome);
                            }
                        } else {
                            printf("\n Fila de consulta vazia.\n");
                        }
                        break;
                        
                    default:
                        printf("Opcao invalida.\n");
                }
                pausar();
                break;
                
            case 5: // Relatórios
                limparTela();
                printf("\nRELATORIOS DO HOSPITAL\n\n");
                printf(" ESTATISTICAS:\n");
                
                printf("Emergencia (Pilha - LIFO): ");
                if (emergenciaVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }
                
                printf("Consultas (Fila - FIFO): ");
                if (consultaVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }
                
                printf("Exames (Fila Circular - 8 vagas): ");
                if (examesVazia()) {
                    printf("0 pacientes\n");
                } else {
                    printf("Pacientes aguardando\n");
                }
                
                printf("\n REGRAS DO SISTEMA:\n");
                printf("- Gravidade 4 ou 5 → Emergência (automatico)\n");
                printf("- Emergencia funciona como PILHA (ultimo a chegar, primeiro atendido)\n");
                printf("- Consulta funciona como FILA (primeiro a chegar, primeiro atendido)\n");
                printf("- Exames: Fila Circular (capacidade 8, remove mais antigo se lotar)\n");
                
                pausar();
                break;
                
            case 0: // Sair
                printf("\nEncerrando o sistema...\n");
                break;
                
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                pausar();
        }
        
    } while(opcao != 0);
    
    return 0;
}