#include <stdio.h>
#include <string.h>

int main()
{
    FILE *ifp, *ofp;
    char str[20];
    char* res;

    ifp = fopen("a1.txt", "r");
    if(ifp == NULL){
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

     ofp = fopen("b1.txt", "w");
    if(ofp == NULL){
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while(1){
        res = fgets(str, sizeof(str), ifp);
        if(res == NULL){
            break;
        }
        str[strlen(str) - 1] = '\0';//문자열 마지막에 NULL문자 삽입
        fputs(str,ofp);//b1.txt에 한줄 write
        fputs(" ",ofp);
    }
    fclose(ifp);
    fclose(ofp);

    return 0;
}
