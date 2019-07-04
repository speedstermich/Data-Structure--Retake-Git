#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 500

typedef struct Routes {
  int num;
  int vera;
  int verb;
  int weight;
} Routes;

Routes road[MAXLINE];
int pre[MAXLINE];
int ans[MAXLINE];
int use = 0;

void SelectionSort_Road(int num, Routes r[]);
void SelectionSort(int num, int a[]);
int find(int root);
int kruskal(int RouteNum);

int main(void) {
  int VertexNum, RouteNum, MinUse;
  int i;

  scanf("%d %d", &VertexNum, &RouteNum);
  for (i = 0; i < MAXLINE; i++)
    pre[i] = i;
  for (i = 0; i < RouteNum; i++)
    scanf("%d %d %d %d", &road[i].num, &road[i].vera, &road[i].verb,
          &road[i].weight);

  MinUse = kruskal(RouteNum);
  SelectionSort(use, ans);

  printf("%d\n", MinUse);
  for (i = 0; i < use - 1; i++)
    printf("%d ", ans[i]);
  printf("%d\n", ans[i]);

  return 0;
}
void SelectionSort_Road(int num, Routes r[]) {
  int i, j, min;
  Routes temp;

  for (i = 0; i < num - 1; i++) {
    min = i;
    for (j = i + 1; j < num; j++)
      if (r[j].weight < r[min].weight)
        min = j;
    if (min != i) {
      temp = r[min];
      r[min] = r[i];
      r[i] = temp;
    }
  }
  return;
}
void SelectionSort(int num, int a[]) {
  int i, j, min, temp;

  for (i = 0; i < num - 1; i++) {
    min = i;
    for (j = i + 1; j < num; j++)
      if (a[j] < a[min])
        min = j;
    if (min != i) {
      temp = a[min];
      a[min] = a[i];
      a[i] = temp;
    }
  }
  return;
}
int find(int root) {
  int child, temp;

  child = root;
  while (root != pre[root])
    root = pre[root];
  while (child != root) {
    temp = pre[child];
    pre[child] = root;
    child = temp;
  }

  return root;
}
int kruskal(int RouteNum) {
  int i, j;
  int sum = 0;

  SelectionSort_Road(RouteNum, road);

  for (i = 0, j = 0; i < RouteNum; i++) {
    int roota = find(road[i].vera);
    int rootb = find(road[i].verb);

    if (roota != rootb) {
      sum += road[i].weight;
      ans[j++] = road[i].num;
      use++;
      pre[roota] = rootb;
    }
  }
  return sum;
}
