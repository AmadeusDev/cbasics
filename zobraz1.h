 /*------------------------------------------------*/
 /* zobraz1.h                                      */

#include <stdio.h>
#include <stdlib.h>

#define TISKNIOPILCER(ZNK) printf("\r%3i%% (%*s%*c %3i%% (%3i)",p->vzad,\
                  p->pozice, ZNK, DELKACHUZE - p->pozice,')',p->vpred,pocet);
#define TISKNIOPILCEN(ZNK) printf("\n%3i%% (%*s%*c %3i%% (%3i)",p->vzad,\
                  p->pozice, ZNK, DELKACHUZE - p->pozice,')',p->vpred,pocet);

void zobraz_opilce1(pohyb *, const smer, const int);
void zobraz_opilce2(pohyb *, const smer, const int);
void zobraz_opilce3(pohyb *, const smer, const int);
void zobraz_opilce4(pohyb *, const smer, const int);

void (*zobraz[]) (pohyb *, const smer, const int) = {
zobraz_opilce1,
	zobraz_opilce2, zobraz_opilce3, zobraz_opilce1, zobraz_opilce3};

void zobraz_opilce1(pohyb * p, const smer s, const int pocet)
{
    switch (s) {
    case dopredu:
	p->pozice++;
	TISKNIOPILCER("->")
	    break;
    case dozadu:
	p->pozice--;
	TISKNIOPILCER("<-")
	    break;
    case stat:
	TISKNIOPILCER("<>")
	    break;
    };
}

void zobraz_opilce2(pohyb * p, const smer s, const int pocet)
{
    switch (s) {
    case dopredu:
	p->pozice++;
	TISKNIOPILCEN("->")
	    break;
    case dozadu:
	p->pozice--;
	TISKNIOPILCEN("<-")
	    break;
    default:
	TISKNIOPILCEN("<>")
	    break;
    };
}

void zobraz_opilce3(pohyb * p, const smer s, const int pocet)
{
    switch (s) {
    case dopredu:
	p->pozice++;
	TISKNIOPILCER(">>")
	    break;
    case dozadu:
	p->pozice--;
	TISKNIOPILCER("<<")
	    break;
    default:
	TISKNIOPILCER("><")
	    break;
    };
}

void zobraz_opilce4(pohyb * p, const smer s, const int pocet)
{
    switch (s) {
    case dopredu:
	p->pozice++;
	printf("\rPOZICE: %2i%*c", p->pozice++, DELKACHUZE + 10, ' ');
	break;
    case dozadu:
	p->pozice--;
	printf("\rPOZICE: %2i%*c", p->pozice++, DELKACHUZE + 10, ' ');
	break;
    default:
	printf("\rPOZICE: %2i%*c", p->pozice++, DELKACHUZE + 10, ' ');
	break;
    };
}

 /*------------------------------------------------*/
