#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>//위나 아래쪽 어느 하나만 사용해도 문제 없음
#include <memory.h>//위나 아래쪽 어느 하나만 사용해도 문제 없음

int tot;

int main()
{
	int* pi;
	double* pd;
	/*int a,b;*/

	pi = (int*)malloc(sizeof(int));
	//printf("heap : %p\n", pi);//힙 영역
	//printf("stack : %p\t%p\n\n", &a, &b);//스택 영역
	//printf("string : %p\n", "hello");//문자열 영역, 글로벌 변수 근처에 존재
	//printf("global : %p\n", &tot);//글로벌 영역
	if (pi == NULL) {
		printf("# 메모리가 부족합니다.\n");
		exit(1);
	}
	pd = (double*)malloc(sizeof(double));//double = 8
	*pi = 10; //stack메모리가 아닌 heap메모리 공간에 값 삽입
	*pd = 3.4; //heap에 값 삽입

	printf("정수형으로 사용 : %d\n", *pi);
	printf("실수형으로 사용 : %.1lf\n", *pd);

	free(pi);
	free(pd);

	return 0;
}
