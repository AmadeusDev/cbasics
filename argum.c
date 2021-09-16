/*------------------------------------------------*/
/* argum.c                                        */

#include <stdio.h>

#define VELKE "velke"
#define MALE "male"

#define VAROVANI printf("Zadejte: %s %s | %s ARGUMENT\n",argv[0],VELKE,MALE);

int shodne(char *v1, char *v2)
{
    int i = 0;
    /* pomoci zarazek '\0' zjistujeme konec retezce */
    while ((v1[i] != '\0') && (v2[i] != '\0')) {
	if (v1[i] != v2[i])
	    return 0;		/* nejsou shodne; */
	i++;
    }
    if (v1[i] || v2[i]) {     /* jeden retezec jeste nezkoncil, nejsou stejne */
	return 0;
    }
    return 1;			/* vsechny znaky byly shodne */
}

void velke(char *);
void male(char *);

int main(int argc, char *argv[])
{
    if (argc != 3) {
	VAROVANI return 1;
    }

    if (shodne(VELKE, argv[1]))
	velke(argv[2]);
    else if (shodne(MALE, argv[1]))
	male(argv[2]);
    else {
	VAROVANI return 1;
    }

    printf("Druhy argument byl zmenen na: %s\n", argv[2]);
    return 0;
}

 /* ve funkcich velke a male vyuzijeme vlastnosti ASCII tabulky */

void velke(char *v)
{
    int i = 0;
    while (v[i]) {		/* '\0' odpovida hodnote FALSE */
	if (v[i] >= 'a' && v[i] <= 'z') {
	    v[i] += ('A' - 'a');	/* rozdil v ASCII tabulce mezi
					   velkymi a malymi pismeny */
	}
	i++;
    }				/* konec while */
}

void male(char *v)
{
    int i = 0;
    while (v[i]) {
	if (v[i] >= 'A' && v[i] <= 'Z') {
	    v[i] += ('a' - 'A');
	}
	i++;
    }
}

/*------------------------------------------------*/
