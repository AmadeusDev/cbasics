/*------------------------------------------------*/
/* goto.c                                         */
#include <stdio.h>

int main(void)
{
    char znak;

    printf("Opravdu chcete smazat vsechny data na disku? [a/n/k]> ");
    znak = (char) getchar();

    if ((znak == 'a') || (znak == 'A'))
	goto ano;
    if (znak == 'n')
	goto ne;
    if (znak == 'N')
	goto ne2;
    if (znak == 'k')
	goto konec2;

    printf("Mel si zmacknout \'a\',\'n\' nebo \'k\' a ne \'%c\'\n", znak);
  konec2:
    return 0;

  ne2:
    printf("Stejne smazu co muzu!\n");
    goto konec;
  ne:
    printf("Nechcete? Smula!\n");

  ano:
    printf("Data byla smazana !!!\n");
  konec:
    printf("Ne, nebojte, to byl jenom zertik\n");
    return 0;
}

 /*------------------------------------------------*/
