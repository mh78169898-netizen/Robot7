//완전수 구하는 문제
#include <stdio.h>

int main()
{
    int num;
    int sum = 0;
    printf("정수 입력 : ");
    scanf("%d", &num);

    for(int i = 1; i < num; i++){
        if(num % i == 0){
            sum += i;
        }
    }
    if(sum == num){
        printf("yes");
    }else{
        printf("no");
    }

    return 0;
}
