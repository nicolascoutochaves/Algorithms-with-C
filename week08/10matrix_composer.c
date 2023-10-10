#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 4
#define MAX_RAND 100

void populateVec(int v[], int length){
    int i;
    srand(time(NULL)+(time_t)v); //using the addres of each vec to avoid same values
    for(i = 0; i < length; i++){
        
        v[i] = rand() % MAX_RAND;
        
    }
}

void composeMatrix(int m[ROWS][COLUMNS], int v1[], int v2[], int v3[], int length){
    int i;
    for(i = 0; i < length; i++){
        m[0][i] = v1[i];
        m[1][i] = v2[i];
        m[2][i] = v3[i];
    }
}

void printMatrix(int m[ROWS][COLUMNS]){
    int i, j;

    for(j = 0; j < COLUMNS; j++){
        printf("%5d", j+1);
    }
    printf("\n\n");
    for(i = 0; i < ROWS; i++){
        printf("%d", i+1);
        
        for(j = 0; j < COLUMNS; j++){
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(){
    int m[ROWS][COLUMNS] = {0};
    int v1[COLUMNS] = {0}, v2[COLUMNS] = {0}, v3[COLUMNS] = {0};
    populateVec(v1, COLUMNS);
    populateVec(v2, COLUMNS);
    populateVec(v3, COLUMNS);
    printMatrix(m);
    composeMatrix(m, v1, v2, v3, COLUMNS);
    printMatrix(m);


    return 0;
}