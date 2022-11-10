#include "global.h"

void Affichage_entree();

void Affichage_activite();

void Gestion_activite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents );


void Supprimer_activite();




int effectuer_activite( int Tab_credit_carte[], int Tab_tarif_activite[], int num_adherant, int nbr_activite, int Tab_numero_carte_adherent[], int nbAdherents, int Tab_Etat_carte[]);

int verif_adherent(int num_adherant, int Tab_Presence_adherent[], int nbAdherents, int Tab_numero_carte_adherent[]);