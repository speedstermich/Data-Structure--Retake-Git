
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word_list {
  char word[26];
};
struct word_list word_block[3510];
struct index {
  char alpha;
  int start;
  int all;
};
struct index index_list[26];
#define NHASH 3001
#define MULT 37
unsigned int hash(char *str) {
  unsigned int h = 0;
  char *p;
  for (p = str; *p != '\0'; p++)
    h = MULT * h + *p;

  return h % NHASH;
}
typedef struct node {
  char word[26];
  struct node *link;
} LNode, *LinkList;
void order_search(struct word_list word_block[], char obj[]);
void bisearch(struct word_list word_block[], char obj[]);
void index_search(struct index index_list[], char obj[]);
void insert(LinkList list, char temp[]);

int total = 0;
int main() {
  FILE *in;
  in = fopen("dictionary3000.txt", "r");
  int i = 0, method, times = 0,
      loop = 0; /*i is the total number of all words, times marks times of
                   comparing in search*/
  char temp[26], obj[26];
  char head_letter = 'a';
  int j = 1, all1 = 0;
  int hash_value;
  LinkList list = NULL, p;
  LinkList hash_list[3002];
  for (loop = 0; loop < 3002; loop++) {
    list = (LinkList)malloc(sizeof(LNode));
    list->link = NULL;
    hash_list[loop] = list;
  }

  for (loop = 0; loop < 26; loop++) {
    index_list[loop].alpha = 'a' + loop;
    index_list[loop].all = 0;
    index_list[loop].start = 0;
  }
  index_list[0].alpha = 'a';
  index_list[0].start = 0;

  while (!feof(in)) {
    fscanf(in, "%s", &temp);
    strcpy(word_block[i].word, temp);

    index_list[temp[0] - 'a'].all++;
    if (temp[0] != head_letter) {
      head_letter++;
      index_list[temp[0] - 'a'].start = i;
    }

    hash_value = hash(temp); /*计算出它的哈希值*/
    if (hash_list[hash_value]->link == NULL) {
      p = hash_list[hash_value];
      strcpy(p->word, temp);
      p->link = NULL;
    } else if (hash_list[hash_value]->link != NULL) {
      insert(hash_list[hash_value], temp);
    }

    i++;
  }
  index_list['z' - 'a'].all--;

  total = i - 1;

  scanf("%s %d", &obj, &method);
  if (method == 1) /*order search*/
  {
    order_search(word_block, obj);
  } else if (method == 2) {
    bisearch(word_block, obj);
  } else if (method == 3) {
    index_search(index_list, obj);
  } else if (method == 4) {
    hash_value = hash(obj);
    p = hash_list[hash_value]; /*hash value is a head pointer*/
    times++;
    while (strcmp(p->word, obj) > 0 && p->link != NULL) {
      p = p->link;
      times++;
    }
    if (strcmp(p->word, obj) == 0) {
      printf("1 %d\n", times);
    } else {
      printf("0 %d\n", times + 1);
    }
  }

  fclose(in);
  return 0;
}

void order_search(struct word_list word_block[], char obj[]) {
  int i = 0, times = 0;
  for (i = 0; i <= 3500; i++) {
    times++;
    if (strcmp(obj, word_block[i].word) > 0)
      continue;

    else if (strcmp(obj, word_block[i].word) == 0) {
      printf("1 %d\n", times);
      break;
    } else {
      printf("0 %d\n", times);
      break;
    }
  }
}
void bisearch(struct word_list word_block[], char obj[]) {
  int low = 0, high = total - 1, mid, times = 0, find = 0;
  while (low <= high) {
    times++;
    mid = (low + high) / 2;
    if (strcmp(word_block[mid].word, obj) == 0) {
      printf("1 %d\n", times);
      find = 1;
      break;
    } else if (strcmp(word_block[mid].word, obj) < 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (find == 0) {
    printf("0 %d\n", times);
  }
}
void index_search(struct index index_list[], char obj[]) {
  int low = index_list[obj[0] - 'a'].start,
      high = low + index_list[obj[0] - 'a'].all - 1, mid, times = 0, find = 0;
  while (low <= high) {
    times++;
    mid = (low + high) / 2;
    if (strcmp(word_block[mid].word, obj) == 0) {
      printf("1 %d\n", times);
      find = 1;
      break;
    } else if (strcmp(word_block[mid].word, obj) < 0) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (find == 0) {
    printf("0 %d\n", times);
  }
}

void insert(LinkList list,
            char temp[]) /*大指针数组内的某个元素 是该链表的头结点*/
{
  LinkList p, r;
  r = list; /*wei zhi zhen */
  while (r->link != NULL) {
    r = r->link;
  }
  p = (LinkList)malloc(sizeof(LNode));
  strcpy(p->word, temp);
  p->link = NULL;
  r->link = p;
}
