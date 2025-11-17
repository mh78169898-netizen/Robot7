#include <stdio.h>

int main()
{
    FILE *afp, *bfp;
    int num = 10;
    int res;

    afp = fopen("a4.txt", "wt");
    fprintf(afp, "%d", num);

    bfp = fopen("b4.txt", "wb");
    fwrite(&num, sizeof(num), 1, bfp);

    fclose(afp);
    fclose(bfp);

    bfp = fopen("b4.txt", "rb"); //binary모드로 read
    fread(&res, sizeof(res), 1, bfp);//b4.txt binary 파일을 읽어옴
    printf("%d", res);//10진 정수로 출력

    fclose(bfp);

    return 0;
}
