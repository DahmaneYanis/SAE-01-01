#include "adherent.h"

int main(void){
    int tabCarte[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tabEtat[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tabPoint[10] = {0};

    int taillePhysique = 10;
    int tailleLog = 9;

    int err = SupprimerAdherent(&tailleLog, tabCarte, tabEtat, tabPoint);

    printf("\nCode erreur : %d\n", err);
}