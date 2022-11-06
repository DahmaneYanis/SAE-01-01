#include "global.h"

void help(int page);

void SupprimerAdherent(int *nbAdherents, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[]);

void AfficheAdherents(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);
void ligne(void);

int AfficheInfosAdherent(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);

int TrouverAdherent(int tabNoCarte[], int nbAdherents, int noCarte, int *trouve);

void RechargeCarte(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);

void CreerAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique);