/* Esse programa recebe um numero 'n' e mostra todos os numeros primos ate 'n'. */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
    int n;
    int i, k, j = 0; // variaveis de controle
    n = 104729; //atribui o 10.000° numero primo conhecido anteriormente atraves do codigo de erastostenes

    // para armazenar o tempo de execução do código
    double time_spent = 0.0;
    
    clock_t begin = clock();

    /* printf("Digite o valor de n: ");
    scanf("%d", &n); */

    for(i = 2; i <= n; i++){
        for(k = 1; k <= i; k++){
            if(i % k == 0){
                j += 1; //i e divisivel por k, j e incrementado
            }
        }
        if(j == 2) {
            printf("%d\n", i); //se j so foi incrementado 2 vezes durante a execucao, significa que o numero so foi dividido 2 vezes: por 1 e por ele mesmo, ou seja, o numero e primo.
        }
        j = 0;
    }


 
 
    //faz algumas coisas aqui
    sleep(3);
 
    clock_t end = clock();
 
    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("The elapsed time is %f seconds\n", time_spent);

    //The elapsed time is 35.669205 seconds

    return 0;
}