/*------------------------------------------------*/
/* typedef1.c                                     */
#include <stdio.h>

typedef int integer;

int main(void)
{
    int a, b;
    integer c, d;
    a = 5;
    b = a + 4;
    printf("a = %i, b = %i\n", a, b);

    d = (integer) a;
    c = d + 5;
    printf("d = %i, b = %i\n", (int) d, (int) c);
    return 0;
}

/*------------------------------------------------*/
