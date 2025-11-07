#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a = 10, b = 20;

	printf("교환 전 a 와 b의 값: %d, %d\n", a, b);
	{
		int temp; 
		//int a = 0, int b = 0;//지역 변수 설정

		temp = a;
		a = b;
		b = temp;
	}
	printf("교환 후 a 와 b의 값: %d, %d\n", a, b);

	return 0;
}
