/* Esse programa tenta adivinhar o número natural não nulo N que o usuário está pensando, com base
em pistas que ele oferece. */

#include <stdio.h>

int main(){
    
	int dn, ndn, mn, nmn; //entradas: divisor de n, nao divisor de n, multiplo de n e um nao multiplo de n.    
    int i, maiornumero; //variaveis de controle

    printf("Adivinhador de numeros\nPense em um numero n e complete as informacoes\n\n");
    printf("Digite um divisor de n: ");
    scanf("%d", &dn);

    printf("Digite um nao divisor de n: ");
    scanf("%d", &ndn);

    printf("Digite um multiplo de n: ");
    scanf("%d", &mn);

    printf("Digite um nao multiplo de n: ");
    scanf("%d", &nmn);


    if (mn >= nmn && mn >= ndn){
        maiornumero = mn;
    } else if(ndn >= nmn && ndn >= mn){
        maiornumero = ndn;
    } else{
        maiornumero = nmn;
    }

    for(i = 1; i <= maiornumero; i++){
        if((i % dn) == 0 && (i % ndn) != 0 && (mn % i) == 0 && (nmn % i) !=0){
            printf("%d\n", i);
        }
    }

	return 0;
}