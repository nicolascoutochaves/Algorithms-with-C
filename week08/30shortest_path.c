#include <math.h>
#include "map.c"

void calculateDistance(int m[MAP_HEIGHT][MAP_WIDTH], int src[], int dest[]){
    int y = src[0], x = src[1];
    int y2 = dest[0], x2 = dest[1];
    int i, j;
    m[y2][x2] = -2;
    int distancex = sqrt(pow((x2 - x), 2));
    int distancey = sqrt(pow((y2 - y), 2));

    for(i = y; abs(i - y2) > 0; i += distancey/(y2 - y)){
        for(j = x; abs(j - x2) > 0; j += distancex/(x2 - x)){
            if(m[i][j] != -1){
                m[i][j] = sqrt(pow(i - y2, 2) + pow(j - x2, 2));
            }
        }
    }

}
int main(){
    int m[MAP_HEIGHT][MAP_WIDTH] = {0};
    int i, j;
    int src[2] = {5, 5};
    int dest[2] = {10, 10};

    generateMap(m);
    
    for(i = 0; i < MAP_HEIGHT; i++){
        for(j = 0; j < MAP_WIDTH; j++){
            if(m[i][j]){
                m[i][j] = 0;
            }  else{
                m[i][j] = -1;
            }
        }
    }

    calculateDistance(m, src, dest);
    printPathMap(m);

    return 0;
}
  
