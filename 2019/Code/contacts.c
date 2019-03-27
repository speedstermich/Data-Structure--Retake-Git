#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Contacts {
  char sName[20];
  char sTel[11];
};

void sortbyName(struct Contacts array[], int n) {
  int i, j;
  struct Contacts tmp;
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      if (strcmp(array[i].sName, array[j].sName) > 0) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main() {
  struct Contacts MyContact[500];
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", MyContact[i].sName, MyContact[i].sTel);
  }

  sortbyName(MyContact, n);
  fflush(stdin);
  for (i = 0; i < n; i++) {
    printf("%s %s\n", MyContact[i].sName, MyContact[i].sTel);
    fflush(stdin);
  }
}
