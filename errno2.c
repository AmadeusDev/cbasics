/*------------------------------------------------*/
/* errno2.c                                       */

#include <stdio.h>
#include <errno.h>
#include <math.h>

double logaritmus(double x)
{
    double y;
    y = log(x);

    switch (errno) {
    case 0:
	perror(NULL);
	printf("log(%f) = %f.\n", x, y);
	return y;
    default:
	perror("Hlaseni");
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
