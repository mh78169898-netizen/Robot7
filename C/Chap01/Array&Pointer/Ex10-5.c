#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_arr(int* pa);

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	print_arr(arr);//배열을 함수로 전달했다.

	return 0;
}

void print_arr(int* pa) {//전달받은 배열을 함수에서 출력하기
	for (int i = 0; i < 5; i++) {
		printf("%d ", pa[i]);
	}
}
