/* Program that calculetes the body mass index (bmi) */
#include <stdio.h>
#include <math.h>
#define N_PERSON 5
int main(){
    float weight[N_PERSON] = {}, heigh[N_PERSON] = {};
    float bmi[N_PERSON] = {};
    int i;
    
    for (i = 0; i < N_PERSON; i++){
        printf("Enter the weight (kg) %d: ", i+1);
        scanf("%f", &weight[i]);

        printf("Enter the heigh (m) %d: ", i+1);
        scanf("%f", &heigh[i]);

        bmi[i] = weight[i] / pow(heigh[i], 2);

    }

    for (i = 0; i < N_PERSON; i++){
        printf("Weight %d = %.2f     Heigh %d = %.2f     BMI %d = %.2f\n", i+1, weight[i], i+1, heigh[i], i+1, bmi[i]);
    }

    return 0;
}