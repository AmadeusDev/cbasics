/*------------------------------------------------*/
/* system2.c                                      */
#include <stdlib.h>
#include <stdio.h>

#ifdef unix
#include <sys/wait.h>
#endif

int main(void)
{
    printf("system2: system(\"mudrc\");\n");
    system("mudrc");
    printf("system2: system(\"mudrc Jak se vede?\");\n");
    system("mudrc Jak se vede?");
    printf("system2: Konec programu.\n");

    return 0;
}

/*------------------------------------------------*/
