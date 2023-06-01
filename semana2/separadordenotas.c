/*Este Programa recebe um valor e diz ao usuario a quantidade de cada cedula ele deve receber de troco 
 * Entradas: valor
 * Saidas:n1, n2, n5, n10, n20, n50, n100*/

#include <stdio.h>

int main(){
	int valor;
	int n1, n2, n5, n10, n20, n50, n100;

	printf("Separador de notas v1.0\nDigite o valor: ");
	scanf("%d", &valor);
	int v = valor;
	n100 = v / 100;
	v = v % 100;
	n50 = v / 50;
	v = v % 50;
	n20 = v / 20;
        v = v % 20;
	n10 = v / 10;
        v = v % 10;
	n5 = v / 5;
        v = v % 5;
	n2 = v / 2;
        v = v % 2;
	n1 = v / 1;
	v = v % 1;
	
	printf("Os valores sao:\n100: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\nFim do Programa.\n", n100, n50, n20, n10, n5, n2, n1);


	return 0;
}

