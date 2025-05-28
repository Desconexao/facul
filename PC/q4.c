#include <ctype.h>
#include <stdio.h>
#include <string.h>

void ex2() {
  int matriz[3][3];
  int i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void ex4() {
  char s1[50] = "jack", s2[50] = "jill", s3[50], *sptr;

  printf("%c%s ", toupper(s1[0]), &s1[1]);
  printf("%s ", strcpy(s3, s2));
  printf("%s ", strcat(strcat(strcpy(s3, s1), " and "), s2));
  printf("%llu ", strlen(s1) + strlen(s2));
  printf("%llu ", strlen(s3));
}

int main() {
  // ex2
  ex4();
}
