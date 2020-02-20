#include <stdio.h>
#include <string.h>
#define NUM_CONSTANT 100
#define STATE_CONSTANT 3
#define TELEPHONE_CONSTANT 12
#define ZIP_CONSTANT 5

typedef struct Contact{
    char *first_name[NUM_CONSTANT];
    char *last_name[NUM_CONSTANT];
    char *street[NUM_CONSTANT];
    char *city[NUM_CONSTANT];
    char *state[STATE_CONSTANT];
    int *zip[ZIP_CONSTANT];
    char *telephone[TELEPHONE_CONSTANT];
}Contact;

typedef struct Contacts {
    struct Contact contacts[NUM_CONSTANT];
}Contacts;