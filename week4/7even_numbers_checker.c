/* Esse programa verifica quantos numeros inseridos pelo usuario sao pares e quantos sao impares */
#include <stdio.h>
int main(){
	int i, k, pares = 0, impares = 0;
    printf("Verificador de numeros\nDigite os numeros a serem verificados: \n");

    for(i = 0; i < 10; i++){
        scanf("%d", &k);
        if(k % 2 == 0){
            pares += 1;
            printf("%d e par\n", k);
        } else {
            impares += 1;
            printf("%d e impar\n", k);
        }
    }
    printf("Voce digitou %d pares e %d impares. \n", pares, impares);
	return 0;
}