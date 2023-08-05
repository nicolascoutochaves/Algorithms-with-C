/* This program prints a '*' according to a vector given by the user */
#include <stdio.h>
#define MAX 5

int main(){
    int n[MAX] = {};
    int i, k;

    for (i = 0; i < MAX; i++){
        printf("\nEnter the value %d: ", i+1);
        scanf("%d", &n[i]);
    }

    for (i = 0; i < MAX; i++){

        for (k = 0; k < n[i]; k++){

            printf("*");
        }
        printf("\n");

    }

    return 0;
}