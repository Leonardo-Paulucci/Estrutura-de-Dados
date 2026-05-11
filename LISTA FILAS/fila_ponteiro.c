#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Estrutura da fila
typedef struct {
    No* frente;
    No* tras;
    int tamanho;
} Fila;

// Inicializar a fila
void inicializarFila(Fila* f) {
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila* f) {
    return f->frente == NULL;
}

// Enfileirar (enqueue)
void enfileirar(Fila* f, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return;
    }
    
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    
    if (estaVazia(f)) {
        // Se a fila está vazia, frente e tras apontam para o mesmo nó
        f->frente = novoNo;
        f->tras = novoNo;
    } else {
        // Adiciona no final e atualiza o tras
        f->tras->proximo = novoNo;
        f->tras = novoNo;
    }
    
    f->tamanho++;
    printf("Enfileirado: %d\n", valor);
}

// Desenfileirar (dequeue)
int desenfileirar(Fila* f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    No* temp = f->frente;
    int valor = temp->valor;
    
    f->frente = f->frente->proximo;
    
    // Se a fila ficou vazia, atualiza também o tras
    if (f->frente == NULL) {
        f->tras = NULL;
    }
    
    free(temp); // Libera a memória do nó removido
    f->tamanho--;
    
    return valor;
}

// Exibir a fila
void exibirFila(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: ");
    No* atual = f->frente;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// Liberar toda a fila da memória
void liberarFila(Fila* f) {
    while (!estaVazia(f)) {
        desenfileirar(f);
    }
}

int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);
    
    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    enfileirar(&minhaFila, 40);
    enfileirar(&minhaFila, 50);
    
    exibirFila(&minhaFila);

    printf("Desenfileirado: %d\n", desenfileirar(&minhaFila));
    printf("Desenfileirado: %d\n", desenfileirar(&minhaFila));
    
    exibirFila(&minhaFila);
    
    // Enfileirar sem limite fixo
    enfileirar(&minhaFila, 60);
    enfileirar(&minhaFila, 70);
    enfileirar(&minhaFila, 80);
    
    exibirFila(&minhaFila);
    
    // Libera memória antes de sair
    liberarFila(&minhaFila);

    return 0;
}