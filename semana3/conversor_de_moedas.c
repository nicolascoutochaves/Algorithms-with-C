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
    moedaorigem = tolower(moedaorigem);
    scanf(" %c", &moedaorigem);

    printf("Digite a moeda de destino (use R/r para real, D/d para dolar e E/e para euro)\n");
    moedadestino = tolower(moedadestino);
    scanf(" %c", &moedadestino);

    printf("Digite o montante em ");
    switch (moedaorigem){
        case 'r':
            printf("Real: ");
            break;
        case 'd':
            printf("Dolar: ");
            break;
        case 'e':
            printf("Euro: ");
        break;
        default: printf("\n[Erro]\nDigite uma moeda valida!n");
    }
    scanf("%f", &montante);


    return 0;
}
