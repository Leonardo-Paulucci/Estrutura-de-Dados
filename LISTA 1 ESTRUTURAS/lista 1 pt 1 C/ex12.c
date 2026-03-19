#include <stdio.h>
int main() {

    int n, maior, i;

    scanf("%d",&maior);

    for(i=1;i<5;i++){
        scanf("%d",&n);
        if(n > maior)
            maior = n;
    }

    printf("%d", maior);

    return 0;
}