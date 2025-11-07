#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[20];
	printf("문자열을 입력하세요 : ");
	gets(str);
	int an = 0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			an++;
		}
		
	}
	printf("모음은 총 %d개 있습니다.", an);

	return 0;
}
