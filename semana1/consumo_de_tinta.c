/*Esse programa calcula a quantidade de latas de tinta necessarias e os custos por metro quadrado
 * entradas: numchapas, largura, comprimento, custotinta, rendimentotinta, demaos
 * saidas: numerodelatas, cusstototal
 * auxiliares: area*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
	float numchapas, largura, comprimento, custotinta, rendimentotinta; int demaos; //entradas
	float custototal; int numerodelatas; //saidas
	float area; //auxiliares

	setlocale(LC_ALL, "Portuguese"); //permitir uso de virgula no terminal

	printf("Calculadora de consumo de tinta v1.0\n\nDigite a quantidade de chapas a serem pintadas: ");
	scanf("%f", &numchapas);

	printf("Digite a largura da chapa (m): ");
	scanf("%f", &largura);

	printf("Digite o comprimento da chapa (m): ");
	scanf("%f", &comprimento);

	printf("Digite o número de demãos a serem aplicadas: ");
	scanf("%d", &demaos);

	printf("Digite o custo da lata de tinta: R$");
	scanf("%f", &custotinta);

	printf("Digite o rendimento por m² da tinta (vide rótulo): ");
	scanf("%f", &rendimentotinta);

	area = largura * comprimento;
	numerodelatas =  ceil(numchapas * area * demaos / rendimentotinta); //Arrendonda pra cima o numero de latas
	custototal = numerodelatas * custotinta;

	printf("\nVocê precisará de: %d latas de tinta.\nO custo total será de: R$%.2f \n\n", numerodelatas, custototal);


	return 0;
}
