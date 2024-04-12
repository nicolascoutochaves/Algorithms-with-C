/* Program that calculetes the area of multiple lands and shows wich one is equal/above or bellow the average */
#include <stdio.h>
#define N_LANDS 5
int main(){
    float width[N_LANDS] = {0}, heigh[N_LANDS] = {0};
    float area[N_LANDS] = {0}, average = 0;
    int i, counter = 0;
    
    printf("Area calculator\nPlease, Enter the width and the heigh of the lands:\n");
    for (i = 0; i < N_LANDS; i++){
        printf("\nEnter the width (m) of land %d: ", i+1);
        scanf("%f", &width[i]);

        printf("Enter the heigh (m) of land %d: ", i+1);
        scanf("%f", &heigh[i]);

        area[i] = width[i] * heigh[i];
        average += area[i];
    }
    average /= N_LANDS;

    printf("\nAverage = %.0fm2\n", average);


    for (i = 0; i < N_LANDS; i++){
        printf("\nWidth of %d = %.2fm     Heigh of %d = %.2fm     Area of %d = %.0fm2\n", i+1, width[i], i+1, heigh[i], i+1, area[i]);

        if (area[i] < average){
            counter += 1;
            printf("Area of %d is bellow the average\n", i+1);
        } else{
            printf("Area of %d is equal/above the average\n", i+1);
        }
        
    }

    printf("\n%d areas were bellow the average\n", counter);
    printf("%d areas were equal/above the average\n", N_LANDS - counter);

    return 0;
}