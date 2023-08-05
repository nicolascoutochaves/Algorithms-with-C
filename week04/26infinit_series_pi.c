/* Esse programa calcula a serie infinita que converge para pi */
#include <stdio.h>

int main(){
    
	int n; //entradas
    long double resultado, resserie = 0, pi; //saida do resultado
    int i, k, q; //variavel de controle

    printf("Serie infinita que converge para pi.\nDigite a quantidade 'n' de operacoes: ");
    scanf("%d", &n);
    
        for(k = 1, i = 1; i <= n; i++, k += 4){
            q = k;
            //printf("q = %d --> ", q);
            resultado = 1 / (long double)q;
            printf("1 / %d = %.15Lf -----> ", q, resultado);
            resserie += resultado;
            printf("%.30Lf\n", resserie);
        }
        for(k = 3, i = 1; i <= n; i++, k+=4){
            //printf("q = %d --> ", q);
            q = k;
            resultado = 1 / (long double)q;
            printf("1 / %d = %.15Lf -----> ", q, resultado);
            resserie += -resultado;
            printf("%.30Lf\n", resserie);
        }
        pi = resserie * 4;
        printf("Pi = %Lf\n", pi);

	return 0;
}