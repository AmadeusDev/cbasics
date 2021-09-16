/*------------------------------------------------*/
 /* dynamic3.c                                     */

#include <stdio.h>
#include <stdlib.h>

#define MAXSLOVO 20
#define NACTISLOVO "%20s"

struct veta {
    unsigned int poradi;
    char slovo[MAXSLOVO + 1];
    struct veta *dalsi;		/* ukazatel na dalsi strukturu */
};


/* pomocna funkce na kopirovani retezce */
void strcopyruj(char *cil, const char *zdroj)
{
    unsigned int i = 0;
    do {
	cil[i] = zdroj[i];
    } while (zdroj[i++]);
}


/* funkce vypisujici seznam */
void vypis_veta(struct veta *zacatek)
{
    struct veta *dalsi;

    dalsi = zacatek;
    printf("\n");
    do {
	if (strcmp(dalsi->slovo, ""))	/* prazdne slova ignoruj */
	    printf("%3i: %s\n", dalsi->poradi, dalsi->slovo);
	dalsi = dalsi->dalsi;	/* prejdi na dalsi slovo */
    }
    while (dalsi != NULL);
}


void setrid_seznam(struct veta *zacatek)
{
    int zmena = 0;
    struct veta *dalsi, pom;

    dalsi = zacatek;
    if (dalsi == NULL)
	return;

    do {
	/* dosli jsme na konec a nic se nezmenilo?
	   pak mame setrideno */
	if ((dalsi->dalsi == NULL) && (zmena == 0))
	    break;
	else if (dalsi->dalsi == NULL) {
	    dalsi = zacatek;
	    zmena = 0;
	}
	if (strcmp(dalsi->slovo, dalsi->dalsi->slovo) > 0) {
	    pom = *dalsi;
	    strcopyruj(dalsi->slovo, dalsi->dalsi->slovo);
	    dalsi->poradi = dalsi->dalsi->poradi;
	    strcopyruj(dalsi->dalsi->slovo, pom.slovo);
	    dalsi->dalsi->poradi = pom.poradi;
	    zmena = 1;
	}
	dalsi = dalsi->dalsi;
    } while (1);
}


/* Nasleduje funkce pro uvolneni pameti. Prvni polozka je staticka, proto se
 * pomoci free() neuvolnuje a take se musi jeji atribut "dalsi" nastavit
 * na NULL */

void zabij(struct veta *zacatek)
{
    struct veta *v, *pom;

    v = zacatek->dalsi;
    while (v != NULL) {
	pom = v->dalsi;
	free(v);
	v = pom;
    }
    zacatek->dalsi = NULL;
}

int main(void)
{
    unsigned int poradi;
    int navrat;
    struct veta prvni, *posledni;

    printf("Zadavejte slova ne delsi nez %i znaku.\n"
	   "Zadavani vet ukoncete pomoci znaku konec souboru.\n"
	   "(tj. CTRL+D v unixech nebo CTRL+Z v DOSu a Windows)\n\n",
	   MAXSLOVO);

    poradi = 0;
    posledni = &prvni;		/* "prvni" je prvni prvek ze seznamu. Ukazatel
				   "posledni" ukazuje na posledni prvek v seznamu. */
    do {
	poradi++;
	navrat = scanf(NACTISLOVO, posledni->slovo);
	posledni->poradi = poradi;
	if ((navrat == EOF) || (navrat != 1)) {
	    /* EOF * -> konec vstupu,
	     * navrat  !=1 -> nebyl nacten spravne retezec */
	    /* dalsi prvek v seznamu jiz nebude. seznam ukoncime
	       zarazkou NULL */
	    posledni->dalsi = NULL;
	    break;
	}
	if ((posledni->dalsi = (struct veta *)
	     calloc(1, sizeof(struct veta))) == NULL) {
	    printf("Nedostatek pameti!\n");
	    exit(1);
	}
	posledni = posledni->dalsi;
    } while (1);

    setrid_seznam(&prvni);
    vypis_veta(&prvni);
    zabij(&prvni);

    return 0;
}

 /*------------------------------------------------*/
