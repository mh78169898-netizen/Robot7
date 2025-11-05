//홀수,짝수를 판별하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	
	if (a % 2 == 1) {
		printf("홀수");
	}
	else {
		printf("짝수");
	}
	return 0;
}
