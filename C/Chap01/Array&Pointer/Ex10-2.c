#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[3];
	int* pa;
	pa = arr;

	*pa = 10; //arr[0]
	*(pa + 1) = 20; //arr[1]
	pa[2] = pa[0] + pa[1]; //arr[3] = 10 + 20

	for (int i = 0; i < 3; i++) {
		printf("%5d", pa[i]);
	}
	return 0;
}
