/* Esse programa mostra os termos e calcula o somatorio de uma PG*/
#include <stdio.h>
#include <math.h>

int main(){
    
	float a1, r, n; //entradas
    float somatorio, resultado; //saida do resultado
    float k; //variavel de controle
    printf("Calculo PG.\nDigite o termo inicial(a1), a razao(r) e a quantidade de termos(n): ");
    scanf("%f %f %f", &a1, &r, &n);
    

        for(k = 1; k <= n; k++){
            resultado = a1 * pow(r, k-1);
            printf("a%.0f = %f\n", k, resultado);
        }       
        somatorio = (a1 * (pow(r, n) - 1))/(r-1);
        printf("O somatorio dos termos e de: %.2f\n", somatorio);
    

	return 0;
}