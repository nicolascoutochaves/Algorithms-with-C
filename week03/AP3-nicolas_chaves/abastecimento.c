/* Esse programa analisa os precos de combustiveis e identifica qual tem o melhor custo x beneficio
entradas: gascomum, gasadt, etanol
saidas: cideal
variaveis auxiliares: razao
*/

#include <stdio.h>
int main(){
    double gascomum, gasadt, etanol; // precos de gasolina comum, gasolina aditivada e etanol
    int cideal; //recebe o codigo do combustivel

    double razao; //variavel que auxilia no calculo do custo beneficio

    printf("Calculadora de custo x beneficio.\nDigite os precos do litro dos combustiveis:\n\n");
    printf("Etanol: R$");
    scanf("%lf", &etanol);

    printf("Gasolina comum: R$");
    scanf("%lf", &gascomum);
    
    printf("Gasolina aditivada: R$");
    scanf("%lf", &gasadt);

    if (gascomum >= gasadt){
        razao = etanol / gasadt;

    } else {
        razao = etanol / gascomum;
    }
    //printf("Razao = %lf\n", razao); //Teste da razao

    if(razao < (double)0.70){
            cideal = 1; //cideal == etanol

    } else if((razao >= (double)0.70) && (gascomum >= gasadt)){
            cideal = 2; //cideal == gasolina aditivada

    } else if((razao > (double)0.70) && (gascomum < gasadt)){
            cideal = 3; //cideal == gasolina comum
    }
    else {
        cideal = 4; // sem preferencia
    }

    //printf("cideal = %d\n", cideal); //Teste do tipo de combustivel

    printf("O combustivel ideal e: ");
    switch(cideal){
        case 1: printf("etanol\n");
            break;
        case 2: printf("gasolina aditivada\n");
            break;
        case 3: printf("gasolina comum\n");
            break;
        default: printf("Nao ha preferencia de combustivel\n");
    }

    return 0;
}
