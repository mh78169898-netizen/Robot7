//크기가 다른 배열을 출력하는 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_arr(int* pa, int size);

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int arr2[7] = { 10,20,30,40,50,60,70 };

	print_arr(arr, 5);
	printf("\n");
	print_arr(arr2, 7);

	return 0;
}

void print_arr(int* pa, int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%d ", pa[i]);
	}
}
