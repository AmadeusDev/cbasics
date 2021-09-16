/*------------------------------------------------*/
/* pretyp.c                                       */

#include <stdio.h>

int main(void)
{
    int a, b;
    float c, d;
    char ch = 'x';

    printf("Zadej delenec: ");
    scanf("%d", &a);
    printf("Zadej delitel: ");
    scanf("%d", &b);
    c = a / b;
    d = (float) a / b;
    printf("Celociselne deleni: %+5.2f\n", c);
    printf("Racionalni deleni:  %+5.2f\n", d);

    printf("ASCII kod znaku %c je %i\n", ch, (int) ch);
    return 0;
}

/*------------------------------------------------*/
