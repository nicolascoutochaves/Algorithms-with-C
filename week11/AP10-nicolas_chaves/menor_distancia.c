/*Esse programa recebe dois vetores coordenadas cartesianas e realiza o calculo da menor distancia entre os pontos*/
#include <stdio.h>
#include <math.h>
#include <float.h>
#define N 5

//funcao que retorna por referencia os pontos x e y que possuem a menor distancia, alem de sua distancia

float menorDistancia(float x[], float y[], int tam, int *indexp1, int *indexp2){
    int i, j; //variaveis de controle
    float distancia;
    float menor_distancia = FLT_MAX; //menor distancia inicia com o valor do float max

    for(i = 0; i < tam; i++){
        for(j = tam-1; j > i; j--){
                distancia = sqrt( pow((x[i] - x[j]),2) + pow((y[i] - y[j]),2) ); //Formula da menor distancia de dois pontos
                if(distancia < menor_distancia){
                    menor_distancia = distancia;
                    *indexp1 = i;
                    *indexp2 = j;
                }
        }
    }
    return menor_distancia;
}

int main(){
    float x[N], y[N];
    int indexp1, indexp2; //indices dos pontos 1 e 2
    float menordistancia;
    int i;

    for(i = 0; i < N; i++){

        printf("Informe as coordenadas x  e y do ponto %d: ", i+1);
        scanf("%f%f", &x[i], &y[i] );

    }

    menordistancia = menorDistancia(x, y, N, &indexp1, &indexp2);

    printf("Os pontos (%.2f, %.2f) e (%.2f, %.2f) tem distancia %.2f!\n", x[indexp1], y[indexp1], x[indexp2], y[indexp2], menordistancia);


    return 0;
}

