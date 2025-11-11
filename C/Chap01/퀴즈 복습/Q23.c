#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(char** pa, int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", pa[i]);
	}
}

int main()
{
	char* arr[3] = { "Lion", "Tiger", "Rabbit"};
	int cnt = 0;

	cnt = sizeof(arr) / sizeof(arr[0]);
	print_array(arr, cnt);
	return 0;
}

----------------------축소 버전-------------------------------
  #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_array(char** pa, int cnt) {
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", pa[i]);
	}
}

int main()
{
	char* arr[3] = { "Lion", "Tiger", "Rabbit"};

	print_array(arr, 3);
	return 0;
}

