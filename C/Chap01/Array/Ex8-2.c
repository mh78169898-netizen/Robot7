#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sco[5];
	int tot = 0;
	
	for (int i = 0; i < 5; i++) {
		scanf("%d", &sco[i]);
	}

	//tot = sco[0] +  sco[1] +  sco[2] +  sco[3] +  sco[4];
	for (int i = 0; i < 5; i++) {
		//tot = tot + sco[i];
		tot += sco[i];
	}
	double avg = (double)tot / 5;
	for (int i = 0; i < 5; i++) {
		printf("%5d", sco[i]);
	}
	printf("\n");
	printf("평균 : %.1lf\n", avg);

	return 0;
}

////////////////코드 최적화 버전//////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sco[5];
	int tot = 0;
	
	for (int i = 0; i < 5; i++) {
		scanf("%d", &sco[i]);
		tot += sco[i];
		printf("%5d", sco[i]);
	}

	double avg = (double)tot / 5;

	printf("\n");
	printf("평균 : %.1lf\n", avg);

	return 0;
}
