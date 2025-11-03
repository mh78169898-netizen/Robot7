#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j;

	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}

//while문 버전
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 2;

	while (i <= 9) {
		int j = 1;
		printf("%d단 \n", i);

		while (j <= 9) {
			printf("%d * %d = %d\n", i, j, i * j);
			j++;
		}
		i++;
	}
	return 0;
}
