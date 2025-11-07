//strncpy 함수를 사용한 문자열 복사
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20] = "mango tree";
	
	strncpy(str, "apple-pie", 5);

	printf("%s\n", str);

	return 0;
}
