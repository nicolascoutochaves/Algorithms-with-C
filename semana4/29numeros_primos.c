/* Esse programa recebe um numero 'n' e mostra todos os numeros primos ate 'n'. */

#include <stdio.h>

int main(){
    int n;
    int i, k, j = 0; // variaveis de controle

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++){
        for(k = 1; k <= i; k++){
            if(i % k == 0){
                j += 1; //i e divisivel por k, j e incrementado
            }
        }
        if(j == 2) {
            printf("%d\n", i); //se j so foi incrementado 2 vezes durante a execucao, significa que o numero so foi dividido 2 vezes: por 1 e por ele mesmo, ou seja, o numero e primo.
        }
        j = 0;
    }


    return 0;
}