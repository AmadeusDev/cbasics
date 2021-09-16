/*------------------------------------------------*/
/* fopen1.c                                       */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define NAZEV "pokus.prd"

#ifndef ENOENT
#define ENOENT 2
#endif

/* vraci 0 pokud soubor existuje,
   jinak cislo chyby */
int SouborExistuje(char *nazev)
{
    FILE *soubor;
    if ((soubor = fopen(nazev, "rt")) != NULL) {
	fclose(soubor);
	return 0;		/* soubor existuje,
				   jinak by se jej nepodarilo otevrit */
    }

    if (errno == ENOENT) {
	return errno;		/* soubor neexistuje */
    }

    return errno;		/* soubor mozna existuje, ale nepodarilo
				   se jej otevrit (treba uz je otevreno prilis
				   mnoho souboru nebo nemate prava atp.) */
}



int main(void)
{
    FILE *soubor;
    char text[255];


    printf("Soubor %s %sexistuje.\n", NAZEV,
	   !SouborExistuje(NAZEV) ? "" : "ne");

    /* otevre se soubor pro cteni a pokud se to zdari,
       hned se zase zavre */

    if ((soubor = fopen(NAZEV, "rt")) == NULL) {
	strcpy(text, "Otevreni \"rt\" souboru ");
	strcat(text, NAZEV);
	perror(text);
    } else {
	printf("Soubor %s se podarilo otevrit\n", NAZEV);
	if (fclose(soubor))
	    perror("Zavirani souboru");
    }


    /* otevre se soubor pro aktualizaci, pokud neexistuje,
       bude vytvoren. Pak se hned zavre */

    if ((soubor = fopen(NAZEV, "at")) == NULL) {
	strcpy(text, "Otevreni \"at\" souboru ");
	strcat(text, NAZEV);
	perror(text);
    } else {
	printf("Soubor %s se podarilo otevrit\n", NAZEV);
	if (fclose(soubor))
	    perror(NULL);
    }

    return 0;
}

/*------------------------------------------------*/
