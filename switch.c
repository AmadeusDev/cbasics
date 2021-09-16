 /*------------------------------------------------*/
 /* switch.c                                       */
#include <stdio.h>

int main(void)
{
    char znak;

    printf("Opravdu chcete smazat vsechny data na disku? [a/n/k]> ");
    znak = (char) getchar();

    switch (znak) {
    default:
	printf("Mel si zmacknout \'a\',\'n\' nebo \'k\' a ne \'%c\'\n",
	       znak);
    case 'k':
	return 0;
    case 'N':
	printf("Stejne smazu co muzu!\n");
	break;
    case 'n':
	printf("Nechcete? Smula!\n");
    case 'a':
    case 'A':
	printf("Data byla smazana !!!\n");
	break;
    }
    printf("Ne, nebojte, to byl jenom zertik.\n");
    return 0;
}

/*------------------------------------------------*/
