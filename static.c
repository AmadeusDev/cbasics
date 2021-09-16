/*------------------------------------------------*/
/* static.c                                       */
#include <stdio.h>

char *funkce(void)
{
    static char pole[] = "Ahoj!";
    static int x = 1000;
    int y = 1000;
    x++;
    y++;
    printf("Funkce je volana po %i (%i)\n", x, y);
    return pole;
}

int main(void)
{
    char *uk;
    printf("%s\n", funkce());

    uk = funkce();		/* pomoci ukazatele zmenim statickou promennou */
    uk[0] = 'C';
    uk[1] = 'u';
    uk[2] = 's';
    uk[3] = '\0';

    printf("%s\n", funkce());

    return 0;
}

/*------------------------------------------------*/
