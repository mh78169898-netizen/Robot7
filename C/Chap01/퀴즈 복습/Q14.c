//X보다 작은 수를 배열에서 찾는 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	int arr[10000];
	for (int i = 0; i < n; i++) {
		scanf("%d", & arr[i]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] < x) {
			printf("%2d", arr[i]);
		}
	}
	return 0;
}
