#include <stdio.h>

#define MAX_SIZE 5 

int fila[MAX_SIZE];  
int frente = 0;
int tras = -1;
int tamanho = 0; // Controla quantos elementos existem na fila

// Verifica se a fila está vazia
int estaVazia() {
    return tamanho == 0;
}

// Verifica se a fila está cheia
int estaCheia() {
    return tamanho == MAX_SIZE;
}

// Enfileirar (enqueue)
void enfileirar(int valor) {
    if (estaCheia()) {
        printf("Erro: Fila circular cheia!\n");
        return;
    }
    tras = (tras + 1) % MAX_SIZE; // Movimento circular
    fila[tras] = valor;
    tamanho++;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar (dequeue)
int desenfileirar() {
    if (estaVazia()) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = fila[frente];
    frente = (frente + 1) % MAX_SIZE; // Movimento circular
    tamanho--;
    return valor;
}

// Exibir a fila
void exibirFila() {
    if (estaVazia()) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    int i = frente;
    for (int count = 0; count < tamanho; count++) {
        printf("%d ", fila[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    enfileirar(40);
    enfileirar(50);
    
    exibirFila();

    printf("Desenfileirado: %d\n", desenfileirar());
    printf("Desenfileirado: %d\n", desenfileirar());
    
    exibirFila();
    

    enfileirar(60);
    enfileirar(70);
    
    exibirFila();

    return 0;
}