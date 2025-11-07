#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	printf("문자열을 입력하세요 : ");
	gets(str);
	int len = strlen(str);
	for (int i = len; i >= 0; i--) {
		printf("%c", str[i]);
	}

	return 0;
}
