#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;
    char fnev[60];
    printf("Filenev: ");
    scanf("%s", fnev);
    fp = fopen(fnev, "w");
    printf("Uzenet: ");
    while( (ch = getchar()) != '#') {
        putc(ch, fp);
    }
    fclose(fp);
    fp = fopen(fnev, "r");
    while ( (ch = getc(fp)) != EOF ) {
        printf("%c", toupper(ch));
    }
    fclose(fp);

    char nev2[60] = "atmeneti";
    FILE *fpp = fopen(nev2, "w");
    fp = fopen(fnev, "r");
    fseek(fp, 0L, SEEK_END);
    int pos = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    while (pos--)
    {
        ch = fgetc(fp);
        fputc(toupper(ch), fpp);
    }

    fclose(fp);
    fclose(fpp);

    remove(fnev);
    rename(nev2, fnev);

    return 0;
}
