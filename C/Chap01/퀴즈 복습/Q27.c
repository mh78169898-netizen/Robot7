#include <stdio.h>

int main(){
    FILE* fp;
    char str[] = "블루베리";
    int i;

    fp = fopen("fruits.txt", "w");
    if(fp == NULL){
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    i = 0;
    while(str[i] != '\0'){
        fputc(str[i], fp);
        i++;
    }
    fputc('\n', fp);
    fclose(fp);

    return 0;
}
