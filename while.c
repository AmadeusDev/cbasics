/*------------------------------------------------*/
/* while.c                                        */
#include <stdio.h>

int main(void)
{
    int iterace = -1;
    int navrat;
    do {
	printf("Zadejte pocet iteraci <0,10>: ");
	navrat = scanf("%i", &iterace);
	if (!navrat)
	    return 1;		/* uzivatel nezadal cislo; navrat == 0 */
	if (navrat == EOF) {
	    printf("stdin je uzavren.\n");
	    return 1;
	}
    } while ((iterace < 0) || (iterace > 10));

    while (iterace) {
	printf("%i ", iterace--);
    }

    printf("\n");
    return 0;
}

 /*------------------------------------------------*/
