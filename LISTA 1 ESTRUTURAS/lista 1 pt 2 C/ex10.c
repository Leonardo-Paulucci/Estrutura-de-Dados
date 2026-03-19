#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {

    struct Pessoa p;

    scanf("%s", p.nome);
    scanf("%d", &p.idade);

    printf("%s\n", p.nome);
    printf("%d\n", p.idade);

    return 0;
}
