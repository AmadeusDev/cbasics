/*------------------------------------------------*/
/* pole1.c                                        */

#include <stdio.h>

int main(void)
{

    float pole[] = { 5.0, 6.0, 7.0, 8.0, 9.0 };
    float *ukazatel;

    ukazatel = pole;

    /* prvni cast */
    printf("%.1f ", pole[1]);
    printf("%.1f ", pole[1] + 10.0);
    printf("%.1f, ", (pole + 1)[2]);

    /* druha cast */
    printf("%.1f ", *ukazatel);
    printf("%.1f ", *ukazatel + 10);
    printf("%.1f\n", *(ukazatel + 1));

    return 0;
}

/*------------------------------------------------*/
