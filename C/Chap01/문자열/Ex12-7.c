//문자열을 출력하는 puts, fputs 함수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);
	fputs(ps, stdout);
	puts("milk");

	return 0;
}
//puts는 \n이 포함되어 있고 fputs는 아니다.
