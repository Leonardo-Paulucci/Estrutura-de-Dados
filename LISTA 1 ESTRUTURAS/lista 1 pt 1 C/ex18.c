#include <stdio.h>
int main(){

    int n,i;
    int soma=0;

    scanf("%d",&n);

    for(i=0;i<=n;i++){
        if(i%2==0)
            soma += i;
    }

    printf("%d", soma);

    return 0;
}