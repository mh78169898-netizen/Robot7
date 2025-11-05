Q1.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()

{

	int ind[10];



	for (int i = 0; i < 10; i++) {

		scanf("%d", &ind[i]);

	}
  //for(int i = 0; i < 10; i++(i+=2){
  //if(ind[i] % 2 == 0){
  printf("%d", ind[i])
    }
 printf("%d", ind[i])
}

	printf("%5d% 5d% 5d% 5d% 5d", ind[1], ind[3], ind[5], ind[7], ind[9]);

	return 0;

}

Q2.
Q2.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()

{

	int arr[6] = { 3,7,2,9,5,1 };

	int max_s = arr[0];

	int max_i = 0;



	for (int i = 0; i < 6; i++) {

		if (arr[i] > max_s) {

			max_s = arr[i];

			max_i = i;

		}


	}

	printf("max : %d\n", max_s);

	printf("index : %d\n", max_i);

	return 0;

}

