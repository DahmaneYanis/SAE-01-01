#include "../header/adherent.h"

int main(void){

    color

    int tabCarte[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tabEtat[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tabPoint[15] = {0};

    int taillePhysique = 15;
    int tailleLog = 15;

    int err = AfficheInfosAdherent(15, tabCarte, tabEtat, tabPoint, tailleLog);
    //SupprimerAdherent(&tailleLog, tabCarte, tabEtat, tabPoint);
    //AfficheAdherents(tabCarte, tabEtat, tabPoint, tailleLog);

}