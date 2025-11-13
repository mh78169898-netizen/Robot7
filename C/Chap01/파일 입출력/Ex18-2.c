//파일의 내용을 화면에 출력하기
#include <stdio.h>

int main()
{
    FILE* fp;
    int ch;

    fp = fopen("a.txt", "r");
    if(fp == NULL){
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }
    while(1){
        ch = fgetc(fp); //한 글자를 가져오는 함수
        if(ch == EOF){ //-1 파일의 끝
            break;
        }
        putchar(ch);//printf("%c", ch)
    }
    fclose(fp);//자원 반납(반환)

    return 0;
}
