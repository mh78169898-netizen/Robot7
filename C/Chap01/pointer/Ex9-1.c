#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 5;
	double b;
	char c;

	printf("int형 변수의 주소(10진수) : %u\n", & a);
	printf("int형 변수의 주소(16진수) : %p\n\n", &a);

	printf("int형 변수의 주소(10진수) : %u\n", &b);
	printf("int형 변수의 주소(16진수) : %p\n\n", &b);

	printf("int형 변수의 주소(10진수) : %u\n", &c);
	printf("int형 변수의 주소(16진수) : %p\n\n", &c);
	return 0;
}
