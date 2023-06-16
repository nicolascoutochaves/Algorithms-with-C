/* Esse programa imprime na tela um quadro nxn em formato de moldura */

#include <stdio.h>

int main(){

    int n;
    int i, j;

    printf("Digite um valor de n: ");
    scanf("%d", &n);

    for (i = 0; i < n*4; i++){ //cima

        printf("*");  
    }

    printf("\n");

    for(i = 0; i < n -2 ; i++){
        printf("*");

        for(j = 0; j < n*4-2; j++){ //meio
            printf(" ");
        }

        printf("*");
        printf("\n");
    }

    if(n >= 2){
        for (i = 0; i < n*4; i++){ //baixo

        printf("*");  
        }  
    }

    printf("\n");

    return 0;
}