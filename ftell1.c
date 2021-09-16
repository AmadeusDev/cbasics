/*------------------------------------------------*/
/* ftell1.c                                       */

#include <stdio.h>


int main(void)
{
    FILE *soubor;
    unsigned int i;
    char pole[100];
    soubor = fopen("pokus.txt", "w+t");

    /* nejdrive zapiseme do souboru nekolik znaku 'a' */
    for (i = 0; i < 50; i++)
	fputc('a', soubor);

    /* posuneme kurzor za prvnich 5 bajtu */
    fseek(soubor, 5L, SEEK_SET);
    /* zapiseme 5 znaku '-' */
    for (i = 0; i < 5; i++)
	fputc('-', soubor);

    /* posuneme se na konec souboru a zjistime jeho velikost */
    fseek(soubor, 0L, SEEK_END);
    printf("Velikost souboru je %lu bajtu.\n", ftell(soubor));

    /* presuneme se opet na zacatek souboru a precteme jeho obsah */
    fseek(soubor, 0L, SEEK_SET);
    while (!feof(soubor)) {
	fgets(pole, sizeof(pole) / sizeof(char) - 1, soubor);
	printf("%s", pole);
    }
    printf("\n");
    fclose(soubor);
    return 0;
}

/*------------------------------------------------*/
