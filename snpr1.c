/*------------------------------------------------*/
/* snpr1.c                                        */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50];
    snprintf(str, 5, "%f", 3.8);
    printf("Retezec %s je dlouhy %i znaku.\n", str, strlen(str));
    return 0;
}

/*------------------------------------------------*/
