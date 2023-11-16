#include <stdio.h>

void Convert(int num, int base){
    int mod = num % base; //Calculates the remainder of the division of num by base
    if(num >= base)
        Convert((num - mod)/base, base);
    
    if(base >= 16)
        printf("%3X", mod);
    else printf("%3d", mod);
}

int main(){
    int decimal;
    int base;
    
    printf("Enter the decimal number to convert: ");
    scanf("%d", &decimal);

    printf("Enter the base: ");
    scanf("%d", &base);

    Convert(decimal, base);
    printf("\n");
    return 0;
}