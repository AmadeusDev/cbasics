/*------------------------------------------------*/
/* dynamic4.c                                     */

#include <stdio.h>
#include <stdlib.h>

#define MEGABAJT 1024*1024

int main(void)
{
    unsigned long x, a;
    char *pom, *v = NULL;

    do {
	printf("Zadejte pocet megabajtu, 0 pro konec: ");
	scanf("%lu", &x);
	pom = (char *) realloc((void *) v, x * MEGABAJT);
	if ((pom == NULL) && (x))
	    printf("Nedostatek pameti!!\n");
	else {
	    v = pom;
	    /* vyplneni pameti jednickami.
	     * To pocitac trosilinku zamestna :-) */
	    for (a = 0; a < x * MEGABAJT; a++) {
		v[a] = '1';
	    }
	}
    } while (x);

    return 0;
}

 /*------------------------------------------------*/
