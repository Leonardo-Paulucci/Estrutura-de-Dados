#include <stdio.h>

int main() {

    int v[5];
    int i;
    int maior;

    for(i = 0; i < 5; i++) {
        scanf("%d", &v[i]);
    }

    maior = v[0];

    for(i = 1; i < 5; i++) {
        if(v[i] > maior) {
            maior = v[i];
        }
    }

    printf("%d", maior);

    return 0;
}