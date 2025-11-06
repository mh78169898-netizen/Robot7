#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_arr(double* pa, int siz);
double find_max(double* pa, int siz);

int main()
{
	double arr[5];
	double max;
	int siz = sizeof(arr) / sizeof(arr[0]);
	input_arr(arr, siz);
	max = find_max(arr, siz);
	printf("배열의 최댓값 : %.1lf\n", max);

	return 0;
}

void input_arr(double* pa, int siz) {
	int i;
	printf("%d개의 실수 입력 : ", siz);
	for (i = 0; i < siz; i++) {
		scanf("%lf", pa + i);
	}
}

double find_max(double* pa, int siz) {
	double max;
	int i;

	max = pa[0];
	for (i = 1; i < siz; i++) {
		if (pa[i] > max) {
			max = pa[i];
		}
	}
	return max;
}
