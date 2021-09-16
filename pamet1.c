/*------------------------------------------------*/
/* pamet1.c                                       */

#include <stdio.h>
#include <string.h>

void porovnej(const char *s1, const char *s2, const int n)
{
    int x;
    x = memcmp(s1, s2, n);
    printf("%2i: %s %s %s\n", n, s1, x < 0 ? "<" : x > 0 ? ">" : "=", s2);
}

typedef struct {
    short int x;
    char pole[10];
    float f;
} Trida;

void tiskni(const Trida * T)
{
    unsigned int i;
    printf("T = {%3i,{", T->x);
    for (i = 0; i < sizeof(T->pole) / sizeof(T->pole[0]); i++)
	printf("%i,", T->pole[i]);
    printf("\b},{%.40f}}\n", T->f);
}

int main(void)
{
    Trida T1, T2;
    char text1[] = "1234567890";
    char text2[] = "abcdefghij";

    porovnej("aaazzzzz", "aabaa", 4);
    porovnej("aaaaa", "aabaa", 2);

    tiskni((Trida *) memset(&T1, 0, sizeof(T1)));
    tiskni((Trida *) memset(&T2, 1, sizeof(T2)));

    /* Vzpomente si na aritmetiku ukazatelu. Vyraz &T1 + n neukazuje n
     * bajtu za adresu &T1, ale n*sizeof(T1) bajtu za adresu T1. Tedy o n
     * struktur dale. Proto pouzijeme k pretypovani ukazatele typ char,
     * ktery jiz ma velikost 1 bajtu
     * a tak muzeme pomoci sizeof posouvat ukazatele po bajtech */

    memcpy((char *) &T1 + sizeof(T1.x), (char *) &T2 + sizeof(T1.x),
	   sizeof(T1) - sizeof(T1.x));
    tiskni(&T1);

    printf("text1+3: %s\n", (char *) memcpy(text1 + 3, text2 + 6, 3));
    printf("text1  : %s\n", text1);

    /* chybne pouziti - pameti se prekryvaji */
    (void) memcpy(text2 + 1, text2, 6);
    printf("text2+1: %s (memcpy)\n", text2);

    /* spravne pouziti */
    memcpy(text2, "abcdefghij", 10);
    (void) memmove(text2 + 1, text2, 6);
    printf("text2+1: %s (memmove)\n", text2);

    return 0;
}

/*------------------------------------------------*/
