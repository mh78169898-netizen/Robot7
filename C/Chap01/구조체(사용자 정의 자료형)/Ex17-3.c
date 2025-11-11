//다른 구조체를 맴버로 갖는 구조체 사용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile
{
	int age;
	double heig;
};

struct student
{
	struct profile pf;
	int id;
	double grade;
};

int main()
{
	struct student yuni;
	yuni.pf.age = 17;
	yuni.pf.heig = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이 : %d\n", yuni.pf.age);
	printf("키 : %.1lf\n", yuni.pf.heig);
	printf("학번 : %.d\n", yuni.id);
	printf("학점 : %.1lf\n", yuni.grade);

	return 0;
}
