/*------------------------------------------------*/
/* mudrc.c                                        */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    printf("\n***************************\n");
    printf("* mudrc rika:             *\n");
    switch (argc) {
    case 1:
	printf("* Kdo to rusi me kruhy?   *\n");
	break;
    default:
	printf("* Argumenty:              *\n");
	/* Prvni argument je nazev programu (preskocime ho). Muze to byt napr. 
	 * "c:\mudrc.exe" nebo jen "mudrc". Zalezi to jednak na OS a v 
	 * nasem pripade take na funkci, ktera tento program bude volat.*/
	for (i = 1; i < argc; i++) {
	    printf("* %2i) %-19s *\n", i, argv[i]);
	}
	break;
    }
    printf("***************************\n\n");
    return 0;
}

/*------------------------------------------------*/
