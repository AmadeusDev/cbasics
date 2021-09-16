/*------------------------------------------------*/
/* faktor.c                                       */
#include <stdio.h>

long double faktorial(long double x)
{
    if (x == 0L)
	return 1L;
    return x * faktorial(x - 1L);
}

int main(void)
{
    int i;
    for (i = 0; i <= 40; i++)
	printf("%2i! = %040.0Lf\n", i, faktorial(i));
    return 0;
}

/*------------------------------------------------*/
