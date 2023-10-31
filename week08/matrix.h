#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLUMNS 30
#define MAX_RAND 2

void populateVec(int v[], int length){
    int i;
    srand(time(NULL)+(time_t)v); //using the addres of each vec to avoid same values
    for(i = 0; i < length; i++){
        
        v[i] = rand() % MAX_RAND;
        
    }
}
void populateMatrix(int m[ROWS][COLUMNS]){
    int i, j;
    srand(time(NULL)+(time_t)m);
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m[i][j] = rand() % MAX_RAND;
        }
    }
}


void printMatrix(int m[ROWS][COLUMNS]){
    int i, j;
    printf("        ");
    for(j = 0; j < COLUMNS; j++){
        printf("%02d  ", j+1);
    }
    printf("\n\n");
    for(i = 0; i < ROWS; i++){
        printf("%02d   ", i+1);
        
        for(j = 0; j < COLUMNS; j++){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printVec(int v[], int length){
    int i;
    for(i = 0; i < length; i++){
        printf("%5d", v[i]);
    }
    printf("\n");
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