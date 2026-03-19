#include <stdio.h>
int main() {

    int v[5];
    int i;
    float soma=0;

    for(i=0;i<5;i++){
        scanf("%d",&v[i]);
        soma += v[i];
    }

    printf("%.2f", soma/5);

    return 0;
}