/*------------------------------------------------*/
/* qsort1.c                                       */

#include <stdio.h>
#include <stdlib.h>

#define DELKAPOLE 20

typedef struct {
    int x, y;
    div_t podil;
} cisla;

int srovnej_cislo(cisla * a, cisla * b)
{
    /* nejdrive tridime podle zbytku */
    if (a->podil.rem > b->podil.rem)
	return 1;
    else if (a->podil.rem < b->podil.rem)
	return -1;
    /* kdyz jsou si zbytky rovny, tridime podle
     * podilu */

    else if (a->podil.quot > b->podil.quot)
	return 1;
    else if (a->podil.quot < b->podil.quot)
	return -1;
    else
	return 0;		/* jsou si rovny */
}

int main(void)
{
    int i;
    cisla pole[DELKAPOLE];
    for (i = 0; i < DELKAPOLE; i++) {
	pole[i].x = i;
	pole[i].y = 5;
	pole[i].podil = div(pole[i].x, pole[i].y);
    }

    qsort(pole, sizeof(pole) / sizeof(pole[0]), sizeof(pole[0]),
	  (int (*)(const void *, const void *)) srovnej_cislo);

    for (i = 0; i < DELKAPOLE; i++)
	printf("%2i/%2i = %2i (%2i)\n", pole[i].x, pole[i].y,
	       pole[i].podil.quot, pole[i].podil.rem);

    return 0;
}

/*------------------------------------------------*/
