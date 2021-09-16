/*------------------------------------------------*/
/* exec1.c                                        */

#include <stdlib.h>
#include <stdio.h>
#ifndef unix
#include <process.h>
#else
#include <unistd.h>
#endif
#include <errno.h>

int main(void)
{
    char *argv[] = { "mudrc", "prvni", "druhy", "treti", NULL };
    char *env[] = { "PATH=.", NULL };
    int navrat;

    printf("exec1: execl(\"nesmysl\",\"nesmysl\",\"argument1\",NULL);\n");

    navrat = execl("nesmysl", "nesmysl", "argument1", NULL);
    /* kdyby nesmysl existoval, nasledujici kod by jiz neprobehl */
    fprintf(stderr, "Navrat execl = %2i\n", navrat);
    perror("CHYBA EXECL");

    printf("exec1: execve(\"mudrc\", argv, env);\n");
    execve("mudrc", argv, env);
    /* pokud se podari spustit program mudrc, nasledujici kod se jiz neprovede */
    fprintf(stderr, "Navrat execl = %2i\n", navrat);
    perror("CHYBA EXECVE");

    return 0;
}

/*------------------------------------------------*/
