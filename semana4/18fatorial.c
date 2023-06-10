/* Esse programa calcula o fatorial de um numero*/
#include <stdio.h>
int main(){
    
	int a; //entrada
    int resultado = 1; //saida do resultado
    int n; //variaveis de controle
    printf("Fatorial.\nDigite o numero para realizar a operacao: ");
    scanf("%d", &a);
    
    if (a > 0){

        for(n = a; n >= 1; n--){
            resultado *= n;
        }
        printf("O resultado e igual a: %d\n", resultado);
    } else{
        printf("Impossível calcular!\n");
    }

	return 0;
}