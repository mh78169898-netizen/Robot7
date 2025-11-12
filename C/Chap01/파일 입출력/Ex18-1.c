//파일을 열고 닫는 프로그램(시스템쪽 프로그램)
#include <stdio.h>

int main()
{
    FILE* fp;

    fp = fopen("a.txt", "r");
    if(fp == NULL){
        printf("파일이 열리지 않았습니다.\n");
        return 1;
    }
    printf("파일이 열렀습니다.\n");
    fclose(fp);

    return 0;
}
