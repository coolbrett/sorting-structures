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

Contact copy(Contact contact){
    Contact temp;
    strcpy(temp.first_name, contact.first_name);
    strcpy(temp.last_name, contact.last_name);
    strcpy(temp.address.city, contact.address.city);
    strcpy(temp.address.street, contact.address.street);
    strcpy(temp.address.state, contact.address.state);
    strcpy(temp.address.zip, contact.address.zip);
    strcpy(temp.telephone, contact.telephone);
    return temp;
}

void printContacts(Contact contacts[], int num){
    int i = 0;
    while (i < num) {
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

void sort(Contact contacts[], int num) {
    int RIGHT = 1;
    int EQ = 0;
    for (int i = 0; i < num; ++i) {
        for (int j = i + 1; j < num; ++j) {
            //-1 is left bigger, 1 is right bigger, 0 means equal
            if (strcasecmp(contacts[i].first_name, contacts[j].first_name) > EQ){
                Contact temp = copy(contacts[j]);
                contacts[j] = contacts[i];
                contacts[i] = temp;
            }
            else if (strcasecmp(contacts[i].first_name, contacts[j].first_name) == EQ){
                if (strcasecmp(contacts[i].last_name, contacts[j].last_name) > EQ){
                    Contact temp = copy(contacts[j]);
                    contacts[j] = contacts[i];
                    contacts[i] = temp;
                }
            }
        }
    }
}

int readFile(FILE *file, Contact contacts[]) {
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
    return i;
}

int main(int argc, char *argv[]){
    FILE *file;
    FILE *output;
    Contact contacts[NAME];
    file = fopen(argv[1], "r");
    int num = readFile(file, contacts);
    printf("%s\n", "\n[BEFORE SORT]\n-------------------------------");
    printContacts(contacts, num);
    sort(contacts, num);
    printf("%s\n", "\n[AFTER SORT]\n-------------------------------");
    printContacts(contacts, num);
    fclose(file);
    return (0);
}
