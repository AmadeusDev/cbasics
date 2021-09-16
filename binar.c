/*------------------------------------------------*/
/* binar.c                                        */

#include <errno.h>
#include <stdio.h>

typedef struct {
    float cisla[5];
    char text[100];
} data;

#define NAZEV "bsoub.dat"

int main(void)
{
    FILE *soubor;
    /* pole obsahuje 5 struktur typu data */
    data pole[] = { {{1.1, 1.2, 1.3, 1.4, 1.5}, "prvni struktura"},
    {{2.1, 2.2, 2.3, 2.4, 2.5}, "druha struktura"},
    {{3.1, 3.2, 3.3, 3.4, 3.5}, "treti struktura"},
    {{4.1, 4.2, 4.3, 4.4, 4.5}, "ctvrta struktura"},
    {{5.1, 5.2, 5.3, 5.4, 5.5}, "pata struktura"}
    };
    data xdata;
    size_t navrat;
    unsigned int i;

    if ((soubor = fopen(NAZEV, "wb")) == NULL) {
	/* vite co znamena "w" ? */
	fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	perror(NULL);
	return errno;
    }

    /* zapis dat do souboru - nejdriv prvnich tri a pak zbylych dvou */

    navrat = fwrite(pole, sizeof(data), 3, soubor);
    if (navrat != 3) {
	fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	perror(NULL);
	if (EOF != fclose(soubor))
	    fprintf(stderr, "S jistotou bylo zapsano %i polozek\n",
		    navrat);
	else
	    perror(NULL);
	return errno;
    }

    navrat = fwrite(pole + 3, sizeof(data) * 2, 1, soubor);
    if (navrat != 1) {
	fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	perror(NULL);
	fclose(soubor);
	fprintf(stderr, "Neni znam pocet zapsanych polozek\n");
	return errno;
    }

    /* soubor pred ctenim uzavreme a pak zase otevreme */
    if (fclose(soubor) == EOF)
	perror(NULL);

    if ((soubor = fopen(NAZEV, "rb")) == NULL) {
	fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	perror(NULL);
	return errno;
    }

    /* nyni data nacteme a vypiseme */
    do {
	navrat = fread(&xdata, 1, sizeof(xdata), soubor);
	if (navrat != sizeof(xdata)) {
	    if (feof(soubor)) {
		printf("Konec souboru!\n");
		break;
	    } else {
		perror(NULL);
		fprintf(stderr, "Bylo nacteno pouze %i bajtu "
			"z jedne polozky spravne\n", navrat);
		break;
	    }
	}

	/* vypasni jedne struktury */
	for (i = 0; i < sizeof(xdata.cisla) / sizeof(xdata.cisla[0]); i++)
	    printf("%3.1f ", xdata.cisla[i]);
	printf("%s\n", xdata.text);

    } while (!feof(soubor));

    if (fclose(soubor) == EOF)
	perror(NULL);

    return 0;
}

/*------------------------------------------------*/
