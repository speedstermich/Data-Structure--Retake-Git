#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET (26)
#define MAXN (50)
#define islow(ch) (ch <= 'z' && ch >= 'a')

int main() {
  int i, j, vis[ALPHABET];
  char ch, key[MAXN];

  scanf("%s", key);
  /* 建立密钥的加密映射并去重 */
  for (i = j = 0; key[i] != '\0'; ++i, ++j) {
    if (!vis[key[i] - 'a']) {
      key[j] = key[i];
    }
    vis[key[i] - 'a'] = 1;
  }
  /* 反序追加剩余字符 */
  for (i = 0; i < ALPHABET; ++i) {
    if (!vis[i]) {
      key[j] = i;
    }
    ++j;
  }
  ch = getchar();
  while (ch != EOF) {
    putchar(islow(ch) ? key[ch - 'a'] : ch);
    // ch = getchar();
  }
  return 0;
}
