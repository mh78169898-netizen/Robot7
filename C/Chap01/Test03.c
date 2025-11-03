#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//1~100까지의 누적합 5050을 while문으로 작성하시오
	int i = 0;
	int sum = 0;

	while (i < 100) {
		i++; //증감식
		sum = sum + i;
	}
	printf("sum : %d\n", sum); //합계를 출력
	return 0;
}
