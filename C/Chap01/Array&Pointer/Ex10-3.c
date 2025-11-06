#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int a;
	//int arr[3];
	//int* pa = &a;

	//printf("%d\t %d\t %d\n", sizeof(a), sizeof(pa), sizeof(arr));

	int arr[3] = { 10,20,30 };
	int* pa = arr;
	int i;

	printf("배열의 값 : ");
	for (int i = 0; i < 3; i++) {
		printf("%d ", *pa);
		pa++;
	}
	return 0;
}
