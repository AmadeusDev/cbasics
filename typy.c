/*------------------------------------------------*/
/* typy.c                                         */

#include <stdio.h>
int a;

int main(void)
{
    /* deklarace promennych */
    unsigned int b;
    float c;

    a = 5;
    b = 11;
    a = a / 2;
    c = 5.0;
    printf("a=%i\nb=%u\nc=%f\n", a, b, c / 2);

    return 0;
}

/*------------------------------------------------*/
