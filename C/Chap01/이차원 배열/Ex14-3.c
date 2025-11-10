#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char animal[5][20];
	int i;
	int cou;

	cou = sizeof(animal) / sizeof(animal[0]); //행의 계산
	for (i = 0; i < cou; i++) {
		scanf("%s", animal[i]); //animal = 첫 번째 행 1차원 char배열의 배열명
	}

	for (i = 0; i < cou; i++) {
		printf("%s ", animal[i]);
	}
	return 0;
}
