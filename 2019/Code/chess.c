#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define right 'r'
#define lower 'l'
#define lower_right 'i'
#define lower_left 'e'
#define none 'o'
int table[19][19];

int hit_space(int x, int y, char vec) {
  if (vec == right) {
    if (x - 1 >= 0 && table[x - 1][y] == 0)
      return 1;
    if (x + 4 < 19 && table[x + 4][y] == 0)
      return 1;
  }

  if (vec == lower) {
    if (y - 1 >= 0 && table[x][y - 1] == 0)
      return 1;
    if (y + 4 < 19 && table[x][y + 4] == 0)
      return 1;
  }

  if (vec == lower_right) {
    if (x - 1 >= 0 && y - 1 >= 0 && table[x - 1][y - 1] == 0)
      return 1;
    if (x + 4 < 19 && y + 4 < 19 && table[x + 4][y + 4] == 0)
      return 1;
  }

  if (vec == lower_left) {
    if (x - 1 >= 0 && y + 1 < 19 && table[x - 1][y + 1] == 0)
      return 1;
    if (x + 4 < 19 && y - 4 >= 0 && table[x + 4][y - 4] == 0)
      return 1;
  }

  return 0;
}

int tetra_colinear_on_vec(int x, int y, char vec) {
  if (vec == right) {
    if (x + 3 < 19 && table[x][y] == table[x + 1][y] &&
        table[x + 1][y] == table[x + 2][y] &&
        table[x + 2][y] == table[x + 3][y])
      return 1;
  }

  if (vec == lower) {
    if (y + 3 < 19 && table[x][y] == table[x][y + 1] &&
        table[x][y + 1] == table[x][y + 2] &&
        table[x][y + 2] == table[x][y + 3])
      return 1;
  }

  if (vec == lower_right) {
    if (x + 3 < 19 && y + 3 < 19 && table[x][y] == table[x + 1][y + 1] &&
        table[x + 1][y + 1] == table[x + 2][y + 2] &&
        table[x + 2][y + 2] == table[x + 3][y + 3])
      return 1;
  }

  if (vec == lower_left) {
    if (x + 3 < 19 && y - 3 >= 0 && table[x][y] == table[x + 1][y - 1] &&
        table[x + 1][y - 1] == table[x + 2][y - 2] &&
        table[x + 2][y - 2] == table[x + 3][y - 3])
      return 1;
  }

  return 0;
}

char tetra_colinear(int x, int y) {
  char vec;

  vec = right;
  if (tetra_colinear_on_vec(x, y, vec))
    return vec;

  vec = lower;
  if (tetra_colinear_on_vec(x, y, vec))
    return vec;

  vec = lower_right;
  if (tetra_colinear_on_vec(x, y, vec))
    return vec;

  vec = lower_left;
  if (tetra_colinear_on_vec(x, y, vec))
    return vec;

  return none;
}

int checkmate() {
  int i, j;
  for (i = 0; i < 19; i++)
    for (j = 0; j < 19; j++) {
      if (table[i][j] == 1) {
        char vec = tetra_colinear(i, j);
        if (vec == right || vec == lower || vec == lower_right ||
            vec == lower_left) {
          if (hit_space(i, j, vec)) {
            printf("1:%d,%d\n", i + 1, j + 1);
            return 1;
          }
        }
      }
    }

  for (i = 0; i < 19; i++)
    for (j = 0; j < 19; j++) {
      if (table[i][j] == 2) {
        char vec = tetra_colinear(i, j);
        if (vec == right || vec == lower || vec == lower_right ||
            vec == lower_left) {
          if (hit_space(i, j, vec)) {
            printf("2:%d,%d\n", i + 1, j + 1);
            return 1;
          }
        }
      }
    }

  return 0;
}

int main() {
  int i, j;
  for (i = 0; i < 19; i++)
    for (j = 0; j < 19; j++)
      scanf("%d", &table[i][j]);
  if (!checkmate())
    printf("No\n");
  return 0;
}
