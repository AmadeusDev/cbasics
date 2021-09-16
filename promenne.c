/*------------------------------------------------*/
/* promenne.c                                     */
#include <stdio.h>

int a = 0, b = 0, c = 0;	/* globalni promenne */

void funkce(int a, int b)
{
    int a = -5;			/* lokalni promenne */
    printf("fce: a = %i, b = %i, c = %i\n", a, b, c);
}

int main(void)
{
    int c = 25;

    printf("main: a = %i, b = %i, c = %i\n", a, b, c);
    funkce(100, 200);
    return 0;
}

/*------------------------------------------------*/
