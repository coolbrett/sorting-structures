#include <stdio.h>
#include <stdlib.h>
#include "struct_sort.h"

void sort(struct Contacts contacts) {

}

int main(int argc, char *argv[]){
    //read file and keep adding to contacts array
    //FILE HAS TO COME FROM COMMAND LINE

    //reading file
    FILE *file;
    int c;
    Contacts contacts;

    //printf("%s", "contacts.txt");
    file = fopen(argv[1], "r");
    while (1){
        c = fgetc(file);
        Contact person;
        
        if(feof(file)){
            break;
        }
        printf("%c", c);
    }
    fclose(file);
    return (0);
}