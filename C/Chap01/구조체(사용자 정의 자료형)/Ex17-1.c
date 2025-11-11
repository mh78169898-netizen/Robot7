#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student //예약어, 구조체 이름
{
	int num; // 구조체 맴버
	double grade; //구조체 맴버
};

int main()
{
	struct student gildong;

	gildong.num = 2;
	gildong.grade = 3.4;
	printf("학번 : %d\n", gildong.num);
	printf("학점 : %.1lf\n", gildong.grade);
	return 0;
}
