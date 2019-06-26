#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  unsigned int id;
  char name[64];
  char addr[64];
} Student;

char to_lower(char in) {
  if (in > 0x5A) return in;
  else return in + 0x20;
}

char to_upper(char in) {
  if (in < 0x61) return in;
  else return in - 0x20;
}

Student* create_student(unsigned int id, char name[64], char addr[64]) {
  Student* stnt = malloc(sizeof(Student));
  memset(stnt, 0, sizeof(Student));
  stnt->id = id;
  strcpy(stnt->name, name);
  strcpy(stnt->addr, addr);
  return (Student*)stnt;
}

void free_student(Student* stnt) {
  free(stnt);
}

void println(const char* buf) {
  printf("%s\n", buf);
}

unsigned int is_palindrome(const char* str) {
  int len = strlen(str);
  
  if (len <= 3) return 0;

  double m = floor(strlen(str) * .5f);
  for (int i = 0, j = len - 1; i <= m && j >= m; i++, j--) {
    if (to_lower(str[i]) != to_lower(str[j])) {
      return 0;
    }
  }

  return 1;
}