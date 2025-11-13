#include <stdio.h>

int main()
{
    int sco1, sco2, sco3;
    printf("철수, 영희, 민수의 성적을 입력하시오 : ");
    scanf("%d %d %d", &sco1, &sco2, &sco3);

    if(sco1 > sco2 && sco1 > sco3){
        printf("1등은 철수");
    }else if(sco2 > sco1 && sco2 > sco3){
        printf("1등은 영희");
    }else{
        printf("1등은 민수");
    }

    return 0;

}
