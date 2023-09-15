#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 30
#define C 60


int main(){
    FILE *arquivo;
    char map[L][C] = {'\0'};
    int i, j;
    int value;
    srand(time(NULL));
    for(i=0; i<L;i++){
        for(j=0; j<C;j++){
            value = rand() % 2;
            if(value)
                map[i][j] = '#';
            else
                map[i][j] = ' ';
        }
    }
    if(!(arquivo = fopen("map1.txt", "w+")))
        puts("Erro na abertura do arquivo");
    else{
        for(i=0;i<L;i++){
            for(j=0;j<C;j++){
                if((fwrite(&map[i][j], sizeof(char), 1, arquivo))!= 1){
                    puts("ERRO DE ESCRITA NO ARQUIVO!");
                } else{
                    puts("Escrita bem sucedida!");
                }
            }
            fprintf(arquivo, "\n");
        }
            

    }






    return 0;
}