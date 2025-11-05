//성적 3개를 입력받아 평균을 구하는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[3];
	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
	int tot;
	tot = arr[0] + arr[1] + arr[2];
	printf("총점 : %d\n", tot);
	double avg;
	avg = tot / (double)3;
	printf("평균 : %.2lf\n", avg);
	return 0;
}
