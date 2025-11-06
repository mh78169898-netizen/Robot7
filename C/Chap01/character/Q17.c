#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char ch1[80];
	scanf("%s", ch1);

	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int cnt4 = 0;

	for (int i = 0; i < strlen(ch1); i++) {
		if ((ch1[i] >= 'A') && (ch1[i] <= 'Z')) cnt1++;
		else if ((ch1[i] >= 'a') && (ch1[i] <= 'z')) cnt2++;
		else if ((ch1[i] >= '0') && (ch1[i] <= '9')) cnt3++;
		else cnt4++;
	}

    printf("\n알파벳 대문자 : %d\n", cnt1);
    printf("알파벳 소문자 : %d\n", cnt2);
    printf("숫자 : %d\n", cnt3);
    printf("특수문자 : %d\n", cnt4);

	return 0;
}
