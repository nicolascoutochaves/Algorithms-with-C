#include <stdio.h>
#define MAX_CHAR 30
int main(){
    char s1[MAX_CHAR+1] = {0}, s2[MAX_CHAR+1] = {0}, s3[2*MAX_CHAR+1] = {0};
    int i = 0, j;
    printf("Enter the string 1: ");
    scanf("%s", s1);
    printf("Enter the string 2: ");
    scanf("%s", s2);

    do{
        s3[i] = s1[i];
        i++;
    } while(s1[i] != '\0');
    j = i;
   /*  s3[j] = ' '; //uncoment if you want to add a space between the strings
    j++; */
    i = 0;

    do{
        s3[j] = s2[i];
        j++;
        i++;
    } while(s2[i] != '\0');

    
    printf("%s\n", s3);
    
    
    return 0;
}