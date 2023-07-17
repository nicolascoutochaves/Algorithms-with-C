#include <stdio.h>
#define MAX_CHAR 30
int main(){
    char s[MAX_CHAR+1] = {0};
    int i = 0, c = 0;
    printf("Enter the string: ");
    scanf("%s", s);

    while(s[i] != '\0'){
        c++;
        i++;
    }

    
    printf("length of '%s' = %d\n", s, c);
    
    
    return 0;
}