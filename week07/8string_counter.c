//This program counts the number of occurences of a substring inside a text (like Ctrl + F)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXT_LENGTH 300
#define STRING_LENGTH 20

int countSubstring(char *text, char *substring){
    int text_size = strlen(text);
    int substring_size = strlen(substring);
    char *string_buffer = calloc(substring_size, sizeof(char));
    int i = 0, j;
    int n_substrings = 0;
    text[text_size] = '\0';

    printf("Substring_size: %d\n", substring_size);
    while(text[i] != '\0'){
        for(j = 0; j < substring_size; j++){
            if(j + i < text_size){
                string_buffer[j] = text[i + j];
            }
        }
        if(!strcmp(substring, string_buffer)){
            n_substrings++;
        }
        i++;
    }
    free(string_buffer);
    string_buffer = NULL;
    return n_substrings;
}

int main(){
    char text[TEXT_LENGTH+1] = "Insert here a text with a max size of TEXT_LENGTH characters to search the substrings. the algorithms are case sensitive and also count the substrings merged into another strings (like string 'car' inside 'nascar' or every 'a' in this text)";
    
    char string[STRING_LENGTH+1];
    puts("Enter the string:");
    scanf("%s", string);

    printf("Number of strings ocurrences: %d\n", countSubstring(text, string));
    return 0;
}