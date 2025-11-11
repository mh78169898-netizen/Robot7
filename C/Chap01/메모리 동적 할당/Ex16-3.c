#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <memory.h>

int main()
{
	int* pi;
	int size = 5;
	int cou = 0;
	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int));
	while (1) {
		printf("양수만 입력하세요 =>  ");
		scanf("%d", &num);
		if (num <= 0) {
			break;
		}
		if (cou == size){
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
		}
		pi[cou++] = num;
	}
	for (int i = 0; i < cou; i++){
		printf("%5d", pi[i]);
	}
	
	free(pi);

	return 0;
}
