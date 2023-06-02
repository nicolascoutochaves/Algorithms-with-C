/* Esse programa analisa os precos de combustiveis e identifica qual tem o melhor custo x beneficio
entradas: gascomum, gasadt, etanol
saidas: cideal
variaveis auxiliares: razao, gasbarata
*/

#include <stdio.h>
int main(){
    float gascomum, gasadt, etanol; // precos de gasolina comum, gasolina aditivada e etanol
    int cideal; //recebe o codigo do combustivel

    float razao; //variavel que auxilia no calculo do custo beneficio

    printf("Calculadora de custo x beneficio.\nDigite os precos dos combustiveis:\n\n");
    printf("Gasolina aditivada: R$");
    scanf("%f", &gasadt);

    printf("Gasolina comum: R$");
    scanf("%f", &gascomum);

    printf("Etanol: R$");
    scanf("%f", &etanol);

    if (gascomum >= gasadt){
        razao = etanol / gasadt;

    } else {
        razao = etanol / gascomum;
    }
    //printf("Razao = %f\n", razao); //Teste

    if(razao < (float)7/10){
            cideal = 1; //cideal == etanol

    } else if((razao >= (float)7/10) && (gascomum >= gasadt)){
            cideal = 2; //cideal == gasolina aditivada

    } else if((razao >= (float)7/10) && (gascomum < gasadt)){
            cideal = 3; //cideal == gasolina comum
    }
    else {
        cideal = 4; // sem preferencia
    }

    //printf("cideal = %d\n", cideal); //Teste

    printf("O combustivel ideal e: ");
    switch(cideal){
        case 1: printf("etanol\n");
            break;
        case 2: printf("gasolina aditivada\n");
            break;
        case 3: printf("gasolina comum\n");
            break;
        default: ("Nao ha preferencia de combustivel\n");
    }

    return 0;
}
