#include <stdio.h>

//sum between sl (superior limit) and il (inferior limit)
void s(int il, int sl, int *sum, float *average){
    int odd = 0, n = 0;
    int i;
    for (i = il; i <= sl; i++){
        if(i % 2 != 0){
            odd ++;
            n ++;
        }
        *sum += i;
        printf("%d\n", *sum);
    }
    *average = (float)odd / i;
}


int main(){
    int sl, il, sum = 0;
    float avg;
    printf("Insert the inferior limit: ");
    scanf("%d", &il);
    printf("Insert the superior limit: ");
    scanf("%d", &sl);
    s(il, sl, &sum, &avg);
    printf("sum = %d odds average = %.2f\n", sum, avg );
    
}