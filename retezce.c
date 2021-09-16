 /*------------------------------------------------*/
 /* retezce.c                                      */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char c, *ch, pole1[81], pole2[81];
    int x;

    printf("Zadejte jeden znak a stisknete ENTER: ");
    scanf("%c", &c);
    printf("Zadejte prvni retezec: ");
    scanf("%80s", pole1);
    printf("Zadejte druhy retezec: ");
    scanf("%80s", pole2);

    x = strcmp(pole1, pole2);
    if (x < 0)
	printf("pole1 < pole2\n");
    else if (x == 0)
	printf("pole1 = pole2\n");
    else
	printf("pole1 > pole2\n");

    printf("Prvnich %i znaku se %s\n", 5,
	   !strncmp(pole1, pole2, 5) ? "schoduje" : "neschoduje");
    printf("Schoduje se presne %i znaku\n", strspn(pole1, pole2));

    ch = strchr(pole1, c);
    if (ch == NULL)
	printf("Znak %c se v retezci \"%s\" nenachazi\n", c, pole1);
    else
	printf("pole1 od znaku %c: %s\n", c, ch);

    x = strlen(pole1);
    printf("Delka prvniho retezce: %u\n", x);
    strncat(pole1, pole2, sizeof(pole1) - x - 1);
    printf("Spojeni: %s\n", pole1);

    return 0;
}

 /*------------------------------------------------*/
