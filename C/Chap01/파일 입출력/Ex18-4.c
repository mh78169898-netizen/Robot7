//표준 입/출력 스트림을 사용한 문자열 입력
#include <stdio.h>

int main()
{
    int ch;

    while (1)
    {
        // ch = getchar();
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
