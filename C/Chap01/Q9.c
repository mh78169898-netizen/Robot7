#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	//1단계

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	//2단계

	for (int i = 0; i <= n; i++) {
		for (int j = n; j > i; j--) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	//3단계

	for (int i = 0; i <= n; i++) {
		for (int j = 4; j >= i; j--) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	//4단계

	for (int i = n; i > 0; i--) {
		for (int j = n; j > i; j--) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		//printf("\n");
	}
	printf("\n\n");
	//5단계
	int a;

	printf("숫자를 입력하세요. : ");
	scanf("%d", &a);
	if (a % 2 != 0) {
		int a_ = (a / 2) + 1;
		for (int i = 1; i <= a_; i++) {
			for (int j = 0; j < a_ - i; j++) {
				printf(" ");
			}
			for (int k = 0; k < 2 * i - 1; k++) {
				printf("*");
			}
			printf("\n");
		}
		for (int i = a_ -1; i >= 1; i--) {
			for (int j = 0; j < a_ - i; j++) {
				printf(" ");
			}
			for (int k = 0; k < 2 * i - 1; k++) {
				printf("*");
			}
			printf("\n");
		}
	}
	else {
		printf("홀수만 입력해주세요!!!\n");
	}
	return 0;
}
