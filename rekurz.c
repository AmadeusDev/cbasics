/*------------------------------------------------*/
/* rekurz.c                                       */
#include <stdio.h>

float prvni_funkce(int, float);	/* deklarace */

float druha_funkce(int a, float f)
{				/* definice */
    printf("Vola se druha funkce\n");
    return prvni_funkce(a, f * (a + 1));
}

float prvni_funkce(int a, float f)
{				/* definice */
    printf("Prvni funkce a= %2i, f=%5.2f\n", a, f);
    if (a <= 0)
	return f;
    return druha_funkce(--a, f);
}

int main(void)
{
    printf("Vysledek je %f\n", prvni_funkce(5, 5.0));
    return 0;
}

/*------------------------------------------------*/
