/*------------------------------------------------*/
/* scan1.c                                        */

#include <stdio.h>

int main(void)
{
    int x = -1;

    printf("Zadej cislo jako konstantu jazyka C\n"
	   "napr. 10 0x0a nebo 012: ");
    scanf("%i", &x);
    printf("Zadal jsi cislo %i\n", x);
    return 0;
}

/*------------------------------------------------*/
