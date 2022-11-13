#include "global.h"

void help(int page);

void SupprimerAdherent(int *nbAdherents, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[]);

void AfficheAdherents(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);
void ligne(void);

int AfficheInfosAdherent(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);

int TrouverAdherent(int tabNoCarte[], int nbAdherents, int noCarte, int *trouve);

void RechargeCarte(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);

void CreerAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique);

void Bonus(int indice, int tabPointCarte[]);

void etat_desac(int mode, int raison);

void Gestion_carte( int Tab_numero_carte_adherent[], int Tab_Etat_carte[], int cible, int nbAdherents);