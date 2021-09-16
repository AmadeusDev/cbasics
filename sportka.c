/*------------------------------------------------*/
/* sportka.c                                      */

#include <stdio.h>
#include <stdlib.h>		/* zde jsou definovany funkce rand() a srand() */
#include <time.h>

#define CENA 16			/* korun za vsazeni 1 sloupce */

/* funkce uhodnuto zjisti, kolik cisel z pole cisla[6] je stejnych jako v poli
 * prvnich 6 cisel v poli tah[7]. Posledni cislo v tomto poli je dodatkove!  */

unsigned int uhodnuto(unsigned int *cisla, unsigned int *tah)
{
    unsigned int i, j, vyhra = 0;

    for (j = 0; j < 6; j++)
	for (i = 0; i < 6; i++)
	    if (cisla[j] == tah[i]) {
		vyhra++;	/* pocet uhadnutych cisel */
		break;		/* ukonci vnitrni cyklus */
	    }
    return vyhra;
}

 /* funkce vyhra_sportky urci na zaklade uhodnutych cisel co jste vyhrali.
  * Pokud jste uhodli 5 cisel a 6te je stejne jako dodatkove, pak mate "druhou" */
unsigned int vyhra_sportky(unsigned int uhodnute, unsigned int *cisla,
			   unsigned int *tah)
{
    unsigned int i, vyhra = 0;
    switch (uhodnute) {
    case 6:
	vyhra = 1;		/* mate prvni */
	break;
    case 5:
	vyhra = 3;		/* mate treti */
	/* ale mozna mame druhou */
	for (i = 0; i < 6; i++)
	    if (cisla[i] == tah[6]) {
		vyhra = 2;	/* mame druhou */
		break;
	    }
	break;
    case 4:
	vyhra = 4;
	break;
    case 3:
	vyhra = 5;		/* mate patou */
	break;
    default:			/* to je tu trosku zbytecne,
				   protoze vyhra = 0 je jiz vyse, ale rozhodne to neni na
				   skodu uz kvuli srozumitelnosti kodu */
	vyhra = 0;		/* nic jste nevyhrali */
    }
    return vyhra;
}

 /* tato funkce urci, kolik penez jste vyhrali */
unsigned long penez(unsigned int vyhra)
{
    switch (vyhra) {
    case 5:
	return rand() % 50 + 30;
    case 4:
	return rand() % 500 + 250;
    case 3:
	return rand() % 5000 + 1000;
    case 2:
	return rand() % 500000 + 50000;
    case 1:
	return (unsigned long) ((rand() % 1000000) + 1) * (rand() % 10) +
	    1000000;
    default:
	return 0;
    }
}

/* kontroluje, zda cislo exituje v poli zadane delky */
int existuje(unsigned int cislo, unsigned int *pole, unsigned int delka)
{
    unsigned int i;
    for (i = 0; i < delka; i++)
	if (cislo == pole[i])
	    return 1;
    return 0;			/* cislo se nenaslo */
}

int main(void)
{
    unsigned int i, cisla[6], tah[7], vyhra, uhodnute, finance, vyhrano;
    unsigned int chci_vyhrat;
    unsigned long vyhry[] = { 0, 0, 0, 0, 0, 0 };	/* nic, prvni, druha, treti ...
							   vyhra "nic" bude zrejme velmi casto,
							   proto je pole typu long int */
    unsigned long cyklus = 0;
    time_t cas1, cas2;

    (void) time(&cas1);		/* navratovou hodnotu ignorujeme */
    srand((unsigned int) time(NULL));	/* vystupni hodnotu musime z formatu
					   time_t zkonvertovat na typ unsigned int */

    /* inicializace */
    vyhrano = 0;

    printf("Zadejte poradi, ktere chcete vyhrat (0,1,2,3,4,5): ");
    scanf("%u", &chci_vyhrat);

    /* losovani vsazenych cisel do sportky */
    for (i = 0; i < 6; i++) {
	cisla[i] = (rand() % 49) + 1;
	if (existuje(cisla[i], cisla, i))
	    i--;		/* cislo jiz bylo vylosovano,
				   bude se losovat znovu */
    }

    /* tisk */
    printf("Vsazena cisla:");
    for (i = 0; i < 6; i++)
	printf("%3u", cisla[i]);
    printf("|\n");

    printf("Cyklus  :%-23s| Vyhrano   Vyhry:  1  2  3  4  5  0\n",
	   " Vylosovane Cisla");

    /* cyklus, dokud nevyhraji co chci */
    do {
	/* losovani sportky */
	for (i = 0; i < 7; i++) {
	    tah[i] = (rand() % 49) + 1;
	    if (existuje(tah[i], tah, i))
		i--;		/* cislo jiz bylo vylosovano,
				   bude se losovat znovu */
	}

	/* tisk vysledku */
	printf("\r%8ld:", ++cyklus);

	for (i = 0; i < 6; i++)
	    printf("%3u", tah[i]);
	printf(" /%3u", tah[6]);	/* dodatkove cislo */

	uhodnute = uhodnuto(cisla, tah);	/* pocet uhodnutych cisel */
	vyhra = vyhra_sportky(uhodnute, cisla, tah);	/* prvni, druha atp. */
	finance = penez(vyhra);
	vyhry[vyhra] += 1;	/* vyhry[vyhra]++; */

	vyhrano += finance;
	printf("|%10ld[Kc]   ", (unsigned long) vyhrano - cyklus * CENA);

	for (i = 1; i < 6; i++)
	    printf(" %2ld", vyhry[i]);

	printf(" %2ld", vyhry[0]);
	/* funkce fflush() zajisti, ze program nebude pokracovat dale, dokud se
	 * vystup skutecne nezobrazi v stdout (tj. na obrazovce) */
	fflush(stdout);
	if (!chci_vyhrat)
	    break;		/* nechci nic vyhrat, tj. chci_vyhrat == 0 */
    } while ((chci_vyhrat < vyhra) || (vyhra == 0));

    cas2 = time(NULL);		/* ziskame totez jako (void) time(&cas2); */
    printf("\nZiskal jste %i - %i*%ld = %ld Kc\n", vyhrano, CENA, cyklus,
	   vyhrano - CENA * cyklus);
    printf("Cele to trvalo %u vterin.\n",
	   (unsigned int) difftime(cas2, cas1));

    return 0;
}

 /*------------------------------------------------*/
