#include <stdio.h>

int main() {

    int v[5];
    int i;
    int cont = 0;

    for(i = 0; i < 5; i++) {
        scanf("%d", &v[i]);

        if(v[i] % 2 == 0) {
            cont++;
        }
    }

    printf("%d", cont);

    return 0;
}