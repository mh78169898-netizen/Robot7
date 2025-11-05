//섭씨를 화씨로 변환하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	double b;
	printf("섭씨? : ");
	scanf("%d", &a);
	b = (double)9 / 5 *  a + 32;
	printf("화씨 : %.2lf\n", b);
	return 0;
}
