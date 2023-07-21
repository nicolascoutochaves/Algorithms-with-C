#include <stdio.h>

void decompose(int number, int amount, int *thous, int *hund, int *ten, int *un){
    

}

int amnt(int number){
    float res = number;
    int c = 0;
    do{
       res /= 10;
        c++;
    } while (res > 1);
    return c; 
}
int main(){
    int number, amount;
    int *thous, *hund, *ten, *un;
    printf("Enter the number: ");
    scanf("%d", &number);
    amount = amnt(number);
     decompose(number, amount, thous, hund, ten, un);
    return 0;
}