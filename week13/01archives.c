#include <stdio.h>


int main(){
    FILE *arquivo1;
    int num = 5;
    int numlido;
    int quant = 1;
    if(!(arquivo1 = fopen("001.bin", "w+"))){
        puts("Erro na abertura do arquivo!");
    } else{
        
        if(fwrite(&num, sizeof(int), quant, arquivo1) != quant){
            printf("Erro na escrita!\n");
        } else{
            printf("Escrita bem sucedida!\n\nLendo arquivo...\n\n");

            rewind(arquivo1); //Retorna o ponteiro para o inicio do arquivo para nao ocorrer erro na leitura

             if ((fread(&numlido, sizeof(int), quant, arquivo1))!=quant){
                printf("Erro na primeira Leitura!\n");
            } else{

                printf("Leitura bem sucedida!\nvalor lido = %d\n", numlido);
            }
        } 
       fclose(arquivo1);
    }   


    return 0;
}