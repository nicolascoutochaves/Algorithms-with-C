/* Esse programa recebe as notas de provas e trabalhos de diversos alunos, realiza uma soma ponderada delas e indica a media das notas finais da turma, bem como a menor e a maior nota final.

entradas: numero de alunos, nota da prova 1, nota da prova 2, nota do trabalho
saidas: media do aluno, menor nota, maior nota, media da turma
*/

#include <stdio.h>

int main(){
    int nalunos; float np1, np2, nt; //entradas: numero de alunos, notas prova 1, prova 2 e trabalho;
    float mediaaluno, menornota = 10, maiornota = 0, mediaturma = 0; //saidas;
    /* Aqui a menor nota comeca com a nota maxima e a medida que sao adicionados mais alunos a menor nota eh calculada comparando a nota desses alunos com o estado anterior que inicia em 10. Da mesma forma a maior nota inicia com o valor 0.*/
    int i; //variavel de controle
    
    printf("Calculadora de conceitos. \n\nDigite a quantidade de alunos: ");
    scanf("%d", &nalunos);
    
    for(i = 1; i <= nalunos; i++ ){

        printf("\nDigite a nota da prova 1 do aluno %d: ", i);
        scanf("%f", &np1);

        printf("Digite a nota da prova 2 do aluno %d: ", i);
        scanf("%f", &np2);

        printf("Digite a nota do trabalho do aluno %d: ", i);
        scanf("%f", &nt);

        mediaaluno = ((np1 * 0.40) + (np2 * 0.40) + (nt * 0.20)) / (0.40 + 0.40 + 0.20); // realiza a media ponderada das notas do aluno

        printf("Media do aluno = %.1f\n", mediaaluno); //teste para ver se o calculo da media foi bem sucedido.

        // verifica se a nota do aluno e maior ou menor que a dos alunos anteriores:
        if (mediaaluno >= maiornota){
            maiornota = mediaaluno;
        }
        if (mediaaluno <= menornota){
            menornota = mediaaluno;
        }

        mediaturma += mediaaluno; //incrementa a mediaturma o valor da media ponderada do aluno atual

        //printf("menornota = %.2f\nmaiornota = %.2f\nmediaturma = %.2f\n", menornota, maiornota, mediaturma); //teste para verificar como as variaveis estao sendo processadas

    }

    mediaturma /= nalunos; //divide a mediaturma pelo numero de alunos

    printf("\nA menor nota da turma foi: %.1f \nA maior nota da turma foi: %.1f \nA media das notas finais da turma foi: %.1f \n", menornota, maiornota, mediaturma);

	return 0;
}