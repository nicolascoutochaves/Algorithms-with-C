/* Esse programa solicita ao usuario que insira os elementos em uma matriz quadrada N x N e realiza o calculo da norma matricial.
entradas: valores da matriz
saidas: norma matricial*/

#include <stdio.h>
#include <math.h>
#define MAX 3

int main(){
    float matriz[MAX][MAX] = {0}, valor;
    float somatorio = 0, norma = 0;
    int i, j;

    for (i = 0; i < MAX; i++){

        for (j = 0; j < MAX; j++){
            printf("Insira o elemento da posicao (%d, %d): ", i+1, j+1);
            scanf("%f", &valor);
            matriz[i][j] = valor;
        }
    } //Insere os elementos na matriz

    /* for (i = 0; i < MAX; i++){
        
        for (j = 0; j < MAX; j++){
            printf("%5.1f", matriz[i][j]);
        }
        printf("\n");
    } //Teste que printa a matriz */


    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            somatorio += pow(matriz[i][j], 2);
        }
    } //Realiza o somatorio do quadrado dos termos da matriz

    norma = sqrt(somatorio); //Realiza o calculo da norma

    //printf("%f\n", somatorio);

    printf("A norma da matriz e: %.2f\n", norma);


    return 0;
}