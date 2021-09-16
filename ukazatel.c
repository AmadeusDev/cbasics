/*------------------------------------------------*/
/* ukazatel.c                                     */

#include <stdio.h>

int main(void)
{
    int i;	/* promenne int */
    float f, f2;
    int *ui;	/* ukazatel (na typ int) */
    float *uf;

    f = 5.5;
    uf = 50;	/* v ukazateli uf je hodnota 50. Co je v pameti na 50 bajtu
		   nikdo nemuze vedet, proto se takto do ukazatele adresa
		   nikdy (!) neprirazuje */
    uf = &f;	/* v ukazateli uf je hodnota adresy promenne f (tak je to
		   spravne :-)) */
    ui = &i;

    f2 = *uf;	/* do f2 se priradi hodnota z promenne f, tedy 5.5 */
    *ui = 10;	/* tam, kam ukazuje adresa v ui (tedy do i) se ulozi 10.
		   Hodnota promenne ui se nezmeni (je to stale adresa    
		   promenne i) */

    printf("f = %f\n", f); /* hodnota v f se od prirazeni 5.5 nezmenila */
    printf("f2 = %f\n", f2); /* do f2 se priradila hodnota z promenne f, na
			        kterou jsme se odkazovali pomoci ukazatele uf */
    printf("i = %i\n", i); /* do i jsme pres ukazatel ui priradili 10 */

    printf("uf = %u, *uf=%f\n", uf, *uf); /* vytiskneme si hodnotu uf a hodnotu
					     na teto adrese (tj. adresu f2 a
					     hodnotu f2) */
    return 0;
}
/*------------------------------------------------*/
