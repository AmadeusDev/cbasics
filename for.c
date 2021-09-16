/*------------------------------------------------*/
/* for.c                                          */
#include <stdio.h>

int main(void)
{
    int x;

    for (x = 1; x < 10; x++) {
	if ((x % 2) != 0)
	    continue;
	printf("Sude cislo: %i\n", x);
    }
    printf("\nA nebo trochu jinak:\n\n");

    x = 1;
    for (;;) {
	if (x >= 10)
	    break;
	if ((x % 2) == 0)
	    printf("Sude cislo: %i\n", x);
	x++;
    }
    return 0;
}

 /*------------------------------------------------*/
