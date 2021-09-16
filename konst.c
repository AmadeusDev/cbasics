/*------------------------------------------------*/
/* konst.c                                        */

#include <stdio.h>

int main(void)
{
    const a = 5;		/* konstantu a vyhodnoti prekladac jako int 5 */
    const b = 5.9;		/* konstantu b vyhodnoti prakladac jako int 5 */
    const float c = 5;		/* konstanta c je urcena jako float,tj. 5.0 */
    int i = 0;

    printf("a/2 = %f\n", (a / 2) * 1.0);	/* celociselne deleni ... */
    printf("b/2 = %f\n", (b / 2) * 1.0);	/* celociselne deleni ... */
    printf("c/2 = %f\n\n", (c / 2) * 1.0);	/* deleni s des. carkou ... */

    printf("Mala nasobilka pro cislo %i\n\n", a);
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);
    i = i + 1;
    printf("%i * %i = %i\n", a, i, i * a);

    return 0;
}

/*------------------------------------------------*/
