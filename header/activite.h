#include "global.h"
#include <string.h>


void Gestion_activite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents,  char Tab_nom_activite[100][20],  int Tab_nb_activite_adherent[100]);


void Supprimer_activite();




int effectuer_activite(int num_adherant , int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents,  char Tab_nom_activite[100][20],  int Tab_nb_activite_adherent[100]);

int verif_adherent(int num_adherant, int Tab_Presence_adherent[], int nbAdherents, int Tab_numero_carte_adherent[],  int Tab_nb_activite_adherent[100], int Tab_Etat_carte[]);


int verif_activite(int Tab_numero_activite[],int  activite, int nbActivite);

void modif_crea_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite);

void affichage_activite( int Tab_numero_activite[], int Tab_tarif_activite[], char Tab_nom_activite[100][20], int nbActivite, int Tab_nbr_entree_activite[]);

void creer_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite);

void supprimer_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite);

void modifier_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite);
