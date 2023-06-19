/*Esse programa recebe indefinidamente os valores de receita/despesa de um usuario ate que o valor inserido seja = 0
e no final imprime os valores acumulados, assim como o balanco final e o percentual de despesas.
entradas: valores diferentes de 0;
saidas: receitas, despesas, balanco final, percentual de despesas*/

#include <stdio.h>
int main(){
    float valor; //variaveis de entrada
    float receita = 0, despesa = 0, percentdespesa; //variaveis de saida

    printf("Calculo de balanco.\nDigite as receitas/despesas(digite 0 para sair):\n");
    do{
        scanf("%f", &valor);

        if(valor < 0){
            despesa += valor * -1; // Acumula a despesa e inverte o sinal.
        } else{
            receita += valor;
        }
    } while(valor != 0);

    percentdespesa = despesa * 100 / receita;

    printf("O total de receitas foi: R$%.2f\n", receita);
    printf("O total de despesas foi: R$%.2f\n", despesa);
    printf("O balanco total foi: R$%.2f\n", receita - despesa); //calcula o balanco no printf para nao precisar declarar uma nova variavel para realizar uma tarefa "simples"
    if(receita != 0) {
            printf("O percentual de receita gasto com despesas foi de: %.2f%%\n", percentdespesa);
    } else{
        printf("Nao houve receita para calcular o percentual de despesas!\n");
    }


    return 0;
}
