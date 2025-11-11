#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <memory.h>

int main()
{
	char temp[80];
	char* str[3];

	for (int i = 0; i < 3; i++) {
		printf("문자열을 입력하세요 : ");
		fgets(temp, sizeof(temp), stdin);
		str[i] = (char*)malloc(strlen(temp) + 1); //'\0' 문자가 들어가는 곳
		strcpy(str[i], temp);
	}

	for (int i = 0; i < 3; i++) {
		printf("%s\n", str[i]);
	}
	for (int i = 0; i < 3; i++) {
		free(str[i]);//메모리 해제
	}

	return 0;
}
