/*------------------------------------------------*/
/* feof1.c                                        */

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define NAZEV "cisla.txt"

int zavri_soubor(FILE * soubor)
{
    if (fclose(soubor) == EOF) {
	fprintf(stderr, "%s %i", __FILE__, __LINE__);
	perror(NULL);
	return errno;
    }
    return 0;
}

int main(void)
{
    FILE *soubor;
    float f, suma;

    if ((soubor = fopen(NAZEV, "rt")) == NULL) {
	fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	perror(NULL);
	return errno;
    }
    suma = 0.0;
    do {
	if (fscanf(soubor, "%f", &f) == 1) {	/* ma se nacist 1 cislo */
	    printf("%.1f ", f);
	    suma += f;
	} else if (feof(soubor))	/* dosahli jsme konce souboru */
	    break;
	else if (fscanf(soubor, "%*s") != 0) {	/* preskoci retezec, ktery neni cislo */
	    fprintf(stderr, "%s %i:", __FILE__, __LINE__);
	    perror(NULL);
	    return zavri_soubor(soubor);
	}
    } while (1);

    (void) zavri_soubor(soubor);
    printf("\nSuma = %.3f\n", suma);
    return 0;
}

/*------------------------------------------------*/
