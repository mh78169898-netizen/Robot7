#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

void print_max(int arr[]);//int* arr 도 가능

int main()
{
	int arr[7] = { 4,5,8,1,2,3,7 };
	int max = arr[0];

	print_max(arr);
	return 0;
}

void print_max(int arr[]) {
	int max = INT_MIN;//변수의 Scope
	for (int i = 0; i < 7; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	printf("가장 큰 값 : %d\n", max);
}
