#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int id;
  char name[64];
  char addr[64];
} Student;

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