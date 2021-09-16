/*------------------------------------------------*/
/* fscanf1.c                                      */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define NAZEV "textak.txt"

int main(void)
{
    FILE *soubor;
    int i;
    float x, y, z;
    char text[255];
    /* nejdrive do souboru neco zapiseme */
    if ((soubor = fopen(NAZEV, "w")) == NULL) {
	fprintf(stderr, "Chyba zapisu do souboru %s\n", NAZEV);
	return errno;
    }

    fputs("Seznam zlomku:\n", soubor);
    for (i = 1; i <= 5; i++)
	fprintf(soubor, "%f %f %f\n", 100.0, (float) i, 100.0 / i);
    fclose(soubor);
    /* a ted to zpatky nacteme */
    if ((soubor = fopen(NAZEV, "r")) == NULL) {
	fprintf(stderr, "Chyba cteni souboru %s\n", NAZEV);
	return errno;
    }

    /* prvni radek nacteme znak po znaku */
    do {
	i = fgetc(soubor);
	fputc(i, stdout);
    } while (i != '\n');

    /* druhy radek (prvni radek s cisly) nacteme naraz */
    fgets(text, sizeof(text) - 1, soubor);
    fputs(text, stdout);

    /* zbytek nacteme po cislech */
    for (i = 1; i <= 4; i++) {
	fscanf(soubor, "%f %f %f", &x, &y, &z);
	printf("%f/%f = %f\n", x, y, z);
    }

    fclose(soubor);
    return 0;
}

/*------------------------------------------------*/
