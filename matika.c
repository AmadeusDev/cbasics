/*------------------------------------------------*/
/* matika.c                                       */
#include <stdio.h>
#include <math.h>

int main(void)
{
    int ia;
    float fa;
    double da;
    /* kresleni sinusove vlny */
    for (fa = 0.0; fa < 2.0 * M_PI; fa += M_PI / 13) {
	ia = 40 + 20.0 * sin(fa);
	printf("%*c\n", ia, '*');
    }

    printf("ceil(%f)=%f\tfloor(%f)=%f\n", 5.9, ceil(5.9), 5.9, floor(5.9));
    printf("ceil(%f)=%f\tfloor(%f)=%f\n", 5.1, ceil(5.1), 5.1, floor(5.1));

#define MODF 5.5
    fa = modf(MODF, &da);
    printf("fmod(%4.2f,%4.2f)=%4.2f\nmodf(%4.2f,&y)=%4.2f --> y=%4.2f\n",
	   100.0, 3.0, fmod(100.0, 3.0), MODF, fa, da);

    return 0;
}

/*------------------------------------------------*/
