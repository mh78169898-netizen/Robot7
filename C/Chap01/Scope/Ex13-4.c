//auto(일반)지역 변수와 static(정적)지역 변수의 비교
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void auto_func();//일반
void static_func();//정적

int main()
{
	int i;

	printf("일반 지역 변수(auto)를 사용한 함수... \n");
	for (i = 0; i < 3; i++) {
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수... \n");
	for (i = 0; i < 3; i++) {
		static_func();
	}
	return 0;
}

void auto_func() {//함수가 종료되면 0으로 초기화 됨
	auto int a = 0;
	a++;
	printf("%d\n", a);
}

void static_func() {//최초만 초기화, 이후로는 누적
	static int a = 0;
	a++;
	printf("%d\n", a);
}
