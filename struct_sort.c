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

void sort(Contact contacts[]) {

}

void readFile(FILE *file){
    Contact contacts[NAME];
    char str[NUM];
    int i = 0;
    while (fgets(str, NUM, file) != NULL){
        Contact contact;
        char *token = strtok(str, ",\t");
        if (token != NULL) {
            trim(token);
            strcpy(contact.first_name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL){
            trim(token);
            strcpy(contact.last_name, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL){
            trim(token);
            strcpy(contact.address.street, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL){
            trim(token);
            strcpy(contact.address.city, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL){
            trim(token);
            strcpy(contact.address.state, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL){
            trim(token);
            strcpy(contact.address.zip, token);
            token = strtok(NULL, ",");
        }
        if(token != NULL){
            trim(token);
            strcpy(contact.telephone, token);
        }
        contacts[i] = contact;
        i++;
    }
}

int main(int argc, char *argv[]){
    FILE *file;
    FILE *output;

    file = fopen(argv[1], "r");
    readFile(file);
    fclose(file);
    return (0);
}