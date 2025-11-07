#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, gra;

	printf("학번 입력 : ");
	scanf("%d", &num);
	getchar(); //버그 퇴치용
	printf("학점 입력 : ");
	gra = getchar();
	printf("학번 : %d, 학점 : %c", num, gra);
	return 0;
}
