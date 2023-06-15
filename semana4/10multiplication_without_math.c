/* Esse programa multiplica dois numeros sem usar a biblioteca math.h ou '*' */
#include <stdio.h>
int main(){
	int a, b; //entradas
    int resultado = 0; //saida do resultado
    int n, k; //variaveis de controle
    printf("Multiplicador.\nDigite os numeros para multiplica-los: ");
    scanf("%d %d", &a , &b);
    
    if(b >= 0){
        k = b;
    for(n = 1; n <= k; n++){
        resultado += a;
    }
    } else{
        k = -b;
        for(n = 1; n <= k; n++){
        resultado -= a;
    }
    }
    printf("O resultado e igual a: %d\n", resultado);

	return 0;
}