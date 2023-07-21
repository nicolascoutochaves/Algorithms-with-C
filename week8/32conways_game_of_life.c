#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#define X 38
#define Y 150



int main(){
    int states[X][Y] = {0}, newstates[X][Y] = {0};
    char board[X][Y] = {};
    int i, j, k, l;
    int counter = 0, newstate;
    char next = 's';

    srand(time(NULL));
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            states[i][j] = round((float)rand() / RAND_MAX);
        }
    }

 do{
    for(i = 0; i < X; i++){
        for(j = 0; j < Y; j++){
            if(i-1 > 0 && j-1 > 0){
                if (states[i-1][j-1] == 1) counter++;
                if (states[i-1][j] == 1) counter++;
                if (states[i-1][j+1] == 1) counter++;
                if (states[i][j-1] == 1) counter++;
                if (states[i][j+1] == 1) counter++;
                if (states[i+1][j-1] == 1) counter++;
                if (states[i+1][j] == 1) counter++;
                if (states[i+1][j+1] == 1) counter++;
                //printf("counter = %d\n", counter);
                if (states[i][j] == 1){
                    if (counter < 2){
                        newstate = 0;
                    } else if (counter > 3){
                        newstate = 0;
                    } else{
                        newstate = 1;
                    }
                } else if (states[i][j] == 0 ){
                    if (counter == 3){
                        newstate = 1;
                    } else{
                        newstate = 0;
                    }
                }
                newstates[i][j] = newstate;
                counter = 0;
                }
        }
        
    }
        for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
                states[i][j] = newstates[i][j];
            }  
        }


        for(i = 0; i < X; i++){
                for(j = 0; j < Y; j++){

                    if (newstates[i][j] == 1){
                        printf("#");
                    } else{
                        printf(" ");
                    }
                }
                printf("\n");
            }
        
        usleep(200000);
        //printf("next?");
 }while (next == 's');



    /* for(i = 0; i < X; i++){
            for(j = 0; j < Y; j++){
            printf("%5d", states[i][j]);
            }
            printf("\n");
        } */

 /*             Rows and columns:

        i-1, j-1    i-1, j    i-1, j+1

        i, j-1      i, j       i, j+1

        i+1, j-1    i+1, j     i+1, j+1
    
                


     */
   /*  i = 1;
    j = 2;
    printf("\ni = %d,  j = %d\n\n", i, j);
    printf("i-1, j-1: %d\n", states[i-1][j-1]);
    printf("i-1, j: %d\n", states[i-1][j]);
    printf("i-1, j+1: %d\n", states[i-1][j+1]);
    
    printf("i, j-1: %d\n", states[i][j-1]);
    printf("\ni, j: %d\n\n", states[i][j]);
    printf("i, j+1: %d\n", states[i][j+1]);

    printf("i+1, j-1: %d\n", states[i+1][j-1]);    
    printf("i+1, j: %d\n", states[i+1][j]);
    printf("i+1, j+1: %d\n", states[i+1][j+1]); */

    


   

   


    return 0;
}