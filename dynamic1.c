/*------------------------------------------------*/
/* dynamic1.c                                     */

#include <stdio.h>
#include <stdlib.h>

 /* funkce pro setrideni pole od nejmensiho do nejvetsiho */
void setrid(unsigned int delka, float pole[])
{
    unsigned int i, j;
    float pom;
    if (delka <= 1)
	return;

    for (j = 0; j < delka - 1; j++) {
	i = 0;
	do {
	    if (pole[i] > pole[i + 1]) {
		pom = pole[i];
		pole[i] = pole[i + 1];
		pole[i + 1] = pom;
	    }
	    i++;
	} while (i < delka - 1);
    }
}

int main(void)
{
    unsigned int i;
    unsigned int *ui;		/* ukazatel na dynamicky alokovane cislo, ktere bude urcovat
				   delku pole pro tridene cisla. V tomto pripade by bylo
				   lepsi pouzit statickou promennou (jako unsigned int i); je to
				   tu tak udelano jen pro nazorny priklad */
    float *uf;			/* ukazatel na dynamicky alokovane pole, do ktereho budou
				   ulozeny tridene cisla */


    ui = (int *) malloc(sizeof(int));
    if (ui == NULL) {		/* jeden mozny zpusob kontroly */
	printf("Nedostatek pameti!\n");
	return 0;
    }

    printf("Zadejte pocet cisel: ");
    scanf("%u", ui);		/* u funkce scanf by se melo kontrolovat, zda skutecne
				   nacetla to, co mela. Pro strucnost prikladu to nedelam */

    /* pozadam o tolik bytu, kolik ma typ float krat velikost pole */
    if ((uf = (float *) malloc(sizeof(float) * (*ui))) == NULL)
	/* taky zpusob kontroly :-) */
    {
	printf("Nedostatek pameti!\n");
	return 0;
    }

    for (i = 0; i < *ui; i++) {
	printf("Zadejte cislo [%2u]: ", i + 1);
	scanf("%f", uf + i);	/* nebo uf[i] */
    }

    setrid(*ui, uf);
    for (i = 0; i < *ui; i++) {
	printf("%5.2f ", uf[i]);	/* nebo uf + i */
    }
    printf("\n");
    free(ui);
    free(uf);
    return 0;
}

 /*------------------------------------------------*/
