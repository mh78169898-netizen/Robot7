//열거형을 사용한 프로그램
#include <stdio.h>

enum season {SPRING, SUMMER, FALL, WINTER};

int main()
{
    enum season ss;
    char* pc = NULL;

    ss = FALL;

    switch(ss)
    {
        case SPRING:
            pc = "inline"; break;
        case SUMMER:
            pc = "swimming"; break;
        case FALL:
            pc = "trip"; break;
        case WINTER:
            pc = "skiing"; break;
    }
    printf("나의 레저 활동 => %s\n", pc);

    return 0;
}
