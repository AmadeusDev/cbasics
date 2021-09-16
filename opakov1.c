/*------------------------------------------------*/
/* opakov1.c                                      */

#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#include "unix1.h"
#define VERZE "UNIX"
#define CEKEJ 100000ul
#elif defined __MSDOS__
#define VERZE "MSDOS"
#include "dos1.h"
#define CEKEJ 100
#elif defined __WINDOWS__ || defined __WIN16__ || defined __WIN32__ || defined __WIN64__
#include "windows1.h"
#define VERZE "WINDOWS"
#define CEKEJ 100
#endif


 /* V souboru define1.h jsou nadefinovany datove typy, ktere se pouzivaji i v
  * souboru zobraz1.h. Proto musi byt #include "define.h" pred
  * #include "zobraz1.h" */

#include "define1.h"
#include "zobraz1.h"

 /* Pokusime se nacist cisla z prikazove radky a pote zkontrolujeme, zda maji
  * rozumne hodnoty. Pokud ne, program ukoncime */

pohyb nacti_procenta(int argc, char *argv[])
{
    pohyb p = { 0, 0, 0, DELKACHUZE / 2 };
    if (argc != 3) {
	printf("Spatny pocet argumentu\n"
	       "Zadejte pravdepodobnost chuze vpred a vzad.\n");
	exit(0);
    }
    p.vpred = atoi(argv[1]);
    p.vzad = atoi(argv[2]);
    p.stop = 100 - p.vpred - p.vzad;

    if (p.stop < 0) {
	printf("Chybne zadane pravdepodobnosti\n");
	printf("Jejich soucet nesmi prekrocit 100\n");
	exit(0);
    }

    if (!(p.vpred || p.vzad)) {
	printf("Pravdepodobnost vpred nebo vzad musi byt nenulova\n");
	exit(0);
    }
    if ((p.vpred < 0) || (p.vzad < 0)) {
	printf("Pravdepodobnosti musi byt kladne!\n");
	exit(0);
    }
    return p;
}

/* nahodne vybirame smer pohybu opilce */
smer vyber_smer(const pohyb * p)
{
    int x;
    x = (rand() % 100);		/* tj. 0 - 99 */
    if (x <= p->vpred)
	return dopredu;
    if (x <= p->vpred + p->vzad)
	return dozadu;
    return stat;
}


int main(int argc, char *argv[])
{
    pohyb opilec;
    int pocet_funkci, fce, pocet;
    opilec = nacti_procenta(argc, argv);
    /* Diky tomu, ze nahodne cisla inicializujeme "nenahodne", pak pri stejne
     * zadanych procentech se bude program chovat stejne. Lepe je funkci
     * srand inicializovat treba na zaklade aktualniho casu */
    srand(opilec.vpred * opilec.vzad);
    /* NULL je ukazatel "do nikam". Jako takovy ma stejnou velikost jako
     * kterykoliv ukazatel, vcetne ukazatele na funkci.
     * Tj. sizeof(NULL) = sizeof(char *) atd. */
    pocet_funkci = sizeof(zobraz) / sizeof(NULL);

    pocet = 0;
    do {
	pocet++;
	fce = rand() % pocet_funkci;	/* vybirame nahodne funkci na zobrazeni */
	zobraz[fce] (&opilec, vyber_smer(&opilec), pocet);
	fflush(stdout);		/* vyprazdneni standardniho vystupu pred pozastavenim */
	cekej(CEKEJ);
    } while ((opilec.pozice > 2) && (opilec.pozice < DELKACHUZE - 1));

    printf("\n");
    return 0;
}

/*------------------------------------------------*/
