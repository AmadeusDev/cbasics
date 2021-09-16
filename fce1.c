/*------------------------------------------------*/
/* fce1.c                                         */
#include <stdio.h>

void tecka(int pocet)
{
    if (pocet <= 0)
	return;			/* kdyby byl pocet unsigned int, bylo by tohle
				   zbytecne */
    /* kdyz se podivate na podminku v cyklu tak
     * zjistite, ze je to zbytecne stejne :-) */
    for (; pocet > 0; pocet--)
	printf(". ");
}

int mocnina(int x)
{
    return x * x;
}

int main(void)
{
    tecka(10);
    printf("-5^2 = %i\n", mocnina(-5));
    return 0;
}

/*------------------------------------------------*/
