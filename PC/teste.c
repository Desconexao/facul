#include <stdio.h>

void test1() {
    char *frase = {"Hello world"};
    printf("%s", frase);
}

void test2() {
    int jump[] = {0, 2, 3, 4, 1235};

    printf("%d", *(jump + 2));
}

int main(int argc, char *argv[]) {
    test2();
    return 0;
}
