/*------------------------------------------------*/
/* spawn1.c                                       */
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include <errno.h>

int main(void)
{

    printf
	("spawn1: spawnl(\"mudrc\",\"mudrc\",\"prvni\",\"druhy\",\"treti\",NULL);\n");
    if (spawnl(P_WAIT, "mudrc", "mudrc", "prvni", "druhy", "treti", NULL)
	== -1)
	perror("CHYBA SPAWNL");

    printf("spawn1: konec.\n");
    return 0;
}

/*------------------------------------------------*/
