#include <stdio.h>
#include <string.h>
#define MAXALUNOS 5 // define o numero maximo de alunos
#define MAXNOTAS 2 //define o numero de notas a serem calculadas
#define MAXCHAR 30 //define o n maximo de caracteres do nome

int main(){
    char nomealuno[MAXALUNOS][MAXCHAR + 1] = {0};
    float notas[MAXALUNOS][MAXNOTAS + 1] = {0}; //inicializa as notas com um espaco a mais para guardar a media
    float media = 0, mediaturma = 0;
    int i, j;

    for (i = 0; i < MAXALUNOS; i++){
        
        printf("\nInsira o nome do aluno %d: ", i+1);

         if(fgets(nomealuno[i], MAXCHAR + 1, stdin) != NULL){ //Insere o nome do aluno
            nomealuno[i][strlen(nomealuno[i])-1] = '\0';
            //puts(nomealuno[i]);

        } else{
            puts("ERRO ao receber o valor do nome do aluno");
        } 
        

        for(j = 0; j < MAXNOTAS; j++){
            printf("Insira a nota %d de ", j+1);
            printf(" %s: ", nomealuno[i]);
            scanf(" %f", &notas[i][j]);
            media += notas[i][j]; //Faz o somatorio das notas do aluno atual
        } //Insere as notas do aluno

        media /= (MAXNOTAS); //Calcula a media do aluno atual
        mediaturma += media;
        printf("Media de ");
        printf("%s e igual a: %.1f\n", nomealuno[i], media);

        notas[i][MAXNOTAS] = media; //Insere a media do aluno na ultima posicao de cada linha da matriz

        media = 0; //reseta a variavel media para ser reutilizada no proximo aluno

        int c;
        while ((c = getchar()) != '\n' && c != EOF) // Loop to discard remaining characters in input buffer
            ; //Trecho obtido atraves do chat gpt, pois o fflsuh(stdin) nao estava funcionando corretamente (compilado com gcc)
        
    }

    mediaturma /= (MAXALUNOS); //Calcula a media da turma

    printf("\nMedia turma = %.1f\n", mediaturma);
    /* for (i = 0; i < MAXALUNOS; i++){
        
        for (j = 0; j < 3; j++){
            printf("%5.1f", notas[i][j]);
        }
        printf("\n"); //Teste que printa as notas dos alunos em forma de matriz
    } */

     for (i = 0; i < MAXALUNOS; i++){
        if(notas[i][MAXNOTAS] > mediaturma){
            printf("O aluno %s teve nota acima da media da turma!\n", nomealuno[i]);
        }
    }

    return 0;
}
