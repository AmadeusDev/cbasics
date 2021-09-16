/*------------------------------------------------*/
/* cekej.c                                        */
#include <stdio.h>

#ifdef unix
#include "unix1.h"
#define VERZE "UNIX"
#define CEKEJ 100000ul
#elif defined __MSDOS__
#define VERZE "MSDOS"
#include "dos1.h"
#define CEKEJ 100
#elif defined __WINDOWS__ || defined _Windows || defined _WINDOWS || defined __WIN32__ || defined _WIN32 || defined WIN32
#include "windows1.h"
#define VERZE "WINDOWS"
#define CEKEJ 100
#endif

int main(void)
{
    int i, j;

    for (i = 0; i <= 100; i++) {
	printf("\rZdrzuji: [");
	for (j = 0; j < 10; j++) {
	    printf("%c", (j * 10 <= i) ? '.' : ' ');
	}
	printf("] %3i%%", i);
	fflush(stdout);		/* vyprazdnime standardni vystup */
	cekej(CEKEJ);		/* implementacne zavisla funkce */
    }
    printf(" OK\n");
    return 0;
}

/*------------------------------------------------*/
