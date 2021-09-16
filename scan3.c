/*------------------------------------------------*/
/* scan3.c                                        */

#include <stdio.h>

int main(void)
{
    int zamek = 5;
    int navrat;

    printf("Hodnota zamku je nyni %+5i\n", zamek);
    printf("Pokud chcete hodnotu zmenit, zadejte heslo a novou hodnotu\n"
	   "a stisknete ENTER. Napriklad: heslo 25\n>> ");

    /* heslo je 1234567890 */
    navrat = scanf("1234567890 %i", &zamek);

    printf("Bylo nacteno %i spravnych polozek\n", navrat);
    printf("Hodnota zamku je nyni %+5i\n", zamek);
    return 0;
}

/*------------------------------------------------*/
