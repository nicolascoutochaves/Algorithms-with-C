#include <stdio.h>
#define MAX_CHAR 30
int main(){
    char s1[MAX_CHAR+1] = {0}, s2[MAX_CHAR+1] = {0};
    int i = 0;
    printf("Enter the string to be copied: ");
    scanf("%s", s1);
    do{
        s2[i] = s1[i];
        i++;
    } while(s1[i] != '\0');
    
    printf("%s\n", s2);
    
    
    return 0;
}