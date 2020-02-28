/**
 * @author Brett Dale
 * @version 1.0 (2/28/2020)
 *
 * This file is the header file for the C source file struct_sort.c
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM 100 /** Constant for reading file in */
#define STREET 30 /** Constant for Street and City char arrays */
#define NAME 20 /** Constant for First and Last name char arrays */
#define STATE 3 /** Constant for State */
#define ZIP 6 /** Constant for Zip code */
#define TELEPHONE 13 /** Constant for Telephone */

typedef struct {
    char street[STREET]; /** Field for street name */
    char city[STREET]; /** Field for city name */
    char state[STATE]; /** Field for state acronym */
    char zip[ZIP]; /** Field for Zip code */
}Address;

typedef struct {
    char first_name[NAME]; /** Field for first name */
    char last_name[NAME]; /** Field for last name */
    Address address; /** Field for address struct */
    char telephone[TELEPHONE]; /** Field for telephone number */
}Contact;

void trim(char *string);

Contact copy(Contact contact);

void print_contacts(Contact contacts[], int num);

void sort(Contact contacts[], int num);

int read_file(FILE *file, Contact contacts[]);

void write_to_file(FILE *output, Contact contacts[], int num);