#ifndef STR_UTILS_H
#define STR_UTILS_H

/* to_string macros for divisor */
#define DIV_BIN 2
#define DIV_DEC 10
#define DIV_HEX 16

void strrev(char* str);
void to_string(char* buffer, int n, int divisor);
char to_lower(char in);
char to_upper(char in);
char* str_to_lower(char* str);
char* str_to_upper(char* str);
unsigned int is_palindrome(const char* str);
unsigned int is_anagram(const char* left, const char* right);
void merge_sort(char* arr, int l, int r);

#endif 