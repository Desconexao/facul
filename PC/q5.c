#include <stdio.h>

void ex4() {
    int vet[] = {4, 9, 12};
    int i, *ptr;
    ptr = vet;
    for (i = 0; i < 3; i++)
        printf("%d ", (*ptr)++);
}

void ex5() {
    int a, b, *p1, *p2;

    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;
    printf("%d %d\n", *p1, *p2);
    printf("%d %d\n", a, b);
}

int main() {
    // ex4();
    ex5();
}
