#include <stdio.h>
#define N 50

int main(){

    int primos[N] = {0};
    primos[0] = 2;
    int i = 0, j = 3, sum = 0;

    

    while(primos[N-1] == 0 && j < 50){
        for (i = 0; i < j; i++){

            if (j % primos[i] == 0){  
                sum += 1;              
            }
        }
        /* if (sum < 2){
            printf("%d e primo\n", j);
            primos[i+1] = j;
        } */
        j++;
    }
    

    /*  for(i = 0; i < N; i++){
        printf("%5d", primos[i]);
    }
    printf("\n");   
 */

    return 0;
}