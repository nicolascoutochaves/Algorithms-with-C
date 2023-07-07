#include <stdio.h>
#include <string.h>
#define MAX 5 // define o numero maximo de alunos
#define MAXCHAR 30 //define o n maximo de caracteres do nome

int main(){
    char nomealuno[MAX][MAXCHAR + 1] = {0};
    float notas[MAX][3] = {0};
    float media = 0, mediaturma = 0;
    int i, j;

    for (i = 0; i < MAX; i++){
        printf("Insira o nome do aluno %d: ", i+1);

         if(fgets(nomealuno[i], MAXCHAR + 1, stdin) != NULL){
            nomealuno[i][strlen(nomealuno[i])-1] = '\0';
            //puts(nomealuno[i]);

        } else{
            puts("ERRO ao receber o valor do nome do aluno");
        } //Insere o nome do aluno
        

        for(j = 0; j < MAX - 1; j++){
            printf("Insira a nota %d do aluno ", j+1);
            printf("%s: ", nomealuno[i]);
            scanf("%f", &notas[i][j]);
        } //Insere as notas do aluno

        for(j = 0; j < MAX - 1; j++){
            media += notas[i][j]; //Faz o somatoria das notas do aluno atual
        } //Insere as notas do aluno

        media /= (MAX - 1); //Calcula a media do aluno atual

        mediaturma += media;

        printf("Media do aluno %d e igual a: %.1f\n", i+1, media);

        notas[i][2] = media; //Insere a media do aluno na terceira posicao de cada linha da matriz

        media = 0; //reseta a variavel media para ser reutilizada no proximo aluno

        fflush(stdin); //Libera o buffer para realizar uma nova leitura
    }

    mediaturma /= (MAX); //Calcula a media da turma

    printf("Media turma = %.1f\n", mediaturma);
    /* for (i = 0; i < MAX; i++){
        
        for (j = 0; j < 3; j++){
            printf("%5.1f", notas[i][j]);
        }
        printf("\n"); //Teste que printa as notas dos alunos em forma de matriz
    } */

     for (i = 0; i < MAX; i++){
        if(notas[i][2] > mediaturma){
            printf("O aluno %s teve nota acima da media da turma!\n", nomealuno[i]);
        }
    }

    return 0;
}
