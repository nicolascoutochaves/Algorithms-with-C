/*Esse programa recebe a nota e a frequencia de alunos e realiza o calculo de conceitos indefinidamente, ate o usuario parar.
entradas: nota final, frequencia.
saidas: conceito final*/

#include <stdio.h>
#include <ctype.h>
int main(){
    float notafinal, frequencia; //variaveis de entrada
    int i = 1; char sair = 's'; //variaveis de controle
    int ca = 0, n10 = 0; //variaveis acumuladoras
    float mediaturma = 0; // variavel de saida


    printf("Conceitos finais.\nDigite a nota [0, 10] e a frequencia [0, 100] do aluno\n");
    do{
        printf("Digite a nota final do aluno %d: ", i);
        scanf("%f", &notafinal);
        printf("Digite a frequencia do aluno %d: ", i);
        scanf("%f", &frequencia);

        if (notafinal >= 0 && notafinal <= 10 && frequencia >= 0 && frequencia <= 100){

            mediaturma += notafinal;

            if (frequencia >= 75){ //Verifica se a frequencia e maior ou igual a 75 antes de verificar os conceitos

                if(notafinal == 10){
                n10 = 1; //verifica se houve ao menos 1 aluno com nota 10
                }
                if(notafinal >= 9){
                    ca += 1; //incrementa a quantidade de alunos com conceito 'A'
                    printf("O conceito do aluno %d foi: 'A'\n", i);
                }
                else if(notafinal >= 7.5){
                    printf("O conceito do aluno %d foi: 'B'\n", i);
                }
                else if(notafinal >= 6){
                    printf("O conceito do aluno %d foi: 'C'\n", i);
                }
                else if(notafinal >= 0){
                    printf("O conceito do aluno %d foi: 'D'\n", i);
                }
            } else{
                printf("O conceito do aluno %d foi: 'FF'\n", i);
            }

            i++; //incrementa o numero de alunos ja contabilizados

            printf("Deseja inserir mais dados (s/n)? ");
            scanf(" %c", &sair);

        } else {
            printf("Nao contabilizado! Digite um intervalo valido!\n");
        }

    } while(tolower(sair) == 's');

    //printf("media acumulada = %f\n", mediaturma);//teste da variavel antes da divisao
    //printf("numero de alunos = %d\n",i-1);//teste da variavel antes da divisao


    printf("A media das notas finais da turma foi: %f\n", mediaturma/(i-1)); //pega as notas acumuladas e divide pelo numero de alunos contabilizados.
    printf("O numero de alunos com conceito 'A' foi: %d\n", ca);

    if (n10 > 0){
        printf("Ao menos um aluno teve nota 10!\n");
    } else{
        printf("infelizmente nao houve nenhum aluno com nota 10\n");
    }





    return 0;
}
