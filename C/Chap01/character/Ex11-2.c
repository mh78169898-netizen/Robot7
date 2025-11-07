#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char ch1, ch2;

	scanf(" %c %c", &ch1, &ch2);

	//fflush(stdin); //TC에서는 잘 작동함(XXXX)

	printf("[%c%c]", ch1, ch2);

	return 0;
}
