/* Essa serie infinita computa sen(x) para um dado valor x em radianos e uma quantidade n de termos fornecido pelo usuario.
entradas: x (radianos), numero de termos(n)
saidas: valor aproximado de sen(x)
*/

#include <stdio.h>
#include <math.h>

int main(){
    double x; int n; //entradas
    double senx; //saida
    double denominador = 1; //variavel auxiliar
    int i, k; //variaveis de controle

    printf("Serie infinita sen(X).\nDigite um valor para x em radianos e o numero de iteracoes da serie: ");
    scanf("%lf %d", &x, &n);



    for(i = 0; i < n; i++){

        //calcula o fatorial do denominador:
        for(k = (2 * i + 1); k > 0; k--){
            denominador *= k;
        }
        
        senx += ((pow(-1, i)) / denominador) * pow(x, (2 * i + 1)); //realiza o calculo da serie.

        //printf("sen(x) = %lf\n", senx); //teste para verificar a qual valor sen(x) esta tendendo a cada iteracao.
    }

    printf("\nO sen(%.2lf) e, aproximadamente: %.10lf\n", x, senx);

    //printf("\nSen(%.2lf) (math.h): %lf\n", x, sin(x)); //teste do valor de sen(x) atraves da biblioteca <math.h>.

	return 0;
}