/*
        Name: book
        Description: I've done this homework all by myself
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book {
  char name[50];
  char author[20];
  char press[30];
  char date[10];
};
void sortbyName(struct book array[], int n);
int main() {
  int op, i, j, n, clear = 0;
  int total_line = 0;
  char
      temp_string[200]; /*used to calculate the lines in the original document*/
  char temp_str[200];   /*used to store the string that needed to be searched */
  struct book info[500];
  FILE *in, *out;
  /*Open the file now*/
  if ((in = fopen("books.txt", "r")) == NULL) {
    printf("Can't Open file books.txt!\n");
    return 1;
  }
  if ((out = fopen("ordered.txt", "w")) == NULL) {
    printf("Can't Open ordered.txt!\n");
    return 1;
  }
  /*firstly, calculate the total lines in the original document*/
  while (fgets(temp_string, 500, in) != NULL) {
    total_line++;
  }

  n = total_line;
  fseek(in, 0, SEEK_SET);

  for (i = 0; i < n; i++) {
    fscanf(in, "%s %s %s %s", info[i].name, info[i].author, info[i].press,
           info[i].date);
  }
  sortbyName(info, n);

  int loop = 1;
  while (loop == 1) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%s %s %s %s", info[n].name, info[n].author, info[n].press,
            info[n].date);
      n++;
      sortbyName(info, n);

    }

    else if (op == 2) {
      /*search for the relative books
                  have to find the objects and printed out on the screen
                  no operation to document */
      scanf("%s", temp_str);
      for (i = 0; i < n; i++) {
        if (strstr(info[i].name, temp_str) != NULL) {
          printf("%-50s%-20s%-30s%-10s\n", info[i].name, info[i].author,
                 info[i].press, info[i].date);
        }
      }
    }

    else if (op == 3) {
      scanf("%s", temp_str);
      for (i = 0; i < n;) {
        if (strstr(info[i].name, temp_str) != NULL) {
          /*let later array cover the former array that need to be deleted*/
          if (i == n - 1)
            n--;
          else {
            while (strstr(info[i].name, temp_str) != NULL) {
              for (j = i; j < n; j++) {
                info[j] = info[j + 1];
              }
              n--;
            }
          }
        }
        i++;
      }

    }

    else if (op == 0) {
      for (i = 0; i < n; i++) {
        fprintf(out, "%-50s%-20s%-30s%-10s\n", info[i].name, info[i].author,
                info[i].press, info[i].date);
      }
      fclose(out);
      loop = 0;
    }
  }

  fclose(in);

  return 0;
}

void sortbyName(struct book array[], int n) {
  int i, j;
  struct book tmp;
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++) {
      if (strcmp(array[i].name, array[j].name) > 0) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
}
