//사용자 정의 헤더 파일을 사용하는 프로그램
1.헤더 코드
typedef struct
{
	int num;
	char name[20];
} Student;
////////////////////////////////////////////////////
2.메인 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "student.h" //사용자 정의 헤더

int main()
{
	Student a = { 315,"홍길동" };

	printf("학번 : %d, 이름 : %s\n", a.num, a.name);

	return 0;
}
