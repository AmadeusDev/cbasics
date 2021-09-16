/*------------------------------------------------*/
/* enum1.c                                        */

#include <stdio.h>

typedef enum {
    vlevo, vpravo, stred, center = stred
} zarovnani;


void tiskni_znak(char ch, zarovnani zr)
{
    switch (zr) {
    case vlevo:
	printf("%c\n", ch);
	break;
    case vpravo:
	printf("%50c\n", ch);
	break;
    case stred:
	printf("%25c\n", ch);
	break;
    default:
	printf("%c%24c%25c\n", '?', '?', '?');
    }
}

int main(void)
{
    tiskni_znak('A', 50);
    tiskni_znak('X', vlevo);
    tiskni_znak('Y', center);
    tiskni_znak('Z', vpravo);
    return 0;
}

/*------------------------------------------------*/
