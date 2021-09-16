/*------------------------------------------------*/
/* union.c                                        */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    znak, cele, racionalni
} typ;

typedef union {
    char ch;
    unsigned int uin;
    float fl;
} datovy_typ;

datovy_typ nahodne_cislo(typ t)
{
    datovy_typ x;

    switch (t) {
    case znak:
	x.ch = (char) (rand() % ('z' - 'a')) + 'a';
	break;
    case cele:
	x.uin = (unsigned int) rand();
	break;
    case racionalni:
	x.fl = (float) rand() / RAND_MAX;
	break;
    }
    return x;
}

int main(void)
{
    datovy_typ un;

    printf("Zadej cislo: ");
    if (scanf("%u", &un.uin) == 0)
	return 1;

    srand(un.uin);
    un = nahodne_cislo(racionalni);
    printf("float = %f\n", un.fl);

    un = nahodne_cislo(znak);
    printf("char = %c\n", un.ch);

    un = nahodne_cislo(cele);
    printf("int = %i\n", un.uin);

    printf("velikost un = %u == float = %u\n", sizeof(un), sizeof(float));
    return 0;
}

/*------------------------------------------------*/
