#include "../header/chargement.h"

int chargement_tableaux_adherent(int Tab_numero_carte_adherent[], int Tab_Etat_carte[], int Tab_credit_carte[])
{
    FILE *flot;

    flot=fopen("../donnees/adherent.don", "r");

    if (flot == NULL)
    {
        printf("Erreur de chargement\n");
        return -1;
    }

    int i = 0;
    while (!feof(flot))
    {
        fscanf(flot,"%d", &Tab_numero_carte_adherent[i]);
        fscanf(flot,"%d", &Tab_Etat_carte[i]);
        fscanf(flot,"%d", &Tab_credit_carte[i]);

        i = i +1;
    }
    fclose(flot);
    return i-1;
}

int chargement_tableaux_activite(int Tab_numero_activite[], int Tab_tarif_activite[])
{
    FILE * flot;
    int i = 0;

    flot = fopen("../texte/activite.don", "r");

    if ( flot == NULL)
    {
        printf("\n Erreur dans ouverture du fichier activite\n");
        return -1;
    }

    while (!feof(flot))
    {
        fscanf(flot,"%d", &Tab_numero_activite[i]);
        fscanf(flot, "%d", &Tab_tarif_activite[i]);
        i = i +1;
    }
    fclose(flot);
    return i-1;
}

