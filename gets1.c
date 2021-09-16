/*------------------------------------------------*/
/* gets1.c                                        */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[80];
    printf("Zadejte libovolny text: ");	/* puts() by nam na konec vytisklo
					   znak noveho radku, a to nechci */
    (void) gets(text);
    puts(text);
    printf("Zadejte libovolny text: ");
    scanf("%s", text);
    puts(text);

    return 0;
}

/*------------------------------------------------*/
