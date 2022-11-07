#include "../header/adherent.h"
#include "../header/menus.h"

int main(void){

    #ifdef _WIN32
    color
    #endif

    int tabCarte[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tabEtat[17] = {1, 1, 1, 1, 1, 1, -2, 1, 1, 1, 1, 1, 1, 1, 1};
    int tabPoint[17] = {0};

    int taillePhysique = 17;
    int tailleLog = 15;
    int trouve = 0;

    //int err = AfficheInfosAdherent(15, tabCarte, tabEtat, tabPoint, tailleLog);
    //SupprimerAdherent(&tailleLog, tabCarte, tabEtat, tabPoint);
    //AfficheAdherents(tabCarte, tabEtat, tabPoint, tailleLog);
    //RechargeCarte(30, tabCarte, tabEtat, tabPoint, tailleLog);
    //int indice = TrouverAdherent(tabCarte, tailleLog, 5, &trouve);
    //printf("Indice: %d\nTrouve = %d", indice, trouve);
    //CreerAdherent(tabCarte, tabEtat, tabPoint, &tailleLog, taillePhysique);
    //GestionAdherent(tabCarte, tabEtat, tabPoint, &tailleLog, taillePhysique);
    GestionCompteAdherent(tabCarte, tabEtat, tabPoint, tailleLog);

}