#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 6
#define MAX_RAND 100

void populateMatrix(int **m){
    int i, j;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            m[i][j] = rand() % MAX_RAND;
        }
    }
}

void search(int n, int **m){
    int i, j;
    int flag = 0;

    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            if(n == m[i][j]){
                printf("%d found on line %d, column %d!\n", n, i+1, j+1);
                flag = 1;
            }
        }
    }
    if(!flag){
        printf("%d not found anywhere!\n", n);
    }
}

void printMatrix(int **m){
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
    int i, n;
    int **m = NULL;
    m = (int **) calloc (ROWS, sizeof(int *));

    for(i = 0; i < COLUMNS; i++)
        m[i] = (int *) calloc (COLUMNS, sizeof(int));

    populateMatrix(m);   

    printMatrix(m);

    printf("Enter the number to search: ");
    scanf("%d", &n);

    search(n, m);

    free(m);
    for(i = 0; i < COLUMNS; i++)
        m[i] = NULL;

    m = NULL;

    return 0;
}