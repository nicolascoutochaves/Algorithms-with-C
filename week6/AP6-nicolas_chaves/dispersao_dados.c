/* Esse programa le um conjunto de numeros de um usuario e uma tolerancia maxima,
calcula a media deles e indica o desvio padrao e se os valores sairam ou nao do limiar de tolerancia.
Entradas: vetor numerico.
Saidas: desvio padrao e tolerencia.
*/
#include <stdio.h>
#include <math.h>
#define MAX 10

int main(){
    float resultados[MAX] = {}, tol; //dados do experimento e tolerancia
    float desviopadrao = 0, somatorio =0, media = 0;
    int i, j;

    printf("Calculo de Dispersao de dados experimentais\nInsira a tolerancia do desvio: ");
    scanf("%f", &tol);

    printf("Por favor, insira um conjunto de ate 10 dados experimentais:\n");
    for(i = 0; i < MAX; i++){
        printf("Insira o resultado do experimento %d: ", i+1);
        scanf("%f", &resultados[i]);
    }


    for(i = 0; i < MAX; i++){
        media += resultados[i];
    }   media /= MAX; // calculo da media dos valores do vetor

    //printf("Media = %f\n", media);

    for(i = 0; i < MAX; i++){
        somatorio += pow(resultados[i] - media, 2); //realiza o somatorio interno desvio padrao
    }
        desviopadrao = sqrt(somatorio / MAX); //calcula o desvio padrao



    printf("O desvio padrao dos experimentos foi de: %f\n", desviopadrao);
    if(desviopadrao <= tol){
        printf("O desvio padrao esta dentro da tolerancia\n");
    } else{
        printf("O desvio padrao esta FORA da tolerancia!\n");
    }

    return 0;
}
