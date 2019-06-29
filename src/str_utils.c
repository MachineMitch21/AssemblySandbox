#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 255 byte buffer might not be big enough for all use cases, but it will suffice for now
#define MERGE_BUFFER_SIZE 255


void strrev(char* str) {
	int len = strlen(str);
  // [0], [1], [2], [3]
  // mid_index == 1
	int mid_index = len * .5f - 1;
	for (int i = 0; i <= mid_index; i++) {
    // swap elements at exact opposite ends of the string
    // [0], [1], [2], [3]
    // swap 0 and 3
    // swap 1 and 2
		char temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
}

/*
*   buffer  -> the buffer to store the resulting string in
*               it is up to you to make sure the buffer is large enough
*   n       -> the number to convert to a string
*   divisor -> the type of string output will be decided by this
*                 ex. 
*/
void to_string(char* buffer, int n, int divisor) {
	int d = 0;
	int count = 0;
  do {
    d = n % divisor;
    buffer[count++] = d + (d > 9 /* hex value greater than 9?? */ ? 0x37 : 0x30);
    n/=divisor;
  } while (n > 0);

  int offset = 0;

  if (divisor == 16) {
    // this is a hexadecmial value
    buffer[count + 1] = 'x';
    buffer[count + 2] = '0'; 
    offset = 3;
  }

	strrev(buffer);
	buffer[count + offset] = '\0';
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
  size_t ls = strlen(temp_l);
  size_t rs = strlen(temp_r);
  str_to_lower(temp_l);
  str_to_lower(temp_r);
	merge_sort(temp_l, 0, ls - 1);
	merge_sort(temp_r, 0, rs - 1);

	if (strcmp(temp_l, temp_r) == 0) {
		return 1;
	} 

	return 0;
}

void merge_sort(char* arr, int low, int high) {
  int mid;

  if (low < high) {
    // [0], [1], [2], [3], [4], [5]
    // taking right array [3], [4], [5]
    // low == 3
    // high == 5
    // low + high == 8
    // 8 * .5f == 4
    // therefore midpoint of right array is at the 4th index of { arr }
    mid = (low + high) * .5f;
    // sort left array           
    merge_sort(arr, low, mid);
    // sort right array
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, mid + 1, high);  
  }
}

void merge(char* arr, int low_left, int high_left, int low_right, int high_right) {
  char temp[MERGE_BUFFER_SIZE];
  memset(temp, 0, MERGE_BUFFER_SIZE);
  int i, j, k;
  // start of the left array
  i = low_left;     
  // start of the right array
  j = low_right;
  k = 0;

  // do not go above either left high index or the right high index
  while (i <= high_left && j <= high_right) {
    // [0], [1], [2], [3], [4], [5]
    // say i == 2 && j == 5
    // remember (i is set to the start of the left array which is at index 0 and j is set to the start of the right which is index 3)
    // arr[i] is <= arr[j] given arr[i] == 2 and arr[j] == 5
    // array values in this example are set to the same as their index values for simplicity
    // for every time we insert a value in the temp array, we increment the counter { k } which we keep as the index into temp
    // so values just keep getting inserted at the back of temp;
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  // this is for cases where the size of arr is odd
  // [0], [1], [2]
  // when splitting the array, the left array will end up being [0], [1]
  // leaving [2] to be the right array
  // in this case, of course, high_left will end up being larger than high_right
  // causing us to get out of the above loop sooner than all the elements have been evaluated
  while (i <= high_left) {
    temp[k++] = arr[i++];
  }

  while (j <= high_right) {
    temp[k++] = arr[j++];
  }

  // Refill arr with the sorted array values stored in temp
  for (i = low_left, j = 0; i <= high_right; i++, j++) {
    arr[i] = temp[j];
  }
}