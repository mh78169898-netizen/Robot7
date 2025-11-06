#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[3];
	int i;

	*(arr + 0) = 10;
	*(arr + 1) = *(arr + 0) + 10;

	printf("세 번째 배열 요소에 키보드 입력 : ");
	scanf("%d", arr + 2);
	
	for (i = 0; i < 3; i++) {
		printf("%5d", *(arr + i));
	}
	return 0;
}
