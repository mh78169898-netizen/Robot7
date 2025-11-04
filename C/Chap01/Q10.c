#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pul(int a, int b);
int miu(int a, int b);
int mul(int a, int b);
double div( double a, double b);

int main()
{
	int x, y;
	printf("두 정수를 입력하세요. : ");
	scanf("%d %d", &x, &y);

	printf("%d\n", pul(x, y));
	printf("%d\n", miu(x, y));
	printf("%d\n", mul(x, y));
	printf("%.2lf\n", div(x, y));
	return 0;
}

int pul(int a, int b) {
	return a + b;
}

int miu(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

double div(double a, double b) {
	return (double)a / b;
}
