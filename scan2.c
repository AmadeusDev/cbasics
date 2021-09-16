/*------------------------------------------------*/
/* scan2.c                                        */

#include <stdio.h>

int main(void)
{
    int x = 0;
    double f = 0.0;
    char znak = 'a';

    printf("Zadej jeden znak a cislo max. 2 znaky dlouhe: ");
    scanf("%c %2d", &znak, &x);
    printf("\t--- zadal jsi %c a %i\n", znak, x);

    printf("Zadej retezec a pak racionalni cislo: ");
    scanf("%*s %lf", &f);
    printf("\t--- zadal jsi %f\n", f);

    return 0;
}

/*------------------------------------------------*/
