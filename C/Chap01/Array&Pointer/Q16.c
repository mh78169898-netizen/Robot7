#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_max(int arr[]);

int main()
{
	int arr[7] = { 4,5,8,1,2,3,7 };
	int max = arr[0];

	print_max(arr);
	return 0;
}

void print_max(int arr[]) {
	int max = 0;
	for (int i = 0; i < 7; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("가장 큰 값 : %d\n", max);
}
