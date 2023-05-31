/*Esse programa recebe o raio de um circulo e calcula sua area e sua circunferencia.
 * entradas: raio
 * saidas: area, circunferencia
 * auxiliares: pi*/

#include <stdio.h>
int main(){
	float raio; //entrada
	float area, circunferencia; //saida
	float pi = 3.141593; //variaveis auxiliares
	
	printf("Calculadora de circulos v1.0\nDigite o raio do seu circulo: ");
	scanf("%f", &raio);

	if (raio <= 0){
		printf("Por favor, digite um raio geometricamente valido!\n");
	}
	else{
		area = pi * raio * raio;
        	circunferencia = 2 * pi * raio;
		printf("A area calculada e igual a: %.2f\nA circunferencia calculada e igual a: %.2f\nFim do Programa!\n", area, circunferencia);
	}
	return 0;
}
