/* Esse programa calcula a serie infinita que converge para ln2 */
#include <stdio.h>

int main(){
    
	int n; //entradas
    long double resultado, resultadoant = 0, resserie = 0; //saida do resultado
    int i, k, q; //variavel de controle

    printf("Serie infinita que converge para ln2.\nDigite a quantidade 'n' de operacoes: ");
    scanf("%d", &n);
    

        for(k = 1, i = 1; i <= n; i++, k ++){
            if (k % 2 == 0){
                q = -k;
            } else{
                q = k;
            }
            //printf("q = %d --> ", q);
            resultado = 1 / (double)q;
            printf("1 / %d = %.15Lf -----> ", q, resultado);
            resserie += resultado;
            printf("%.30Lf\n", resserie);
        }       

	return 0;
}