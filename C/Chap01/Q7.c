1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()

{

	int i = 0;

	while (i < 9) {

		int a = 3;

		i++;

		a = a * i;

		printf("3 * %d = %d\n", i, a);

	}

	return 0;

}



2.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()

{

	char i = '@';



	while (i < 'Z') {

		i++;

		printf("%c ", i);

	}

	printf("\n");

	char j = '`';



	while (j < 'z') {

		j++;

		printf("%c ", j);

	}

	return 0;

}

