/*------------------------------------------------*/
/* bubble.c                                       */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMER 10

void vypis_pole(short int cykl, unsigned int pole[])
{
    unsigned short int i;
    printf("Prvky pole (%2i):\n", cykl);

    /* schvalne, co by se stalo, kdyby byl ROZMER lichy ? */
    for (i = 0; i < ROZMER / 2; i++)
	printf("%2u: %u\t\t%2u: %u\n", i + 1, pole[i], i + ROZMER / 2 + 1,
	       pole[i + ROZMER / 2]);
    /* spravna odpoved zni .... chvilka napeti ...
     * posledni prvek z pole by se nevypsal.     */
}

int main(void)
{
    unsigned int cykl, bublani;
    unsigned int pole[ROZMER], pom;

    /* nejdrive inicializujeme pole nahodnymi hodnotami a vypiseme jej */
    srand((unsigned int) time(NULL));

    for (cykl = 0; cykl < ROZMER; cykl++)
	pole[cykl] = (rand() % 100) + 1;

    printf("Inicializace: \n");
    vypis_pole(-1, pole);

    /* ted pole setridime algoritmem bubble sort */

    for (cykl = 1; cykl < ROZMER; cykl++) {
	for (bublani = ROZMER - 1; bublani >= cykl; bublani--) {
	    printf(".");
	    if (pole[bublani - 1] > pole[bublani]) {
		/* mensi cislo probubla o jeden prvek smerem k zacatku */
		pom = pole[bublani - 1];
		pole[bublani - 1] = pole[bublani];
		pole[bublani] = pom;
	    }
	}
	/* vypiseme mezivysledek, kde "cykl" nejmensich cisel
	 * uz mame zarucene na zacatku pole */
	printf("\n");
	vypis_pole(cykl, pole);
    }

    return 0;
}

/*------------------------------------------------*/
