//개행문자로 인해 gets함수가 입력을 못하는 경우
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int age;
	char name[20];

	printf("나이 입력 : ");
	scanf("%d", &age);

	printf("이름 입력 : ");
	gets(name);
	printf("나이 : %d, 이름 : %s\n", age, name);

	///////////////////fgets 함수 사용/////////////////////////////
	
	char sAge[10];
	char name[20];

	printf("나이 입력 : ");
	fgets(sAge, 10, stdin); //17 --> "17
	int age = atoi(sAge);

	printf("이름 입력 : ");
	fgets(name, 20, stdin);
	printf("이름 : % s\n", name);
	return 0;
}
