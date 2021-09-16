/*------------------------------------------------*/
/* null1.c                                        */

#include <stdio.h>

int main(void)
{
    float *uk = NULL;
    float p[] = { 10.2, 5.1, 0.6 };

    printf("%s\n", uk == NULL ? "Ukazatel neni inicializovan" :
	   "Ukazatel lze pouzit");
    printf("%f\n", uk == NULL ? 0.0 : uk[0]);

    uk = p;

    printf("%s\n", uk == NULL ? "Ukazatel neni inicializovan" :
	   "Ukazatel lze pouzit");
    printf("%f\n", uk == NULL ? 0.0 : uk[0]);
    return 0;
}

/*------------------------------------------------*/
