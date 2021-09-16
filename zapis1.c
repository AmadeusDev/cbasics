/*------------------------------------------------*/
/* zapis1.c                                       */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifdef unix
#include <unistd.h>
#else
#include <io.h>
#endif

#define POCET_CYKLU 1000000u

#ifdef unix
#define OPEN open("jmeno.txt",O_RDWR|O_CREAT|O_TRUNC,\
		S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#else
#define OPEN open("jmeno.txt",O_RDWR|O_CREAT|O_TRUNC|O_TEXT)
#endif


int main(void)
{
    int id;
    unsigned long i;
    char SNO[] = "Soubor nelze otevrit\n";
    char TEXT1[] = "Tenhle text budeme zapisovat do souboru\n";
    char TEXT2[] = "-------------- prepsano ---------------\n";

    if ((id = OPEN) <= 0) {
	/* fprintf by bylo vhodnejsi, ale nemohl jsem si to odpustit :-} */
	write(fileno(stderr), SNO, strlen(SNO));
	exit(1);
    }

    for (i = 0L; i < POCET_CYKLU * 10u; i++) {
	if (write(id, TEXT1, strlen(TEXT1)) == -1) {
	    fprintf(stderr, "Data nelze zapisovat");
	    exit(1);
	}
    }


    lseek(id, 0, SEEK_SET);
    for (i = 0L; i < POCET_CYKLU; i++) {
	if (write(id, TEXT2, strlen(TEXT2)) == -1) {
	    fprintf(stderr, "Data nelze zapisovat");
	    exit(1);
	}
#ifdef unix
#define clrf 0
#else
#define clrf 1
#endif
	lseek(id, (strlen(TEXT1) + clrf) * 9, SEEK_CUR);
#undef clrf
    }

    close(id);			/* spravne by bylo kontrolovat navratovou hodnotu */
    return 0;
}

/*------------------------------------------------*/
