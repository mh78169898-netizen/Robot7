//stdin과 stdout을 사용한 문자 입출력
#include <stdio.h>

int main()
{
    int ch;

    while (1)
    {
        //ch = getchar();
        ch = fgetc(stdin);
        if (ch == EOF) //wsl Ubuntu ^z --> ^c로 종료함
        {
            break;
        }
        //putchar(ch);
        fputc(ch, stdout);
    }

    return 0;
}
