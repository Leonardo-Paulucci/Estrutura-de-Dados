#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    char nome[50];
    int idade;
    int gravidade;  // 1 a 5
    int tipo;       // 1-Emergência, 2-Consulta, 3-Exame
} Paciente;

// PILHA (Emergência)
void inicializarEmergencia();
void empilharEmergencia(Paciente p);
Paciente desempilharEmergencia();
void mostrarEmergencia();
int emergenciaVazia();
int emergenciaCheia();

// FILA LINEAR (Consulta)
void inicializarConsulta();
void enfileirarConsulta(Paciente p);
Paciente desenfileirarConsulta();
void mostrarConsulta();
int consultaVazia();
int consultaCheia();

// FILA CIRCULAR (Exame)
void inicializarExames();
void adicionarExame(Paciente p);
Paciente removerExame();
void mostrarExames();
int examesVazia();
int examesCheia();

#endif