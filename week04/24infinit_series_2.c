/* Esse programa calcula a serie infinita que converge para 2 */
#include <stdio.h>
#include <math.h>

int main(){
    
	int n; //entradas
    long double resultado, resultadoant = 0, resserie = 0; //saida do resultado
    int i, k; long unsigned q; //variavel de controle

    printf("Serie infinita que converge para 2.\nDigite a quantidade 'n' de operacoes: ");
    scanf("%d", &n);
    

        for(k = 0, i = 1; i <= n; i++, k ++){
            q = pow(2, k);
            //printf("q = %d --> ", q);
            resultado = 1 / (double)q;
            printf("1 / %lu = %.15Lf -----> ", q, resultado);
            //resultadoant = resultado - resultadoant;
            resserie += resultado;
            printf("%.30Lf\n", resserie);
        }       

	return 0;
}