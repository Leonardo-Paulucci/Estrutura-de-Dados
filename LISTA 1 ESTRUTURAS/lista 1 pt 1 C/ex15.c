#include <stdio.h>

int par(int n){
    if(n%2==0)
        return 1;
    else
        return 0;
}

int main(){

    int n;

    scanf("%d",&n);

    if(par(n))
        printf("Par");
    else
        printf("Impar");

    return 0;
}