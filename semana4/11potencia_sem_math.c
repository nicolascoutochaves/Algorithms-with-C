/* Esse programa realiza a potenciacao de dois numeros sem usar a biblioteca math.h*/
#include <stdio.h>
int main(){
	float a, b; //entradas
    float resultado = 1; //saida do resultado
    int n, k; //variaveis de controle
    printf("Multiplicador.\nDigite os numeros para multiplica-los: ");
    scanf("%f %f", &a , &b);
    
    if(b > 0){
        k = b;
    for(n = 1; n <= k; n++){
        resultado *= a;
    }
    } else if(b < 0){
        k = -b;
        for(n = 1; n <= k; n++){
        resultado *= a;
    }
    resultado = k / resultado;
    } else{
        resultado = 1;
    }
    printf("O resultado e igual a: %.2f\n", resultado);

	return 0;
}