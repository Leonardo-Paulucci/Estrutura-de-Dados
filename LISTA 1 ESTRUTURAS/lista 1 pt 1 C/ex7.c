#include <stdio.h>
int main() {

    char nome[50];
    int idade;

    scanf("%s", nome);
    scanf("%d", &idade);

    printf("%s %d", nome, idade);

    return 0;
}