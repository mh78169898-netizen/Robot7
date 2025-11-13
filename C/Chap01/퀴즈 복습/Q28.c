#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fin;
    FILE *fout;
    int ch;
    fin = fopen("read.txt", "r");
    if(fin == NULL){
        printf("파일이 열리지 않았습니다.");
        exit(1);
    }
    fout = fopen("write.txt", "w");
    if(fout == NULL){
        printf("파일이 열리지 않았습니다.");
        exit(1);
    }

    while((ch=fgetc(fin)) != EOF){//이 부분이 가장 중요함!!!!!!
        fputc(ch, fout);
    }
     
    fclose(fin);
    fclose(fout);

    return 0;
}
