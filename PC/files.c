#include <stdio.h>
#include <stdlib.h>
#define MAX_C 40

int main(int argc, char *argv[]) {
    char linhas[MAX_C];
    FILE *fp;

    if ((fp = fopen("file.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo %s\n", "file.txt");
        exit(1);
    }

    while (fgets(linhas, MAX_C, fp) != NULL) {
        printf("%s", linhas);
    }

    fclose(fp);
    return 0;
}
