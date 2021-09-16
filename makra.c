/*------------------------------------------------*/
/* makra.c                                        */

#include <stdio.h>

#define N 5
#define VERSE "1.0.0"

int main(void)
{
    int pole[N];
    unsigned int x;

    printf("ANSI C:\t%s\t%i\n", __STDC__ ? "ANO" : "NE ", __STDC__);
    printf("i386:\t%s\t%s\n", __i386__ ? "ANO" : "NE ", __VERSION__);
    printf("Tento program byl prelozen %s v %s.\n"
	   "Prave jsme na radku %i.\n", __DATE__, __TIME__, __LINE__);

    printf("Zadejte index pole <0,%u>: ", N - 1);
    scanf("%u", &x);

    x = x >= N ? N - 1 : x;

    printf("Zadejte hodnotu pole[%u]: ", x);
    scanf("%i", &pole[x]);
    printf("verse programu %s\n", VERSE);

    return 0;
}

/*------------------------------------------------*/
