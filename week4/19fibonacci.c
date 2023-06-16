/* Esse programa calcula a serie de fibonacci pedindo um valor n ao usuario*/
#include <stdio.h>
int main(){
    
	int n; //entrada
    long long unsigned int resultado = 1, resultadoant = 0; long double phi; //saida do resultado
    int k; //variavel de controle
    printf("Sequencia de Fibonacci.\nDigite um valor para n: ");
    scanf("%d", &n);
    

        for(k = 0; k < n; k++){
            printf("k = %d resultado = %Lu\n", k, resultado);
            resultado = resultado + resultadoant;
            resultadoant = resultado - resultadoant;
        }
        printf("resultado = %Lu resultado anterior = %Lu\n", resultado, resultadoant);
        phi = (double)resultado / (double)resultadoant;
        printf("O valor calculado de phi é: %.30Lf\n", phi);
        
    

	return 0;
}