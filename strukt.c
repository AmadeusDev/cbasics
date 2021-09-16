/*------------------------------------------------*/
/* strukt.c                                       */
#include <stdio.h>

#define POCET 40
 /* funkce zkopiruj kopiruje retezec v2 do retezce v1,
  * vcetne zarazky '\0' na konci retezce.           */
void zkopiruj(char *v1, char *v2)
{
    int i = 0;
    do {
	v1[i] = v2[i];
    } while (v2[i++]);
}

struct Pisen {
    char nazev[POCET];
    char zpevak[POCET];
    char skladatel[POCET];
    float delka, hodnoceni;
} pisne[10], *ukp;

void vytiskni(void *str);	/* deklarujeme funkci,
				   ktera bude tisknout strukturu Pisen */

int main(void)
{
    struct Pisen pisen;

    zkopiruj(pisen.nazev, "Twist And Shout");
    zkopiruj(pisen.zpevak, "The Beatles");
    zkopiruj(pisen.skladatel, "Lennon/McCartney");
    pisen.delka = 2.36;
    pisen.hodnoceni = 1.0;

    pisne[0] = pisen;

    zkopiruj(pisne[1].nazev, "Eleanor Rigby");
    zkopiruj(pisne[1].zpevak, "The Beatles");
    zkopiruj(pisne[1].skladatel, "Lennon/McCartney");
    pisne[1].delka = 2.06;
    pisne[1].hodnoceni = 1.5;

    ukp = &pisne[2];		/* do ukazatele na strukturu Pisen ukladame adresu
				   tretiho prvku v poli pisne */
    zkopiruj(ukp->nazev, "From Me To You");
    zkopiruj(ukp->zpevak, "The Beatles");
    zkopiruj(ukp->skladatel, "Lennon/McCartney");
    ukp->delka = 1.58;
    ukp->hodnoceni = 1.25;

    vytiskni(&pisne[0]);
    vytiskni(&pisne[1]);
    vytiskni(&pisne[2]);

    return 0;
}

void vytiskni(void *str)
{
    /* str ukazuje na zacatek struktury */
    printf("Nazev pisne:\t%s\n", (char *) str);

    str += POCET * sizeof(char);	/* delka pole "nazev" ve strukture */
    /* str ukazuje za pole "nazev" ve strukture, tj. na
     * zacatek pole "zpevak" */
    printf("Interperet:\t%s\n", (char *) str);

    str += POCET * sizeof(char);
    printf("Skladatel(e):\t%s\n", (char *) str);

    str += POCET * sizeof(char);
    printf("Delka skladby:\t%.2f\n", *((float *) str));

    str += 1 * sizeof(float);
    printf("Hodnoceni:\t%.2f\n\n", *((float *) str));
}

/*------------------------------------------------*/
