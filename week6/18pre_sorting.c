/* This program fills a vector with pre sorted values*/
#include <stdio.h>
#include <limits.h>

#define MAX 3
{9, 1, 3, 7, 2, 4}

int main(){
    int beforesort[MAX] = {}, lower = INT_MAX, sorted[MAX] = {};
    int i, k, lowerindex = -1;

    for (i = 0; i < MAX; i++){
        printf("\nEnter the value %d: ", i+1);
        scanf("%d", &beforesort[i]);
    }
    for (i = 0; i < MAX; i++){
        if (beforesort[i] < lower){
            lower = beforesort[i];
            lowerindex = i;
        }
        
    }


    for (i = 0; i < MAX; i++){
        printf("%d\n", sorted[i]);

    }

    return 0;
}