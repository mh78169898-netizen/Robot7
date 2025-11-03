#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//1~100까지의 누적합 5050을 for문으로 작성하시오
	int sum = 0;

	for (int i = 0; i <= 100; i++) {
		sum = sum + i;
		printf("sum : %d, i = %d\n", sum, i);
	}
	//printf("sum : %d\n", sum);

	return 0;
}
