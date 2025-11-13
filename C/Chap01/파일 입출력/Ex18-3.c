//문자열을 한 문자씩 파일로 출력하는 코드
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    char str[] = "banana";
    int i;

    fp = fopen("b.txt", "w");
    if(fp == NULL){ //fopen의 정상 동작 유무확인
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }
    i = 0;
    while(str[i] != '\0'){
      //fputc(str[i], fp);
      fprintf(fp, "%c", str[i]);
      i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}
