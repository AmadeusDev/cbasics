/*------------------------------------------------*/
/* ifelse.c                                       */
#include <stdio.h>

#define CISLO 5
#define MIN 0
#define MAX 10

int main(void)
{
    int x = -1;
    int navrat;
    printf("Na jake cislo myslim? Hadej mezi %2i a %2i: ", MIN, MAX);

    navrat = scanf("%i", &x);

    if (navrat == EOF) {
	printf("\ascanf nemuze cist. Je uzavren standardni vstup stdin\n");
	return 1;		/* ukoncime funkci main -> konec programu */
    } else if (navrat != 1) {	/* chceme nacist 1 polozku */
	printf("\aNezadal jsi cislo!\n");
	return 1;
    }

    if (x < MIN)
	printf("Tak to bylo malo trochu hochu!\n");
    else if (x > MAX)
	printf("Tak to bylo trochu moc!\n");
    else if (x == CISLO)
	printf("UHADNULS :-))\n");
    else
	printf("Smula. Zkus to znovu.\n");

    return 0;
}

 /*------------------------------------------------*/
