/*------------------------------------------------*/
/* deklar.c                                       */
#include <stdio.h>


float vypocet(int, float, float *);	/* deklarace funkce */

int main(void)
{
    float a, b;

    a = vypocet(5, 0.3, &b);
    printf("Soucet = %5.2f\nNasobek = %5.2f\n", a, b);

    return 0;
}

float vypocet(int a, float b, float *c)
{
    float f;
    *c = (float) a *b;
    f = (float) a + b;
    b = 55.5;			/* menim lokalni promenou b, to nema s promennou b ve funkci
				   main nic spolecneho */
    return f;
}

 /*------------------------------------------------*/
