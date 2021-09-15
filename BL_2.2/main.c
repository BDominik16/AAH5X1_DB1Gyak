#include <stdio.h>
#include <stdlib.h>

void pelda_1();

int main()
{
    //printf("Hello world!\n");
    pelda_1();
    return 0;
}

void pelda_1()
{
    FILE *fp;
    char ch;
    char fnev[50];
    printf("File nev: ");
    scanf("%s",fnev);
    fp =fopen(fnev, "W");
    printf("Uzenet ");
    while( (ch = getchar())!= '#')
    {
        putc(ch,fp);
    }
    fclose(fp);

    fp = fopen(fnev, "r");
    while((ch = getc(fp))!= EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);
    return 0;
}
