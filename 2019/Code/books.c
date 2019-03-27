#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books {
  char name[50];
  char author[20];
  char press[30];
  char year[10];
};

void sortbyName(struct books array[], int n) {
  int i, j;
  struct books tmp;
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      if (strcmp(array[i].name, array[j].name) > 0) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int op, i, j, n;    // variable declaration
  int total_line = 0; // total line number
  char temp_str[200];
  char search_tmp[200];
  struct books info[500]; // books List
  FILE *in, *out;

  /*Input file Handler*/
  if ((in = fopen("books.txt", "r")) == NULL) {
    printf("Can't open file");
    return 1;
  }

  if ((out = fopen("ordered.txt", "w")) == NULL) {
    printf("Write file failed");
    return 1;
  }

  /*count the lines of input*/
  while (fgets(temp_str, 500, in) != NULL) {
    total_line++;
  }

  n = total_line;
  fseek(in, 0, SEEK_SET);

  // to get from the text file and store it to book info database
  for (i = 0; i < n; i++) {
    fscanf(in, "%s %s %s %s", info[i].name, info[i].author, info[i].press,
           info[i].year);
  }

  sortbyName(info, n);

  int loop = 1; // for decide loop

  while (loop == 1) {
    scanf("%d", &op);

    switch (op) {
    case 1:
      scanf("%s %s %s %s", info[n].name, info[n].author, info[n].press,
            info[n].year);
      n++;
      sortbyName(info, n);
      break;
    case 2:
      /*search for book and print to output*/
      scanf("%s", search_tmp);
      for (i = 0; i < n; i++) {
        if (strstr(info[i].name, search_tmp) != NULL) {
          printf("%-50s%-20s%-30s%-10s\n", info[i].name, info[i].author,
                 info[i].press, info[i].year);
        }
      }
      break;
    case 3:
      scanf("%s", search_tmp);
      for (i = 0; i < n;) {
        if (strstr(info[i].name, search_tmp) != NULL) {
          // let later array cover wants to deleted
          if (i == n - 1)
            n--;
          else {
            while (strstr(info[i].name, search_tmp) != NULL) {
              for (j = i; j < n; j++) {
                info[j] = info[j + 1];
              }
              n--;
            }
          }
        }
        i++;
      }
      break;
    case 0:
      for (i = 0; i < n; i++) {
        fprintf(out, "%-50s%-20s%-30s%-10s\n", info[i].name, info[i].author,
                info[i].press, info[i].year);
      }
      fclose(out);
      loop = 0;
    }
  }
  fclose(in);
  return 0;
}
