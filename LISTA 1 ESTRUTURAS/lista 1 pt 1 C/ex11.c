#include <stdio.h>
int main() {

    int n, soma=0, i;

    for(i=0;i<5;i++){
        scanf("%d",&n);
        soma += n;
    }

    printf("%d", soma);

    return 0;
}