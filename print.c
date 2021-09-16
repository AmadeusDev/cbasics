/*------------------------------------------------*/
/* print.c                                        */

#include <stdio.h>

int main(void)
{
    const char *COPYRIGHT = "(C)";
    const int ROK = 2003;

    printf("%i %u %o %x %X %f %e %G\n", -5, -5, 200, 200, 200, 10.0,
	   10.0, 10.0);
    printf("%s %i\n", COPYRIGHT, ROK);
    return 0;
}
/*------------------------------------------------*/
