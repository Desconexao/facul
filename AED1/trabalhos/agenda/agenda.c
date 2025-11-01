#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SKETCH SIZES
#define TEMP_NAME_SIZE 50
#define TEMP_EMAIL_SIZE 50

// pBuffer [METADATA][DATA][SKETCH]
// METADATA MACROS
#define BUFFER_OPTION_PTR(buffer) ((int *)(buffer))
#define BUFFER_OPTION_VAL(buffer) (*(BUFFER_OPTION_PTR(buffer)))

#define BUFFER_PEOPLE_COUNT_PTR(buffer)                                        \
    ((int *)((char *)(buffer) + sizeof(int)))
#define BUFFER_PEOPLE_COUNT_VAL(buffer) (*(BUFFER_PEOPLE_COUNT_PTR(buffer)))

// #define BUFFER_PEOPLE_PTR(buffer)                                              \
    ((char *)BUFFER_OPTION_PTR(buffer) + 2 * sizeof(int))
#define METADATA_SIZE (2 * sizeof(int))

// SKETCH MACROS
#define TEMP_COUNT_PTR(buffer) ((int *)((char *)(buffer) + METADATA_SIZE))
#define TEMP_COUNT_VAL(buffer) (*(TEMP_COUNT_PTR(buffer)))

#define TEMP_NAME_PTR(buffer)                                                  \
    ((char *)((char *)(buffer) + METADATA_SIZE + sizeof(int)))

#define TEMP_AGE_PTR(buffer)                                                   \
    ((int *)((char *)(buffer) + METADATA_SIZE + sizeof(int) +                  \
             TEMP_NAME_SIZE * sizeof(char)))
#define TEMP_AGE_VAL(buffer) (*(TEMP_AGE_PTR(buffer)))

#define TEMP_EMAIL_PTR(buffer)                                                 \
    ((char *)((char *)(TEMP_AGE_PTR(buffer)) + sizeof(int)))

#define SKETCH_SIZE                                                            \
    (sizeof(int) + TEMP_NAME_SIZE * sizeof(char) + sizeof(int) +               \
     TEMP_EMAIL_SIZE * sizeof(char))

// DATA MACRO
#define BUFFER_PEOPLE_PTR(buffer)                                              \
    ((char *)((char *)(buffer) + METADATA_SIZE + SKETCH_SIZE))

// NEW PERSON MACROS
/*
#define PERSON(buffer, idx) (BUFFER_PEOPLE_PTR(buffer) + idx * PERSON_SIZE)

#define PERSON_NAME_PTR(buffer, idx) (PERSON(buffer, idx))

#define PERSON_AGE_PTR(buffer, idx)                                            \
    (int *)(PERSON_NAME_PTR(buffer, idx) + NAME_SIZE)
#define PERSON_AGE_VAL(buffer, idx) (*(PERSON_AGE_PTR(buffer, idx)))

#define PERSON_EMAIL_PTR(buffer, idx)                                          \
    ((char *)(PERSON_AGE_PTR(buffer, idx) + 1))
*/
// name -> age -> email

// main functions
void addPerson(void **pBuffer);
void removePerson(void **pBuffer);
void searchPerson(void **pBuffer);
void listPeople(void *pBuffer);

// aux functions

void test();

int main() {
    void *pBuffer = NULL;
    // [int *option]
    // [int *peopleCount]
    // [char *people] = [int *age][int *nameLen][char
    // *name][int*emailLen][char*email]
    // [int *tempCount]
    // [char *tempName]
    // [char *tempAge]
    // [char *tempEmail]

    pBuffer = malloc(METADATA_SIZE + SKETCH_SIZE);

    if (!pBuffer) {
        printf("Failed to allocate buffer.\n");
        return 0;
    }

    memset(pBuffer, 0, METADATA_SIZE + SKETCH_SIZE);

    // BUFFER_OPTION_VAL(pBuffer) = 0;
    // BUFFER_PEOPLE_COUNT_VAL(pBuffer) = 0;

    while (BUFFER_OPTION_VAL(pBuffer) != 5) {
        printf("1 - Add Person\n2 - Remove Person\n3 - Search Person\n4 - List "
               "People\n5 - Exit\n");
        printf("Choose a option: ");
        if (scanf(" %d", BUFFER_OPTION_PTR(pBuffer)) != 1) {
            BUFFER_OPTION_VAL(pBuffer) = 0;
        }
        // scanf(" %d", BUFFER_OPTION_PTR(pBuffer));

        switch (BUFFER_OPTION_VAL(pBuffer)) {
        case 1:
            addPerson(&pBuffer);
            break;
        case 2:
            // removePerson(&pBuffer);
            break;
        case 3:
            // searchPerson(&pBuffer);
            break;
        case 4:
            // listPeople(pBuffer);
            break;
        case 5:
            break;
        default:
            printf("Isn't a valid option... Try again.\n");
        }
    }

    free(pBuffer);

    return 0;
}

void addPerson(void **pBuffer) {
    BUFFER_PEOPLE_COUNT_VAL(*pBuffer)++;

    // stack????

    printf("Name: ");
    scanf(" %49[^\n]", TEMP_NAME_PTR(*pBuffer));
    printf("Age: ");
    scanf("%d", TEMP_AGE_PTR(pBuffer));
    printf("Email: ");
    scanf(" %49[^\n]", TEMP_EMAIL_PTR(*pBuffer));

    printf("%s\n", TEMP_NAME_PTR(*pBuffer));
    printf("%d\n", TEMP_AGE_VAL(*pBuffer));
    printf("%s\n", TEMP_EMAIL_PTR(*pBuffer));

    *pBuffer = realloc(*pBuffer, METADATA_SIZE + SKETCH_SIZE);
    if (!(*pBuffer)) {
        printf("Failed to add person.");
        return;
    }
}

void removePerson(void **pBuffer) {}
