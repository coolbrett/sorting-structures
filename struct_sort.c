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

void printContacts(Contact contacts[]){
    int i = 0;
    while (i <= sizeof(contacts)) {
        printf("%s ", contacts[i].first_name);
        printf("%s ", contacts[i].last_name);
        printf("%s ", contacts[i].address.street);
        printf("%s ", contacts[i].address.city);
        printf("%s ", contacts[i].address.state);
        printf("%s ", contacts[i].address.zip);
        printf("%s\n\n", contacts[i].telephone);
        i++;
    }
    printf("%s\n", "-------------------------------");
}

void sort(Contact contacts[]) {
    int RIGHT = 1;
    int EQ = 0;
    for (int i = 0; i <= sizeof(contacts); ++i) {
        for (int j = i + 1; j <= sizeof(contacts); ++j) {
            //-1 is left bigger, 1 is right bigger, 0 means equal
            if (strcmpi(contacts[i].first_name, contacts[j].first_name) == RIGHT){
                char temp[NAME];
                strcpy(temp, contacts[j].first_name);
                strcpy(contacts[j].first_name, contacts[i].first_name);
                strcpy(contacts[i].first_name, temp);
            }
            else if (strcmpi(contacts[i].first_name, contacts[j].first_name) == EQ){
                /*char temp[NAME];
                strcpy(temp, contacts[j].last_name);
                strcpy(contacts[j].last_name, contacts[i].last_name);
                strcpy(contacts[i].last_name, temp);*/
            }
        }
    }
}

void readFile(FILE *file, Contact contacts[]) {
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
    Contact contacts[NAME];
    file = fopen(argv[1], "r");
    readFile(file, contacts);
    printf("%s\n", "\n[BEFORE SORT]\n-------------------------------");
    printContacts(contacts);
    sort(contacts);
    printf("%s\n", "\n[AFTER SORT]\n-------------------------------");
    printContacts(contacts);
    fclose(file);
    return (0);
}