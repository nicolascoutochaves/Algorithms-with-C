/*Esse programa verifica a intersecao de dois vetores e insere em outro vetor (v3 = v1 interseccao com v2*/
#include <stdio.h>
#include <math.h>

#define N 5

//Funcao que faz a escrita do valores da intersecao em v3 e retorna o ultimo elemento de v3
int vetorIntersecao(int v1[], int v2[], int v3[], int tam){
   int i, j, k;
   int ultimoelemento;
   for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){

                if(v2[i] == v1[j]){
                    for(k = 0; k < tam; k++){
                        if(v2[i] != v3[k]){
                            v3[i] = v2[i];
                            ultimoelemento = i;
                        }
                    }
            }
        }
   }
   return ultimoelemento; //retorna o ultimo elemento do vetor para nao printar valores que nao existem
}

int main(){
    int v1[N], v2[N], v3[N] = {0};
    int ultimo_elem;
    int i;

    //entrada dos valores no vetor:
    for(i = 0; i < N; i++){
        printf("Informe o %d valor do vetor 1: ", i+1);
        scanf("%d", &v1[i] );
    }
    for(i = 0; i < N; i++){
        printf("Informe o %d valor do vetor 2: ", i+1);
        scanf("%d", &v2[i] );
    }


    ultimo_elem = vetorIntersecao(v1, v2, v3, N); //recebe o retorno da funcao

    printf("Os elementos nao repetidos que aparecem nos vetores 1 e 2 sao: ");
    for(i = 0; i <= ultimo_elem; i++){
        printf("%d ", v3[i]);
    }
    printf("\n");


    return 0;
}

