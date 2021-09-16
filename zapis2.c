/*------------------------------------------------*/
/* zapis2.c                                       */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POCET_CYKLU 1000000u

#define OPEN fopen("jmeno.txt","w+")

int main(void)
{
    FILE *id;
    unsigned long i;
    char SNO[] = "Soubor nelze otevrit\n";
    char TEXT1[] = "Tenhle text budeme zapisovat do souboru\n";
    char TEXT2[] = "-------------- prepsano ---------------\n";

    if ((id = OPEN) == NULL) {
	fprintf(stderr, "%s", SNO);
	exit(1);
    }

    for (i = 0L; i < POCET_CYKLU * 10u; i++) {
	if (fwrite(TEXT1, strlen(TEXT1), 1, id) != 1) {
	    fprintf(stderr, "Data nelze zapisovat");
	    exit(1);
	}
    }

    fseek(id, 0, SEEK_SET);
    for (i = 0L; i < (POCET_CYKLU); i++) {
	if (fwrite(TEXT2, strlen(TEXT2), 1, id) != 1) {
	    fprintf(stderr, "Data nelze zapisovat");
	    exit(1);
	}
#ifdef unix
#define clrf 0
#else
#define clrf 1
#endif
	fseek(id, (strlen(TEXT1) + clrf) * 9, SEEK_CUR);
#undef clrf
    }

    fclose(id);
    return 0;
}

/*------------------------------------------------*/
