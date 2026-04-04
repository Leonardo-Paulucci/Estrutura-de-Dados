#include <stdio.h>
#include <stdlib.h>

// Estrutura da pilha
typedef struct {
    int *dados;
    int topo;
    int capacidade;
} Pilha;

// Criar pilha
Pilha* criarPilha(int capacidade) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->dados = (int*) malloc(capacidade * sizeof(int));
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

// Verificar se está cheia
int estaCheia(Pilha *p) {
    return p->topo == p->capacidade - 1;
}

// Verificar se está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Inserir elemento (push)
void push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia! Nao e possivel inserir %d\n", valor);
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

// Remover elemento (pop)
int pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Nada para remover.\n");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

// Imprimir pilha
void imprimir(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

// MAIN
int main() {
    int tamanho;

    printf("Informe o tamanho maximo da pilha: ");
    scanf("%d", &tamanho);

    Pilha *p = criarPilha(tamanho);

    printf("Informe %d elementos para a pilha:\n", tamanho - 1);

    // Inserindo n-1 elementos
    for (int i = 0; i < tamanho - 1; i++) {
        int valor;
        scanf("%d", &valor);
        push(p, valor);
    }

    // Mostrar estado inicial
    printf("\n--- Estado inicial ---\n");
    imprimir(p);

    printf("Pilha esta vazia? %s\n", estaVazia(p) ? "SIM" : "NAO");
    printf("Pilha esta cheia? %s\n", estaCheia(p) ? "SIM" : "NAO");

    // Inserir mais um elemento
    printf("\nInserindo elemento 999...\n");
    push(p, 999);

    printf("\n--- Apos insercao ---\n");
    imprimir(p);

    printf("Pilha esta cheia? %s\n", estaCheia(p) ? "SIM" : "NAO");

    // Remover elemento
    printf("\nRemovendo elemento...\n");
    int removido = pop(p);
    printf("Elemento removido: %d\n", removido);

    printf("\n--- Apos remocao ---\n");
    imprimir(p);

    printf("Pilha esta vazia? %s\n", estaVazia(p) ? "SIM" : "NAO");

    // Liberar memória
    free(p->dados);
    free(p);

    return 0;
}