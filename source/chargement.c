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

void dechargement_adherent(int Tab_numero_carte_adherent[], int Tab_Etat_carte[], int Tab_credit_carte[])
{
    FILE * flot;

    flot = fopen("../donnees/adherent.don", "w");

    if (flot == NULL)
    {
        printf("\n Erreur enrgistrement dans fichier adherent.don\n");
        return;
    }

    for (int i = 0; i < 100; i ++)
    {
       if (Tab_numero_carte_adherent[i] != 0) fprintf(flot, "%d \t %d \t %d \n", Tab_numero_carte_adherent[i], Tab_Etat_carte[i], Tab_credit_carte[i]);
    }

    fclose (flot);

}


int chargement_tableaux_activite(int Tab_numero_activite[], int Tab_tarif_activite[], char Tab_nom_activite[100][20])
{
    FILE * flot;
    int i = 0;

    flot = fopen("../donnees/activite.don", "r");

    if ( flot == NULL)
    {
        printf("\n Erreur dans ouverture du fichier activite\n");
        return -1;
    }

    while (!feof(flot))
    {
        fscanf(flot,"%d", &Tab_numero_activite[i]);
        fscanf(flot, "%d", &Tab_tarif_activite[i]);
        fscanf(flot, "%s", &Tab_nom_activite[i]);
        i = i +1;
    }
    fclose(flot);
    return i;
}

void dechargement_activite( int Tab_numero_activite[], int Tab_tarif_activite[], char Tab_nom_activite[100][20])
{
        FILE * flot;
   

    flot = fopen("../donnees/activite.don", "w");

    if ( flot == NULL)
    {
        printf("\n Erreur dans ouverture du fichier activite\n");
        return ;
    }

    for (int i = 0; i < 100; i ++)
    {
        if ( Tab_numero_activite[i] != 0) fprintf( flot, "%d \t %d \t %s \n", Tab_numero_activite[i], Tab_tarif_activite[i], Tab_nom_activite[i] );
    }
    fclose (flot);
}


