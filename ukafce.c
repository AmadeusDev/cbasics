/*------------------------------------------------*/
/* ukafce.c                                       */

#include <stdio.h>
#include <stdlib.h>

 /* nejdrive vytvorime strukturu, ktera bude obsahovat nejake pojmenovani
  * funkce pro uzivatele programu, cislo funkce, bude zaznamenavat pocet
  * spusteni funkce a ukazatel na funkci */
typedef struct {
    unsigned int cislo;
    char nazev[50];
    unsigned int spusteno;
    void (*ukfce) (unsigned int *, char *);
} robot;

 /* nyni definujeme funkce programu, ktere budou uzivateli nabizeny pomoci
  * predchozi struktury */
/* zobrazi pouze velka pismena */
void velka_pismena(unsigned int *spusteno, char *v)
{
    int i = 0;
    (*spusteno)++;
    do {
	if ((v[i] >= 'A') && (v[i] <= 'Z')) {
	    printf("%c", v[i]);
	}
    } while (v[i++]);
    printf("\n");
}

/* zobrazi pouze mala pismena */
void mala_pismena(unsigned int *spusteno, char *v)
{
    int i = 0;
    (*spusteno)++;
    do {
	if ((v[i] >= 'a') && (v[i] <= 'z')) {
	    printf("%c", v[i]);
	}
    } while (v[i++]);
    printf("\n");
}

/* zobrazi vse, co neni pismeno */
void nepismena(unsigned int *spusteno, char *v)
{
    int i = 0;
    (*spusteno)++;
    do {
	if (!(((v[i] >= 'a') && (v[i] <= 'z')) ||
	      ((v[i] >= 'A') && (v[i] <= 'Z')))) {
	    printf("%c", v[i]);
	}
    } while (v[i++]);
    printf("\n");
}

/* zobrazi text pozpatku */
void obrat_text(unsigned int *spusteno, char *v)
{
    int i = 0;
    if (*spusteno >= 2) {
	printf("Pro dalsi pouziti teto funkce se musite registrovat!\n");
	return;
    }
    (*spusteno)++;

    while (v[i++]);		/* hledame konec retezce */

    for (i--; i >= 0; i--)
	printf("%c", v[i]);

    printf("\n");
}

/* vlozi do textu mezery */
void roztahni(unsigned int *spusteno, char *v)
{
    int i = 0;
    (*spusteno)++;
    while (v[i]) {
	printf("%c ", v[i++]);
    };
    printf("\n");
}

 /* funkce exit() ma jine parametry, nez ktere ocekava nas ukazatel, proto
  * jsem vytvoril funkci konec, ktera simuluje potrebu deklarovanych argumentu
  * */
void konec(unsigned int *spusteno, char *v)
{
    exit(0);			/* ukonci program  s navratovou hodnotou 0,
				   ktera znaci uspech */
}


/* funkce vlozime do pole struktury robot spolu s nazvem pro uzivatele atd. */
robot *inicializuj(void)
{
    /* pokud by promenna "r" nebyla staticka, pak by po skonceni
       volani funkce prestala existovat! */
    static robot r[] = { {1, "Velke pismena", 0, velka_pismena},
    {1, "Mala pismena", 0, mala_pismena},
    {2, "Co neni pismeno", 0, nepismena},
    {3, "Obraceni textu", 0, obrat_text},
    {4, "Roztazeni textu", 0, roztahni},
    {5, "Ukonceni", 0, konec},
    {0, "", 0, NULL}		/* "zarazka", podle ktere pozname, ze jsme na konci */
    };
    return r;
}


int main(void)
{
    int i, navrat;
    robot *rb;			/* ukazatel na pole struktury robot */
    unsigned int cislo;		/* funkce jsou ve strukture ocislovany,
				   dle tohoto cisla budou vybirany */
    char retezec[51];		/* maximalne 50 znaku + '\0' */

    rb = inicializuj();		/* funkce inicializuj() vraci ukazatel na svou
				   statickou promennou. At ji zavolate kolikrat
				   chcete, bude ukazovat stale na to same pole.
				   O tom, jak vytvaret nove promenne za behu programu
				   si povime pozdeji. */
    do {
	i = 0;
	do {
	    /* zobrazeni menu - snadne a prehledne */
	    printf("%2i)\t%s\t(%2i)\n", rb[i].cislo, rb[i].nazev,
		   rb[i].spusteno);
	} while (rb[++i].ukfce != NULL);

	printf("Vyber polozku dle cisla a zadejte retezec: ");

	/* vysledek prirazeni muzeme pouzit jako hodnotu
	   (tak ho rovnou porovname s EOF) */
	if ((navrat = scanf("%u %50s", &cislo, retezec)) == EOF)
	    break;
	else if (navrat != 2) {	/* chybne nacteni polozek */
	    printf("\n Chyba vstupu (%i)!\n", navrat);
	    /* Zrejme nebylo zadano jako prvni cislo, ale retezec.
	     * Ten se musi nyni nacist, jinak by se jej predchozi funkce
	     * scanf pokousela v cyklu neustale nacitat jako cislo a tim
	     * by cyklus nikdy neskoncil
	     * Promenna retezec muze obsahnout maximalne 50 znaku, proto
	     * funkci scanf v prvnim argumentu urcime max. delku
	     * nacitaneho retezce. */
	    scanf("%50s", retezec);
	    continue;
	}
	i = -1;
	while (rb[++i].ukfce != NULL) {	/* hledame spravnou strukturu, dokud
					   nenarazime na nami vytvorenou zarazku */
	    if (rb[i].cislo == cislo) {
		rb[i].ukfce(&rb[i].spusteno, retezec);
		/* prochazi se cele pole, takze se spusti vsechny polozky v
		 * poli, ktere maji rb[].cislo == cislo */
		/* kdyby zde byl prikaz break, provedla by se prvni nalezena
		 * polozka a dale by se jiz nic neprohledavalo */
	    }
	}
    } while (1);		/* nekonecny cyklus, ukonci se jen pomoci return nebo
				   break (nebo exit ukonci program) */

    printf("\nAstalavista !\n");
    return 0;
}

/*------------------------------------------------*/
