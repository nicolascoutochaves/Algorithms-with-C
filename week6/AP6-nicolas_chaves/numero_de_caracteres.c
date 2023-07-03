/* Esse programa recebe uma palavra do usuario e indica se um caractere aparece mais de uma vez.
Entradas: vetor de caracteres.
Saidas: quantidade de caracteres que repetem 2 ou mais vezes.
*/

//INCOMPLETA

#include <stdio.h>
#include <string.h>
#define MAX 25

int main(){

    char s[MAX] = {};
    char s2[MAX] = {};
    int i, j;

    printf("Analisador de caracteres repetidos\nDigite uma palavra a ser analisada: ");

    if (fgets(s, MAX+1, stdin) != NULL){
        s[strlen(s)-1] = '\0'; // Atribui o '\0' na ultima posição da string.
        puts(s);
        }
      else {
        puts("Erro");
      }



    for(i = 0; i < strlen(s); i++){

        for(j = 0; j < strlen(s); j++){

            if (s[i] == s[j]) { //Verifica se um valor repete ao longo da string

                s2[i] = s[i]; //Atribui o valor repetido na string 2


                printf("%c e igual a %c\n", s[i], s[j]);

            } else{
                printf("%c nao e igual a %c\n", s[i], s[j]);
            }

        }
    }

    puts(s2);


    return 0;
}
