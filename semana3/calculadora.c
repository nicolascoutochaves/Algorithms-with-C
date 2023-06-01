/*Programa que recebe numeros e realiza operacoes matematicas que o usuario solicita
 * entradas: n1, n2, operador
 * saidas: resultado
 * variaveis auxiliares: flag*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(){
	long double n1, n2;
	char operador;
	long double resultado;
	int flag = 0; //variavel verificadora de erros
	
	printf("Calculadora.\nOperacoes aceitas: +, -, *, /, e (potenciacao), v (radiciacao)\nExemplo: 13 * 4, 2v100, 3e2.\n\nDigite a operacao matematica: ");
	scanf("%Lf %c%Lf", &n1, &operador, &n2);
	operador = tolower(operador);
	switch(operador){
		
		case '+': resultado = n1 + n2;
			  break;
			  
		case '-': resultado = n1 - n2;
                          break;
			  
		case '*': resultado = n1 * n2;
                          break;
			  
		case '/': if(n2 == 0){
				  flag = 1;
				  printf("Impossível dividir por zero!\n");
			  } else{
			  	resultado = n1 / n2;
			  }
                          break;
			  
		case 'e':  if (n1 == 0 && n2 < 0 || n1 < 0 && n2!=(int)n2){
				  printf("[Erro] O dominio da funcao e:\n(n1 E R: (n1 >= 0 e n2 > 0) ou (n1 < 0 e n2 E Z))\n");
				  flag = 1;
			  } else{ 
			  resultado = pow (n1, n2);
                          break;
			  }
			  
		case 'v': if(n2 < 0){
				  flag = 1;
				  printf("Raiz inválida (n2 < 0)\n");
			  } else{
				n1 = 1/n1;
			  	resultado = pow(n2,n1);
			  }
                          break;
		default:
			  flag = 1;
	}
	if(flag == 0){
	printf("O resultado foi: %.4Lf\nFim do programa.\n", resultado);	
	} else{
	printf("[ERRO]\nOperacao invalida!\nFim do programa.\n");
	}

	return 0;
}

