#include <stdio.h>
int main() {

    int n,i;
    int fat = 1;

    scanf("%d",&n);

    for(i=1;i<=n;i++){
        fat = fat * i;
    }

    printf("%d", fat);

    return 0;
}