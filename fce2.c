/*------------------------------------------------*/
/* fce2.c                                         */
#include <stdio.h>
#include <stdarg.h>

int maximum(const int pocet, const int znamenko, ...)
{
    va_list ap;
    int i;
    int maxS, dalsiS;
    unsigned int maxU, dalsiU;

    if (pocet <= 0)
	return 0;

    va_start(ap, znamenko);	/*  znamenko je posledni deklarovana promenna */

    if (znamenko)
	maxS = va_arg(ap, int);
    else
	maxU = va_arg(ap, unsigned int);

    for (i = 0; i < pocet - 1; i++) {
	if (znamenko) {
	    dalsiS = va_arg(ap, int);
	    maxS = (maxS < dalsiS) ? dalsiS : maxS;
	} else {
	    dalsiU = va_arg(ap, unsigned int);
	    maxU = (maxU < dalsiU) ? dalsiU : maxU;
	}
    }

    va_end(ap);
    if (znamenko)
	return maxS;
    else
	return (signed int) maxU;
}

int main(void)
{
    printf("Maximum = %i\n", maximum(3, 1, 7, 9, -2));
    printf("Maximum = %x\n", maximum(7, 1, -5, 8, -2, 5, -6, -1, 4));
    printf("Maximum = %x\n", maximum(7, 0, -5, 8, -2, 5, -6, -1, 4));
    return 0;
}

 /*------------------------------------------------*/
