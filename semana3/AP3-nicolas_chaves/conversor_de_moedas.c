/*
Atividade Incompleta
*/

#include <stdio.h>
#include <ctype.h>

#define RUS 0.19132101
#define REUR 0.18119005
#define USEUR 0.94704732

int main(){
    float montante, resultado;
    char moedaorigem, moedadestino;
    printf("Conversor de moedas\nDigite a moeda de origem (use R/r para real, D/d para dolar e E/e para euro): ");
    scanf(" %c", &moedaorigem);
    moedaorigem = tolower(moedaorigem);

    printf("Digite a moeda de destino (use R/r para real, D/d para dolar e E/e para euro) ");
    scanf(" %c", &moedadestino);
    moedadestino = tolower(moedadestino);

    printf("Digite o montante em ");
    switch (moedaorigem){
        case 'r':
            printf("Real: R$");
	    scanf("%f", &montante);
	    
	    if (moedadestino == 'd'){
		resultado =  montante * RUS;
		printf("Seu montante em dolares e de U$%.2f\n", resultado);
	    } else if (moedadestino == 'e'){
		resultado = montante * REUR;
                printf("Seu montante em euros e de £%.2f\n", resultado);
	    } else{
	    printf("Impossivel converter para essa moeda!\n");
	    }
	    break;
		  
        case 'd':
            printf("Dolar: U$");
	    scanf("%f", &montante);

	    if (moedadestino == 'r'){
                resultado = montante / RUS;
                printf("Seu montante em real e de R$%.2f\n", resultado);
            } else if (moedadestino == 'e'){
                resultado = montante / RUS * REUR;
                printf("Seu montante em dolares e de U$%.2f\n", resultado);
            } else{
            printf("Impossivel converter para essa moeda!\n");
            }

            break;
        case 'e':
            printf("Euro: £");
	    scanf("%f", &montante);

	    if (moedadestino == 'd'){
                resultado = montante / REUR * RUS;
                printf("Seu montante em dolares e de U$%.2f\n", resultado);
            } else if (moedadestino == 'r'){
                resultado = montante / REUR;
                printf("Seu montante em real e de R$%.2f\n", resultado);
            } else{
            printf("Impossivel converter para essa moeda!\n");
            }

        break;
        default: printf("\n[Erro]\nDigite uma moeda valida!\n");
    }
    

    return 0;
}
