/*------------------------------------------------*/
/* quick.c                                        */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMER 10

/* funkci quicks budeme volat rekurzivne,
 * vzdy na levou a pravou cast */

void vypis_usek(const unsigned int *pole, const char *text,
		const unsigned int zacatek, const unsigned int konec)
{
    unsigned int i;
    printf("%-10s", text);
    for (i = 0; i < ROZMER; i++) {
	if (i < zacatek || i > konec) {
	    printf("-- ");
	} else {
	    printf("%2u ", pole[i]);
	}
    }
    printf("\n");
}

void quicks(unsigned int *pole, const unsigned int levy_usek,
	    const unsigned int pravy_usek)
{
    unsigned int levy, pravy;
    unsigned int pivot, pom;

    levy = levy_usek;
    pravy = pravy_usek;

    pivot = pole[(levy + pravy) / 2];	/* vybereme pivota */
    printf("pivot: pole[%u] = %u\n", (levy + pravy) / 2, pivot);
    vypis_usek(pole, "Pred:", levy_usek, pravy_usek);

    do {
	while (pole[levy] < pivot)
	    levy++;
	while (pivot < pole[pravy])
	    pravy--;

	if (levy <= pravy) {
	    pom = pole[levy];
	    pole[levy] = pole[pravy];
	    pole[pravy] = pom;
	    levy++;
	    pravy--;
	}

    } while (levy <= pravy);

    vypis_usek(pole, "Po:", levy_usek, pravy_usek);
    /* ted vime, ze vsechny cisla od "levy_usek" k "pravy"
       jsou mensi nebo rovna cislum od "levy" po pravy_usek */
    if (levy_usek < pravy)
	quicks(pole, levy_usek, pravy);	/* razeni leve casti */
    if (levy < pravy_usek)
	quicks(pole, levy, pravy_usek);	/* razeni prave casti */

}

int main(void)
{
    unsigned int cykl;
    unsigned int pole[] = { 74, 43, 94, 6, 89, 76, 88, 33, 52, 59 };

    printf("%-10s", "Start:");

    for (cykl = 0; cykl < ROZMER; cykl++) {
	printf("%2u ", pole[cykl]);
    }
    printf("\n");

    /* ted pole setridime algoritmem quick sort */
    quicks(pole, 0, ROZMER - 1);

    printf("%-10s", "Konec:");
    for (cykl = 0; cykl < ROZMER; cykl++) {
	printf("%2u ", pole[cykl]);
    }
    printf("\n");

    return 0;
}

/*------------------------------------------------*/
