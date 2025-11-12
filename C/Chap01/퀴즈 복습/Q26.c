//소수 구하는 문제
#include <stdio.h>

int main()
{
    int sosu = 100;

    for(int i = 2; i < 100; i++){
        int sosu = 1;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                sosu = 0;
                break;
            }
        }
        if(sosu == 1){
            printf("%d ", i);
        }
    }

    return 0;
}
