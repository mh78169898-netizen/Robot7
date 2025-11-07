#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char* dessert = "apple";//apple은 포인터

	printf("오늘 후식은 %s입니다.\n", dessert);
	dessert = "banana";
	printf("내일 후식은 %s입니다.\n", dessert);
	return 0;
}
