/*------------------------------------------------*/
/* fprintf1.c                                     */

#include <stdio.h>
#include <string.h>

#define NAZEV "textak.txt"

int main(void)
{
    FILE *soubor;
    char text[255];

    soubor = fopen(NAZEV, "a+");	/* soubor se otevre pro aktualizaci, 
					   neexistujici soubor se vytvori */
    do {
	fputs("Zadejte slovo, ktere chcete zapsat do souboru\n"
	      "a stisknete ENTER, nebo \"q\" pro ukonceni: ", stdout);
	scanf("%254s", text);
	if (!strcmp(text, "q"))
	    break;
	printf("Zapisuji >> %s <<\n", text);
	fprintf(soubor, ">> %s <<\n", text);
    } while (1);

    fclose(soubor);

    return 0;
}

/*------------------------------------------------*/
