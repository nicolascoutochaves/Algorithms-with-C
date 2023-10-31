#include <stdio.h>
#include <math.h>
#include "matrix.h"

void calculateDistance(int m[ROWS][COLUMNS], int src[], int dest[]){
    int y = src[0], x = src[1];
    int y2 = dest[0], x2 = dest[1];
    int i, j;
    

     /* for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
              if(!m[i][j]){
                m[i][j] = -1;
            } else  {
                m[i][j] = abs(x - j) + abs(y - i); //sqrt(pow((j - x),2) + pow((i - y),2)); //Just to compare the Euclidian distance to Manhattan distance
            }
        }
    } */ 
    
}
int main(){
    int m[ROWS][COLUMNS] = {0};
    int src[2] = {8,10};
    int dest[2] = {13, 13};
    populateMatrix(m);
    calculateDistance(m, src, dest);
    printMatrix(m);

    return 0;
}
