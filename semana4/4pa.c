/*Esse programa recebe */
#include <stdio.h>
int main(){
	int i, n, k;
    printf("Digite a quantidade de termos: \n");
    scanf("%d", &n);

    for(i = 0, k = 0; i <= n; i++){
        k += i;
        printf("i = %d, soma = %d\n", i, k);
    }

	return 0;
}