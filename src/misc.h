#ifndef MISC_H
#define MISC_H

typedef struct {
  unsigned int id;
  char name[64];
  char addr[64];
} Student;

Student* create_student(unsigned int id, char name[64], char addr[64]);
void free_student(Student* stnt);

#endif 