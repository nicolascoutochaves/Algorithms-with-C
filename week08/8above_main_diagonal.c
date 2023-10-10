#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5
#define MAX_RAND 10

void populateMatrix(int m[ROWS][COLUMNS]){
    int i, j;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m[i][j] = rand() % MAX_RAND;
        }
    }
}

void printMainDiagonal(int m[ROWS][COLUMNS]){
    int i, j, c = 0;

    for(j = 0; j < COLUMNS; j++){
        printf("%5d", j+1);
    }
    printf("\n\n");
    for(i = 0; i < ROWS; i++, c++){
        printf("%d", i+1);
        
        for(j = 0; j < COLUMNS; j++){
            if(j >= c)
                printf("%5d", m[i][j]);
            else printf("%5s", " ");
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    int i, n;
    int m[ROWS][COLUMNS] = {0};
    populateMatrix(m);  
    printMainDiagonal(m);


    return 0;
}