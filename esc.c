/*------------------------------------------------*/
/* esc.c                                          */
#include <stdio.h>

int main(void)
{
    printf("%s %%\n", "%");
    printf("%s\r%s\n", "AAAAAAA", "BB");
    printf("\"\a\"\n");
    printf("\x6a\n");
    return 0;
}

/*------------------------------------------------*/
