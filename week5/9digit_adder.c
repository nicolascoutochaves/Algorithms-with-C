#include <stdio.h>
int main(){
    int number;
    int sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &number);

    while (number > 0)
    {
        digit = number % 10;
        //printf("\nDigit = %d\n", digit);

        //printf("%d + %d = ", sum, digit);
        sum += digit;
        //printf("%d\n", sum);

        number /= 10;
        //printf("Number = %d\n", number);
    }
    
    printf("\nThe sum is = %d\n", sum);
    return 0;
}