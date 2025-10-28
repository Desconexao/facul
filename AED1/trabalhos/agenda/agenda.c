#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 50
#define EMAIL_SIZE 50

void addPerson(void **pBuffer);
void removePerson(void **pBuffer);
void searchPerson(void **pBuffer);
void listPeople(void **pBuffer);

int main() {
    void *pBuffer = NULL;
    // [int option][void* head][void* current][void* previous][char
    // searchName[NAME_SIZE]]
    // void *pNewPerson = NULL; void *pHead = NULL; void
    // *pCurrent = NULL; void *pPrevius = NULL; void *pTemp = NULL; int
    // *pOption;

    pBuffer = malloc(sizeof(int) + 4 * sizeof(void *));

    if (!pBuffer) {
        printf("can't allocate buffer.\n");
        return 0;
    }

    *(int *)pBuffer = 0;
    *(void **)((char *)pBuffer + sizeof(int)) = NULL;
    *(void **)((char *)pBuffer + sizeof(int) + sizeof(void *)) = NULL;
    *(void **)((char *)pBuffer + sizeof(int) + 2 * sizeof(void *)) = NULL;
    *(void **)((char *)pBuffer + sizeof(int) + 3 * sizeof(void *)) = NULL;

    while (*(int *)pBuffer != 5) {
        printf("1 - Add Person\n2 - Remove Person\n3 - Search Person\n4 - List "
               "People\n5 - Exit\n");
        printf("Choose a option: ");
        scanf("%d", (int *)pBuffer);

        switch (*(int *)pBuffer) {
        case 1:
            addPerson(&pBuffer);
            break;
        case 2:
            removePerson(&pBuffer);
            break;
        case 3:
            searchPerson(&pBuffer);
            break;
        case 4:
            listPeople(&pBuffer);
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
