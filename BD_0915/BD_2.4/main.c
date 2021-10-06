#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int sum=0;

struct jarmu{
    char rendszam[7];
    char type[20];
    int price;
}Auto[100];


int main(){

    int szam=0;

    printf("Hany adatot szeretne felvinni? ");
    scanf("%d", &szam);

    FILE *fp;
    fp = fopen("autok.bin", "rb");

    int i=sum;

    while(i<szam+sum){

        printf("Adja meg az auto rendszamat! ");
        scanf("%s", &Auto[i].rendszam);

        printf("Adja meg az auto szinet! ");
        scanf("%s", &Auto[i].type);

        printf("Adja meg az auto arat! ");
        scanf("%d", &Auto[i].price);

        fwrite(&(Auto[i].price), sizeof(int), 1, fp);
        fwrite(&(Auto[i].type), sizeof(Auto[i].type), 1, fp);
        fwrite(&(Auto[i].rendszam), sizeof(Auto[i].rendszam), 1, fp);
        fwrite("\n", 1, 1, fp);

        i++;
    }

    sum = sum+szam;

    fclose(fp);

    pl3_olvas();

    visszair();

    return 0;

}


void pl3_olvas(){

    FILE *fp;
    fp = fopen("autok.bin", "rb");
    int szam=0;

    if(fp == NULL){
        printf("nem sikerult megnyitni az allomanyt");
    }
    else{
        printf("Hanyadik rekordot szeretne visszaolvasni? Eddig %d adat van az adatbazisban. ", sum);
        scanf("%d", &szam);
        fseek(fp, (szam-1)*sizeof(struct jarmu),0);

        fread(&(Auto[szam]), sizeof(struct jarmu), 1,fp);
            printf("rsz: %s\n", Auto[szam-1].rendszam);
            printf("szin: %s\n", Auto[szam-1].type);
            printf("ar: %d\n", Auto[szam-1].price);
    }

    fclose(fp);

}

void visszair(){

    FILE *fp = fopen("autok.bin", "wb");

    for(int i=0; i<sum; i++){
        fwrite(&(Auto[i].rendszam), sizeof(Auto[i].rendszam), 1, fp);
        fwrite(&(Auto[i].type), sizeof(Auto[i].type), 1, fp);
        fwrite(&(Auto[i].price), sizeof(Auto[i].price), 1, fp);
        fwrite("\n", 1, 1, fp);
    }

}
