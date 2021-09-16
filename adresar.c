/*------------------------------------------------*/
/* adresar.c                                      */

#include <stdio.h>
#include <errno.h>
#ifdef unix
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#else
#include <dir.h>
#endif

#define ADRESAR "DATADIR"
#define SOUBOR  "ahoj.txt"

#ifdef unix
#define MKDIR(X) mkdir(X,0777)
#else
#define MKDIR(X) mkdir(X)
#endif

int errkonec(void)
{
    perror("CHYBA");
    fprintf(stderr, "Stisknete ENTER pro ukonceni ...\n");
    (void) getchar();
    return errno;
}

int main(void)
{
    char text[255];
    FILE *soubor;
    char c;

    getcwd(text, sizeof(text) / sizeof(text[0]));
    printf("Vytvarim v adresari %s podadresar %s\n", text, ADRESAR);


    if (MKDIR(ADRESAR) != 0) {
	return errkonec();
    }

    printf("Vstupuji do adresare %s\n", ADRESAR);
    if (chdir(ADRESAR) != 0) {
	return errkonec();
    }

    printf("Vytvarim soubor %s\n", SOUBOR);

    if (!(soubor = fopen(SOUBOR, "wr")))
	return errkonec();

    fprintf(soubor, "Ahoj");
    fclose(soubor);
    printf("Mam zase vse smazat? [y/n] ");
    c = getchar();
    if (c == 'n') {
	fputs("Koncim.", stdin);
	return 0;
    } else if (c != 'y') {
	fputs("Nechapu, koncim.", stdin);
	return 0;
    }

    /* mazani souboru a adresare */
    printf("Mazu soubor %s\n", SOUBOR);
    if (unlink(SOUBOR) != 0) {
	return errkonec();
    }

    printf("Opoustim adresar %s\n", ADRESAR);
    /* prechod v adresarove strukture o adresar vyse */
    if (chdir("..") != 0) {
	return errkonec();
    }

    printf("Mazu adresar %s\n", ADRESAR);
    if (rmdir(ADRESAR) != 0) {
	return errkonec();
    }

    return 0;
}

/*------------------------------------------------*/
