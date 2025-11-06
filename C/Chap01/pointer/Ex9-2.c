#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	int* pa;

	pa = &a; //a변수의 시작주소를 pa에 넣는다.(int*)
	*pa = 10; //int형 포인터 타입으로 설정

	printf("*pa변수의 주소값 : %u\n", &pa);
	printf("a변수의 주소값 : %u\n",&a);
	printf("*pa변수의 값 : %u\n\n", pa);

	printf("포인터로 a값 : %d\n", *pa);
	printf("변수형으로 a값 : %d\n", a);
	return 0;
}
