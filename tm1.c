/*------------------------------------------------*/
/* tm1.c                                          */

#include <stdio.h>
#include <time.h>
#define MAX 80

int main(void)
{
    time_t cas;
    /* jestli pracujete se strukturou tm nebo ukazatelem na tuto strukturu,
     * to je vcelku jedno, ukazu oboji. */
    struct tm gtmcas;
    struct tm *ltmcas;
    char retezec[MAX];

    cas = time(NULL);

    gtmcas = *(gmtime(&cas));
    ltmcas = localtime(&cas);

    /* vsimnete si, ze retezec vraceny funkcemi ctime a asctime je jednak
     * v anglictine a take na konci ukoncen znakem '\n' (coz je v praxi tak
     * trochu neprijemne, ze). Vyrazi LC a UTC nam kvuli tomu prejdou az na
     * dalsi radek */
    printf("Je prave \"%s\" LC\n", ctime(&cas));
    printf("Je prave \"%s\" GMT\n", asctime(&gtmcas));
    printf("Je prave \"%s\" LC\n", asctime(ltmcas));

    strftime(retezec, MAX - 1, "Je prave %A %d.%m.%Y, %I:%M %p LC",
	     ltmcas);
    printf("%s\n", retezec);
    printf("Tm(LC): %02i.%02i.%04i\n", ltmcas->tm_wday, ltmcas->tm_mon,
	   ltmcas->tm_year + 1900);
    cas = (time_t) 0;
    printf("Pocatek vseho je %s", ctime(&cas));

    return 0;
}

/*------------------------------------------------*/
