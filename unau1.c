/*------------------------------------------------*/
/* unau1.c                                        */
#include <stdio.h>

int main(void)
{
    int x;
    int *ukazatel_na_int;
    int **ukazatel_na_ukazatel;

    int pole[] = { 5, 7, 9, 11, 13 };

    /* inicializace promennych */
    x = 25;
    ukazatel_na_int = &x;
    ukazatel_na_ukazatel = &ukazatel_na_int;

    /* pristup k promenne x */
    printf("%2d = %2d = %2d\n", x, *ukazatel_na_int,
	   *(*ukazatel_na_ukazatel));

    /* inicializace */
    ukazatel_na_int = pole;
    /*  ukazatel_na_ukazatel = &ukazatel_na_int; ... toto prirazeni je o
     *  nekolik radek vyse a hodnota ukazatel_na_ukazatel ukazuje stale na
     *  ukazatel_na_int */

    /* pristup k poli */
    printf("%2d = %2d = %2d\n", pole[0], *ukazatel_na_int,
	   **ukazatel_na_ukazatel);
    printf("%2d = %2d = %2d\n", pole[1], *(ukazatel_na_int + 1),
	   *((*ukazatel_na_ukazatel) + 1));
    return 0;
}

/*------------------------------------------------*/
