/*------------------------------------------------*/
/* konec.c                                        */

#include <stdio.h>
#include <stdlib.h>

void koncim1(void)
{
    printf("Elektrina odpojena!\n");
}

void koncim2(void)
{
    printf("Systemy vypnuty!\n");
}

int main(int argc, char *argv[])
{

    atexit(koncim1);
    atexit(koncim2);		/* nejdrive probehne funkce koncim2 a pak koncim1,
				   tedy v obracenem poradi nez byli registrovany */

    if (argc != 2) {
	printf("Na prikazove radce nebyla zadana navratova hodnota!\n");
	abort();
    }
    exit(atoi(argv[1]));

    return 0;			/* tato cast programu za exit nikdy neprobehne */
}

/*------------------------------------------------*/
