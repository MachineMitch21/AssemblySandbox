#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char* str) {
	int len = strlen(str);
	int m = len * .5f;
	for (int i = 0; i < m; i++) {
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

void to_string(char* buffer, int n, int divisor) {
	int d = 0;
	int count = 0;
	while ((d = n % divisor) != 0) {
		buffer[count++] = d + 0x30;
		n/=divisor;
	}
	strrev(buffer);
	buffer[count] = '\0';
}

char to_lower(char in) {
  if ((in >= 0x61 && in <= 0x7A) || !(in >= 0x41 && in <= 0x5A)) {
		return in;
	}
  
	return in + 0x20;
}

char to_upper(char in) {
  if ((in >= 0x41 && in <= 0x5A) || !(in >= 0x61 && in <= 0x7A)) {
		return in;
	}
  
	return in - 0x20;
}

char* str_to_lower(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		str[i] = to_lower(str[i]);
    i++;
	}
  return str;
}

char* str_to_upper(char* str) {
	int i = 0; 
	while (str[i] != '\0') {
		str[i] = to_upper(str[i]);
	}
  return str;
}

unsigned int is_palindrome(const char* str) {
  int len = strlen(str);
  
  if (len <= 3) return 0;

  // This is an undefined reference to floor when using the above 'len' variable
  // Why?  I do not know... :(
  // double m = floor((double)len * .5f);  
  int m = len * .5f;
  for (int i = 0; i <= m; i++) {
    if (to_lower(str[i]) != to_lower(str[len - 1 - i])) {
      return 0;
    }
  }

  return 1;
}

unsigned int is_anagram(const char* left, const char* right) {
	char temp_l[32], temp_r[32];
  memset(temp_l, 0, 32);
  memset(temp_r, 0, 32);
	strcpy(temp_l, left);
	strcpy(temp_r, right);
	merge_sort(temp_l, 0, strlen(temp_l));
	merge_sort(temp_r, 0, strlen(temp_r));

  printf("%s, %s\n", temp_l, left);
  printf("%s, %s\n", temp_r, right);

	if (strcmp(str_to_lower(temp_l), str_to_lower(temp_r)) == 0) {
		return 1;
	} 

	return 0;
}

void merge(char* arr, int low, int mid, int high) {
	int i, j, k;
	int left_len = mid - low + 1;
	int right_len = high - mid;

	char* left_arr = malloc(left_len);
	char* right_arr = malloc(right_len);

	for (i = 0; i < left_len; i++) {
		left_arr[i] = arr[low + i];
	}

	for (j = 0; j < right_len; j++) {
		right_arr[j] = arr[mid + low + j];
	}

	i = 0, j = 0, k = low;

	while (i < left_len && j < right_len) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		} else {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while (i < left_len) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while (j < right_len) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}

  free(left_arr);
  free(right_arr);
}

void merge_sort(char* arr, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) * .5f;

		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);

		merge(arr, low, mid, high);
	}
}