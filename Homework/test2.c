#include<stdio.h>

struct student
{
 int no;
 char name[20];
 char sex;
 struct
 {
  int year;
  int month;
  int day;
 }birth;
};

int main(int argc, char const *argv[]) {

struct student s;
s.birth.year=1988; s.birth.month=5; s.birth.day=10;
printf("%d\n", s.birth.year );
return 0;
}
