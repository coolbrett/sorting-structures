#include <stdio.h>
#include <string.h>
#define NUM 100
#define STREET 30
#define NAME 20
#define STATE 3
#define ZIP 6
#define TELEPHONE 13


typedef struct {
    char street[STREET];
    char city[STREET];
    char state[STATE];
    char zip[ZIP];
}Address;

typedef struct {
    char *first_name;
    char *last_name;
    Address address;
    char *telephone;
}Contact;

typedef struct {
    Contact contacts[NAME];
}Contacts;