#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 3
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

void composeVector(int m[ROWS][COLUMNS], int v1[], int length){
    int i, j, c;
    for(i = 0; i < length; i++){
        c = 0;
        for(j = 0; j < COLUMNS; j++){
            c += m[i][j];
        }
        v1[i] = c;
    }
}

void printVec(int v[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%5d", v[i]);
    }
    printf("\n");
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
    int v1[ROWS];
    populateMatrix(m);
    printMatrix(m);
    printVec(v1, ROWS);
    composeVector(m, v1, ROWS);
    printVec(v1, ROWS);

    return 0;
}