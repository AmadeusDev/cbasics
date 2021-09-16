/*------------------------------------------------*/
/* define1.h                                      */

#define DELKACHUZE 40

typedef enum {
    dopredu, dozadu, stat
} smer;

typedef struct {
    int vpred, vzad, stop;
    int pozice;
} pohyb;
/*------------------------------------------------*/
