#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int tot;

int main()
{
	int* pi;
	int sum = 0;
	//배열을 heap에 할당해보자
	pi = (int*)malloc(5 * sizeof(int));
	printf("다섯명의 나이를 입력하시오 : ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &pi[i]);//heap에 있는 변수의 공간
		sum += pi[i];//heap에 있는 변수의 값을 가져온다.
	}
	printf("평균 : %.1lf\n", sum / 5.0);
	
	free(pi);

	return 0;
}
