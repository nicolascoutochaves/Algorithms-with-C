/* This program just takes a reference value and compare to the products amounts and print it on the screen*/

#include <stdio.h>
int main(){
    int refvalue, productcode, pamount; //input
    int greater = 0, less = 0, equal = 0; //output
    int i = 1; //control

    printf("Inventory control. Type '0' to stop the program.\n\n");

    printf("Insert the reference value for the product amount: ");
    scanf("%d", &refvalue);

    do{
        printf("\nInsert the product %d numeric code: ", i);
        scanf("%d", &productcode);
        
        if (productcode != 0){

            printf("Insert the amount of the product %d: ", i);
            scanf("%d", &pamount);

            if(pamount > refvalue){
                greater += 1;
            } else if(pamount < refvalue){
                less += 1; 
            } else {
                equal += 1;
            }
        }

        i++;

    } while (productcode != 0);

    printf("\n%d products are greater than the reference value\n", greater);

    printf("%d products are less than the reference value\n", less);

    printf("%d products are equal than the reference value\n", equal);

    return 0;
}