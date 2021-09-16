/*------------------------------------------------*/
/* errno1.c                                       */

#include <stdio.h>
#include <errno.h>
#include <math.h>

double logaritmus(double x)
{
    double y;
    y = log(x);

    switch (errno) {
    case EDOM:
	printf("Doslo k chybe v ramci definicniho oboru funkce!\n");
	return 0;
    case ERANGE:
	printf("Doslo k chybe v ramci oboru hodnot funkce!\n");
	return 0;
    case 0:
	printf("Vse je v poradku. log(%f) = %f.\n", x, y);
	return y;
    default:
	printf("Neocekavana chyba\n");
	return 0;
    }
}

int main(void)
{
    double x;

    x = logaritmus(2.718281828);
    x = logaritmus(-5);
    x = logaritmus(9999999999);	/* prilis velke cislo */
    x = logaritmus(0);
    return 0;
}

/*------------------------------------------------*/
