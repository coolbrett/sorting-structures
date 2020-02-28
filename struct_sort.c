/**
 * @author Brett Dale
 * @version 1.0 (2/28/2020)
 *
 * This C source file creates a collection of Contacts and sorts them by
 * last name first, then first name if last name's are the same.
 */

#include "struct_sort.h" /** Header file for the source file */

/**
 * This method eliminates all whitespace leading or trailing the string passed
 */
void trim(char *string) {
    if (string == NULL){
        perror("trim; null parameter");
        exit(-1);
    }else {
        char *ptr = string;
        int length = strlen(ptr);

        while (isspace(ptr[length - 1])) {
            ptr[--length] = 0;
        }
        while (*ptr && isspace(*ptr)) {
            ++ptr, --length;
        }
        memmove(string, ptr, length + 1);
    }
}

/**
 * This method copy's the Contact struct passed in and returns the copy
 *
 * @param contact contact to be copied
 * @return Copy of Contact struct passed
 */
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

/**
 * This method was used in the building process to display all contacts
 * in the Contact struct passed
 *
 * @param contacts contacts array
 * @param num number of elements in array
 */
void print_contacts(Contact contacts[], int num) {
    if (contacts == NULL || (void *) num == NULL) {
        perror("print_contacts; parameters are null");
        exit(-1);
    } else {
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
}

/**
 * This method sorts the Contact array passed in order of last name
 * first, then first name if last names are the same
 *
 * @param contacts contacts array
 * @param num number of elements in array passed
 */
void sort(Contact contacts[], int num) {
    if ((void *) num == NULL || contacts == NULL){
        perror("sort; parameters are null");
        exit(-1);
    }else{
    int EQ = 0;
    for (int i = 0; i < num; ++i) {
        for (int j = i + 1; j < num; ++j) {
            if (strcasecmp(contacts[i].last_name,
                    contacts[j].last_name) > EQ) {
                Contact temp = copy(contacts[j]);
                contacts[j] = contacts[i];
                contacts[i] = temp;
            } else if (strcasecmp(contacts[i].last_name,
                    contacts[j].last_name) == EQ) {
                if (strcasecmp(contacts[i].first_name,
                        contacts[j].first_name) > EQ) {
                    Contact temp = copy(contacts[j]);
                    contacts[j] = contacts[i];
                    contacts[i] = temp;
                }
            }
        }
    }
    }
}

/**
 * This method reads in file passed in and creates Contact structs that
 * eventually go into the contacts array passed
 * @param file file to be read from
 * @param contacts contacts array to place Contact structs
 * @return integer of elements placed into contacts array
 */
int read_file(FILE *file, Contact contacts[]) {
    if (file == NULL || contacts == NULL){
        perror("read_file; parameters are null");
        exit(-1);
    }else {
        char str[NUM];
        int i = 0;
        while (fgets(str, NUM, file) != NULL) {
            Contact contact;
            char *token = strtok(str, ",\t");
            if (token != NULL) {
                trim(token);
                strcpy(contact.first_name, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.last_name, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.address.street, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.address.city, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.address.state, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.address.zip, token);
                token = strtok(NULL, ",");
            }
            if (token != NULL) {
                trim(token);
                strcpy(contact.telephone, token);
            }
            contacts[i] = contact;
            i++;
        }
        return i;
    }
}

/**
 * This method writes the sorted contacts array passed in to the file passed in
 * @param output file to be written to
 * @param contacts array of Contact structs
 * @param num number of elements in contacts array
 */
void write_to_file(FILE *output, Contact contacts[], int num){
    if (output == NULL || contacts == NULL || (void *)num == NULL){

    }else {
        for (int i = 0; i < num; ++i) {
            fprintf(output, "%s,  ", contacts[i].first_name);
            fprintf(output, "%s,  ", contacts[i].last_name);
            fprintf(output, "%s,  ", contacts[i].address.street);
            fprintf(output, "%s,  ", contacts[i].address.city);
            fprintf(output, "%s,  ", contacts[i].address.state);
            fprintf(output, "%s,  ", contacts[i].address.zip);
            fprintf(output, "%s\n", contacts[i].telephone);
        }
    }
}

/**
 * Main method that runs the file
 * @param argc number of how many arguments were passed
 * @param argv array of command line arguments passed
 * @return 0
 */
int main(int argc, char *argv[]){
    if ((void *)argc == NULL || argv == NULL){
        perror("main; parameters are null");
        exit(-1);
    }else if(argc != 3){
        perror("main; Wrong amount of program arguments, "
               "needs <executable file> <contact text file> "
               "<text file to write sorted text file to");
        exit(-1);
    }else {
        FILE *file;
        FILE *output;
        Contact contacts[NAME];
        file = fopen(argv[1], "r");
        int num = read_file(file, contacts);
        sort(contacts, num);
        fclose(file);
        output = fopen(argv[2], "w");
        write_to_file(output, contacts, num);
        fclose(output);
        return (0);
    }
}