/*------------------------------------------------*/
/* sigaction.c                                    */

#include <stdio.h>
#include <signal.h>

static int chyceni_signalu;

int a = 5, b = 0;

void zpracuj_signal(int cislo_signalu)
{
    chyceni_signalu++;
    struct sigaction sa = { zpracuj_signal, 0, SA_RESTART };
    switch (cislo_signalu) {
    case SIGFPE:
	printf("Delit nulou se nevyplaci! a= %i, b= %i, chyceni_signalu= %i\n",
		a, b, chyceni_signalu);
	break;
    default:
	printf("Neocekavany signal!\n");
	break;
    }
    if (chyceni_signalu >= 3) {
	printf("Uz toho mam dost!\n");
	sa.sa_handler =  SIG_DFL;
    }
    (void) sigaction(SIGFPE, &sa, NULL);
}

int main(void)
{

    void (*ukazatel_na_fci) (int);
    struct sigaction sb, sa = { zpracuj_signal, 0, SA_RESTART };

    (void) sigaction(SIGFPE, &sa, &sb);
    if(sb.sa_handler == SIG_DFL) {
    	printf("To je poprve, co nastavuji zpracovani signalu pro SIGFPE\n");
    }

    printf("Zaciname: \n");
    printf("Deleni: %i/%i=%i\n", a, b, a / b);
    printf("Tento text se jiz nevytiskne.");

    return 0;
}
/*------------------------------------------------*/
