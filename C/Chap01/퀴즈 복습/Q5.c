//잔돈 계산 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int price, pay;
	printf("물건 가격 : ");
	scanf("%d", &price);
	printf("지불 금액 : ");
	scanf("%d", &pay);

	int change = pay - price;
	printf("거스름돈 : %d\n", change);

	int c1000, c500, c100;
	c1000 = change / 1000;
	change %= 1000;
	c500 = change / 500;
	change %= 500;
	c100 = change / 100;
	change %= 100;

	printf("1000원 %d개, 500원 %d개, 100원 %d개\n", c1000, c500, c100);
	return 0;
}
