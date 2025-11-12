1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

struct book

{

	char title[50];

	char author[30];

	int page;

	int price;

};

int main()

{

	struct book a;



	strcpy(a.title, "C프로그래밍");

	strcpy(a.author, "데니스");

	a.page = 180;

	a.price = 18000;



	printf("도서명 : %s\n", a.title);

	printf("저자 : %s\n", a.author);

	printf("페이지 수 : %d\n", a.page);

	printf("가격 : %d\n", a.price);



	return 0;

}



2.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct cracker
{
	int price;
	int cal;
};
int main()
{
	struct cracker c;
	int price, cal;
	printf("바사삭의 가격과 열랑을 입력하세요 : ");
	scanf("%d %d", &c.price, &c.cal);

	printf("바사삭의 가격 : %d원\n",c.price);
	printf("바사삭의 가격 : %dkcal\n",c.cal);

	return 0;
}
