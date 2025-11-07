strcmp, strncmp함수를 사용한 문자열 비교
  #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[80] = "pear";
	char str2[80] = "peach";

	//int res = strcmp(str1, str2);//-1, 0, 1
	//printf("리턴값 : %d\n", res);

	printf("사전에 나중에 나오는 과일 이름 : ");
	if(strcmp(str1, str2) > 0) {
		printf("%s\n", str1);
	}
	else {
		printf("%s\n", str2);
	}
		
	return 0;
}
