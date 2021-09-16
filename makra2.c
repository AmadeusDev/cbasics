/*------------------------------------------------*/
/* makra2.c                                       */

#include <stdio.h>
#define PT 6

int main(void)
{
#if PT > 5
    printf("Makro PT je vetsi jak 5\n");
#endif

#if defined unix && defined linux
    printf("Hura, ja bezim na unixovem stroji a snad pod linuxem!\n");
#elif defined unix
    printf("Hura, ja bezim pod unixem!\n");
#else
    printf("Hmm, kde jsem se to kruci ocitl??\n");
#endif

    return 0;
}

/*------------------------------------------------*/
