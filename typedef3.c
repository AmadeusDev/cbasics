/*------------------------------------------------*/
/* typedef3.c                                     */
#include <stdio.h>

/* funkce zkopiruj kopiruje retezec v2 do retezce v1 */
void zkopiruj(char *v1, char *v2)
{
    int i = 0;
    do {
	v1[i] = v2[i];
    } while (v2[i++]);
}

typedef struct {
    char nazev[40];
    char zpevak[40];
    char skladatel[40];
    float delka;
} Pisen;

typedef struct {
    char nazev[40];
    int pocet_pisni;
    float cenaSK, cenaCZ;
    Pisen pisen[20];
} CD;

void tiskni(CD * cd, int pocet);

int main(void)
{
    CD *ualbum, alba[10], album;
    /* inicializuji album */
    ualbum = &album;		/* pouziti ukazatele album je tu jen pro ilustraci */
    zkopiruj(album.nazev, "The Beatles Songs");
    album.cenaSK = 325.50;
    ualbum->cenaCZ = 286.50;
    album.pocet_pisni = 1;
    /* vkladam prvni (a posledni) pisen do alba */
    zkopiruj(album.pisen[0].nazev, "Twist And Shout");
    zkopiruj(ualbum->pisen[0].zpevak, "The Beatles");
    zkopiruj(album.pisen[0].skladatel, "Lennon/McCartney");
    ualbum->pisen[0].delka = 2.36;

    /* ukazka prace z polem alba */
    /* do pole alba vkladam prvni album */
    alba[0] = album;
    /* to same album vlozim jeste jednou,
       tentokrat prez ukazatel */
    alba[1] = *ualbum;
    /* zmenim nazev a cenu ... */
    zkopiruj(alba[1].nazev, "Salute to The Beatles");
    alba[1].cenaSK = 350.0;
    /* ... a pridam dalsi pisen */
    alba[1].pocet_pisni = 2;
    alba[1].pisen[1] = alba[1].pisen[0];
    zkopiruj(alba[1].pisen[1].nazev, "Eleanor Rigby");
    alba[1].pisen[1].delka = 2.06;

    tiskni(alba, 2);
    return 0;
}

void tiskni(CD * cd, int pocet)
{
    int i, j;

    for (i = 0; i < pocet; i++) {
	/* tisknu album "i" */
	printf("%s\t%5.2fKc (%5.2fSk)\n", cd[i].nazev, cd[i].cenaCZ,
	       cd[i].cenaSK);
	for (j = 0; j < cd[i].pocet_pisni; j++) {
	    /* tisknu pisne z alba "i" */
	    printf("\t\tNazev:\t%s\n", cd[i].pisen[j].nazev);
	    printf("\t\tInterpret:\t%s\n", cd[i].pisen[j].zpevak);
	    printf("\t\tSkladatel:\t%s\n", cd[i].pisen[j].skladatel);
	    printf("\t\tDelka:\t%.2f\n", cd[i].pisen[j].delka);
	    printf("\t\t.......................\n");
	}
	printf("------------------------------------------\n");
    }
}

 /*------------------------------------------------*/
