#include <stdio.h>
#include <stdlib.h>
#include "matrix.c"
typedef struct{
    int res[ROWS][COLUMNS];
}result;

result multiplicateMatrix(int m1[ROWS][COLUMNS], int m2[ROWS][COLUMNS]){
    int i, j, k, l;
    int tmp;
    result result;
   
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
            tmp = 0;
            for(k = 0; k < COLUMNS; k++){
                
                tmp += m1[i][k] * m2[k][j];
            }
            result.res[i][j] = tmp;
        }

    }
    return result;
}
int main(){
    int m1[ROWS][COLUMNS], m2[ROWS][COLUMNS];
    result result;
    populateMatrix(m1);
    populateMatrix(m2);
    printMatrix(m1);
    printMatrix(m2);
    result = multiplicateMatrix(m1, m2);
    printMatrix(result.res);


    return 0;
}