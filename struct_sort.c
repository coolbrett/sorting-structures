#include <stdio.h>
#include <stdlib.h>
#include "struct_sort.h"
#include <ctype.h>

void trim(char *string) {
    char *ptr = string;
    int length = strlen(ptr);

    while(isspace(ptr[length - 1])){
        ptr[--length] = 0;
    }
    while(*ptr && isspace(*ptr)){
        ++ptr, --length;
    }

    memmove(string, ptr, length + 1);
}

void sort(Contacts contacts) {

}

int main(int argc, char *argv[]){
    //read file and keep adding to contacts array
    //FILE HAS TO COME FROM COMMAND LINE

    //reading file
    FILE *file;
    FILE *output;
    Contacts contacts;

    file = fopen(argv[1], "r");
    char str[NUM];
    while (fgets(str, NUM, file) != NULL){
        Contact contact;
        char *token = strtok(str, ",\t");
        while(token != NULL) {
            trim(token);
            contact.first_name = str;
            printf("%c", contact.first_name);
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return (0);
}