/*------------------------------------------------*/
/* konst2.c                                       */

#include <stdio.h>

int main(void)
{
    const char Kpismeno = 'a';	/* konstanta */
    char pismeno = 'b';
    const char *veta = "Konstantni veta !\n";
    const char *veta2 = "a";
    char *ukazatel;		/* ukazatel na typ char */

    ukazatel = &pismeno;	/* ukazatel ukazuje na promennou pismeno */

    printf("1: Tisknu pismena: %c %c\n", Kpismeno, pismeno);

    printf("2: Tisknu vetu: %s", veta);
    printf("3: Tisknu vetu: %s\n", veta2);

    printf("4: Tisknu pismeno: %c\n", *ukazatel);

    printf("5: Tisknu pismeno: %c\n", *veta);
    printf("6: Tisknu pismeno: %c\n", *veta2);

    return 0;
    printf("7: Tisknu vetu: %s\n", ukazatel);
    printf("8: Tisknu vetu: %s\n", pismeno);
    /* printf("9: Tisknu: %s\n",*pismeno); uplna blbost */
}

/*------------------------------------------------*/
