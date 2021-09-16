/*------------------------------------------------*/
/* typedef2.c                                     */
#include <stdio.h>

typedef struct pokus {
    int x;
    int y;
    char text[20];
} Pokus;

int main(void)
{
    struct pokus a = { 6, 6, "sest" };
    Pokus b = { 4, 5, "Ahoj" };

    a.x = 0;
    b.x = 6;
    return 0;
}

/*------------------------------------------------*/
