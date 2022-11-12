#include "global.h"

void GestionAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique);
int AffichageGestionAdherent(void);

int AffichageGestionCompteAdherent(int cible);
void GestionCompteAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents);
int CibleAdherent(int tabNoCarte[], int nbAdherents);
void AfficheBandeauGCA(void);

void MenuActivite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents, int Tab_nom_activite[100][20] );

void MenuGlobal(void);
void AfficheBandeauMP(void);
int AffichageMenuPrincipal(void);