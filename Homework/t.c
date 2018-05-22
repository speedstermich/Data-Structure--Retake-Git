#include <stdio.h>
#include <ctype.h>

char getWord(char *buf) {
    int c = 0;
    while((c = getchar()) != EOF && !isalpha(c)) {
    }
    if(c == EOF) {
        return 0;
    }
    while(isalpha(c)) {
        *buf = tolower(c);
        ++buf;
        c = getchar();
    }
    *buf = 0;
    return 1;
}

int main() {
    static char buf[1024];
    while(getWord(buf)) {
        printf("%s\n", buf);
    }
    return 0;
}
