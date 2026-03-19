#include <stdio.h>
int main(){

    int m[2][2];
    int i,j;
    int soma=0;

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&m[i][j]);
            soma += m[i][j];
        }
    }

    printf("%d", soma);

    return 0;
}