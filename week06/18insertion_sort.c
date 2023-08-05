/* This program fills a vector with pre sorted values(Insertio sort algorithm)*/
#include <stdio.h>
#define MAX 10

int main(){
    int v[MAX] = {};
    int i, j;
    int tmp;
  

    for (int i = 0; i < MAX; i++) {
        printf("Insert the value %d: ", i+1);
        scanf("%d", &v[i]);
        tmp = v[i];
        j = i - 1;

        while (tmp < v[j] && j >= 0) {
            v[j + 1] = v[j];
            --j;
        }

        v[j + 1] = tmp;
    }
   
    for(i = 0; i < MAX; i++){
        printf("%5d", v[i]);
    }

    printf("\n");


    return 0;
}