/*------------------------------------------------*/
/* dynamic2.c                                     */

#include <stdio.h>
#include <stdlib.h>

#define X  100			/* pocet radku */
#define Xv1 10			/* vypis radek Xv1 az Xv2 */
#define Xv2 20

#define Y  200			/* sloupce */
#define Yv1 50			/* vypis sloupcu Yv1 az Yv2 */
#define Yv2 60

int main(void)
{
    int **ui;
    int a, b;

    ui = (int **) malloc(X * (sizeof(int *)));
    if (ui == NULL)
	return 1;

    for (a = 0; a < X; a++) {
	ui[a] = (int *) malloc(Y * (sizeof(int)));
	if (ui[a] == NULL)
	    return 1;
    }

    for (a = 0; a < X; a++)
	for (b = 0; b < Y; b++)
	    ui[a][b] = a * b;

    printf("     ");
    for (b = Yv1; b <= Yv2; b++)
	printf("%5i ", b);

    printf("\n");
    for (a = Xv1; a <= Xv2; a++) {
	printf("%3i: ", a);
	for (b = Yv1; b <= Yv2; b++)
	    printf("%5i ", ui[a][b]);
	printf("\n");
    }

    /* jak byla pamet alokovana, tak musi byt dealokovana.
     * Jednoduseji to opravdu nejde. */
    for (a = 0; a < X; a++)
	free(ui[a]);
    free(ui);

    return 0;
}

 /*------------------------------------------------*/
