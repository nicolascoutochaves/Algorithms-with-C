#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define N 10000

int main(){

    int primos[N] = {0};
    int i , j = 3, count;
    // para armazenar o tempo de execução do código
    double time_spent = 0.0;
 
    clock_t begin = clock();

    
    primos[0] = 2;
    
    while(primos[N-1] == 0){
        count = 0;
        i = 0;
        //printf("current j = %d\n", j);
        while(primos[i] != 0 && j > primos[i]){

            if (j % primos[i] == 0){
                count += 1;
            }
            //printf("%d %% %d = %d\n", j, primos[i], j%primos[i]);
            i++;
        }            
        //printf("n of divisors = %d\n", count);
        
        if (count == 0){
            //printf("%d e primo\n", j);
            primos[i] = j;
        } else {
            //printf("%d NAO e primo\n", j);
        }
        //printf("\n");
        j++;
    }
    

      for(i = 0; i < N; i++){
        printf("%10d", primos[i]);
    }
    printf("\n");





 
    //faz algumas coisas aqui
    sleep(3);
 
    clock_t end = clock();
 
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds\n", time_spent);

    //The elapsed time is 4.455549 seconds
    //8 times faster than using the week4, exercise 29 method


    return 0;
}