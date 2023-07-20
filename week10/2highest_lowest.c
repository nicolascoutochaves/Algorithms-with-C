#include <stdio.h>
void cmp(int *a, int *b){
    if(*a > *b){
        printf("a is greater than b\n");
    } else if(*a < *b){
        printf("a is lower than b\n");
    } else{
        printf("a is equal b\n");
    }
}
int main(){
    int a, b;
    printf("Enther the values for a and b: ");
    scanf("%d%d", &a, &b);
    cmp(&a, &b);
    return 0;
}