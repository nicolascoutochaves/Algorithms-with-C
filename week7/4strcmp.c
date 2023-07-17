#include <stdio.h>
#define MAX_CHAR 30
int main(){
    char s1[MAX_CHAR+1] = {0}, s2[MAX_CHAR+1] = {0};
    int i = 0, j = 0;
    printf("Enter the string 1: ");
    scanf("%s", s1);
    printf("Enter the string 2: ");
    scanf("%s", s2);

    do{
        if (s1[i] > s2[i]){
            j++;
        } else if (s1[i] < s2[i]){
            j--;
        }
        i++;
    } while(s1[i] != '\0' || s2[i] != '\0');


    if(j > 0){
        printf("s1 > s2\n");
        printf("%d\n", j);
    } else if (j < 0){
        printf("s1 < s2\n");
        printf("%d\n", j);
    } else{
        printf("s1 == s2\n");
    }
    
    
   


    
    
    return 0;
}