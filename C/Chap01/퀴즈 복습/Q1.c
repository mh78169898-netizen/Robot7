//나이를 구하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	printf("태어난 년도 : ");
	scanf("%d", &a);
	b = 2025 - a;
	printf("나이 : %d\n", b);
	return 0;
}
