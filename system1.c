/*------------------------------------------------*/
/* system1.c                                      */

#include <stdio.h>
#include <stdlib.h>

#ifdef unix
#include <sys/wait.h>
#endif

#ifndef unix
#define WEXITSTATUS(X) X
#endif

int main(void)
{
    int navrat;

    printf("Spoustim program> konec\n");
    navrat = system("konec");
    printf("Program skoncil s navratovou hodnotou %i\n\n",
	   WEXITSTATUS(navrat));

    printf("Spoustim program> konec 5\n");
    navrat = system("konec 5");
    printf("Program skoncil (%i)\n\n", WEXITSTATUS(navrat));

    return 0;
}

/*------------------------------------------------*/
