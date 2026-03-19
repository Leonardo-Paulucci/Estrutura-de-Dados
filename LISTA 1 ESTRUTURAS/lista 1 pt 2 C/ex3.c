#include <stdio.h>

int main() {

    int v[5];
    int i;
    int soma = 0;

    for(i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
        soma += v[i];
    }

    printf("%d", soma);

    return 0;
}