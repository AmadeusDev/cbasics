/*------------------------------------------------*/
/* print3.c                                       */

#include <stdio.h>

int main(void)
{
    long int x;
    long double y = 25.0L;
    x = -25l;			/* je mozno psat jen x = -25, protoze
				   prekladac vi, ze x je long a tak si
				   cislo -25 prevede na -25l;
				   takhle je to vsak "cistci" a citelnejsi */

    printf("%10s <%+5i> <% 5ld> <%x>\n", "Cisla:", 25, x, -25);
    printf("%-10s <%-+5i> <% 5Lf> <%#x>\n", "Cisla:", 25, y, -25);
    return 0;
}

/*------------------------------------------------*/
