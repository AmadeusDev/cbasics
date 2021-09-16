/*------------------------------------------------*/
/* operator.c                                     */

#include <stdio.h>
#include <limits.h> /* ziskame konstanty UINT_MAX a INT_MIN */

int main(void)
{
    int x, y, z;
    int pole[] = { 5, -10, 15, -20, 25, -30 };
    unsigned int delka_pole;
    x = y = z = 10;

    x = y++;
    z++;
    printf("%3d %3d %3d\n", x, y, z);
    printf("%3d %3d %3d\n", ++x, y++, ~z);
    printf("%3d %3d %3d\n", x, y, z);

    delka_pole = sizeof(pole) / sizeof(pole[0]);
    printf("Mate %2u bitovy prekladac.\n", sizeof(int) * 8);
    printf("Pole pole[] zabira %2u bytu.\n\n", sizeof(pole));

    printf("UINT_MAX = %u = %u\n", UINT_MAX, ~0); /* UINT_MAX = max velikost cisla v typu unsigned int */ 
    printf("INT_MIN = %i = %i \n", INT_MIN, 1 << ((sizeof(int)*8)-1)); /* posunu jednicku az do "nejlevejsiho bitu" */
    printf("-51 >> 1 = %i\n\n", -51 >> 1);
    printf("Zadejte index pole (od  0 do %2u): ", delka_pole - 1);

    scanf("%i", &x);
    printf("Zadal jsi %i\n", x);

    /* musi se zkontrolovat platnost zadaneho indexu pole !! */
    x = (x < 0) ? 0 : x;
    x = (x >= delka_pole) ? delka_pole - 1 : x;
    printf("pole[%u] = %i\n", x, pole[x]);

    return 0;
}

/*------------------------------------------------*/
