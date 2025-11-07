//gets함수로 한 줄의 문자열 입력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[80];

	printf("공백이 포함된 문자열 입력 : ");
	gets(str);//Linux등 에서는 사용 불가능한 함수,C11버전에서 부터는 사용 불가,fgets를 사용해야 함
	printf("입력한 문자열은 %s입니다.\n", str);

	return 0;
}
