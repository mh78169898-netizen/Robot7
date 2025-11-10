#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int score[3][4]; //y행,x행
	int tot;
	double avg;
	int i, j;

	for (int i = 0; i < 3; i++) {
		printf("4과목의 점수 입력 : ");
		for (int j = 0; j < 4; j++) {
			scanf("%d", &score[i][j]);
		}
	}
	//출력
	for (int i = 0; i < 3; i++) {//라인, 사람
		tot = 0;
		for (int j = 0; j < 4; j++) {//각 과목
			tot += score[i][j];
		}
		avg = tot / 4.0;
		printf("총점 : %d, 평균 : %.2f\n", tot, avg);
	}
	return 0;
}
