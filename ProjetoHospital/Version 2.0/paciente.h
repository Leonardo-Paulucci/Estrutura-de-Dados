#ifndef PACIENTE_H
#define PACIENTE_H



// ESTRUTURA DO PACIENTE

typedef struct {
    char nome[50];
    int idade;
    int gravidade;  // 1 a 5
    int tipo;       // 1-Emergência, 2-Consulta, 3-Exame
} Paciente;



// ESTRUTURA DO NÓ (PONTEIROS)
typedef struct No {
    Paciente dados;
    struct No *prox;
} No;


// PILHA (EMERGÊNCIA)
void inicializarEmergencia();
void empilharEmergencia(Paciente p);
Paciente desempilharEmergencia();
void mostrarEmergencia();
int emergenciaVazia();

// FILA DE PRIORIDADE (CONSULTA)
void inicializarPrioridade();
void inserirPrioridade(Paciente p);
Paciente removerPrioridade();
void mostrarPrioridade();
int prioridadeVazia();


// FILA CIRCULAR (EXAMES)
void inicializarExames();
void adicionarExame(Paciente p);
Paciente removerExame();
void mostrarExames();

int examesVazia();
int examesCheia();

#endif