/* Esse programa recebe uma palavra do usuario e indica se um caractere aparece mais de uma vez.
Entradas: vetor de caracteres.
Saidas: quantidade de caracteres que repetem 2 ou mais vezes.
*/

//INCOMPLETA

#include <stdio.h>
#include <string.h>
#define MAX 25

int main(){

    char s[MAX+1] = {};
    char s2[MAX+1] = {};
    int i, j, k, flag = 0, contador = 1;

    printf("Analisador de caracteres repetidos\nDigite uma palavra a ser analisada: ");

    if (fgets(s, MAX+1, stdin) != NULL){
        s[strlen(s)-1] = '\0'; // Atribui o '\0' na ultima posi��o da string.
        }
      else {
        puts("Erro");
      }



    for(i = 0; i < strlen(s); i++){

        for(j = i+1; j < strlen(s); j++){


            if (s[i] == s[j]) { //Verifica se um valor repete ao longo da string
                s2[i] = s[i];
                contador += 1;
                
                //printf("%c e igual a %c\n", s[i], s[j]);

            } else{
                //printf("%c nao e igual a %c\n", s[i], s[j]);
            }
            
        }

        while (contador > 1 && i < strlen(s2)){
            printf("O caractere %c aparece %d vezes\n", s2[i], contador);
            contador = 1;
        }
        
        


    }

    puts(s2);


    return 0;
}
