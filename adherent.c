#include "../adherent.h"

/**
 * @brief Supprime un adherent
 * 
 * @param nbAdherent [POINTEUR] Nombre d'adhérent total
 * @param tabNoCarte [TABLEAU] Liste des numéros de cartes des adhérents
 * @param tabEtatCarte [TABLEAU] Liste des états des cartes des adhérents
 * @param tabPointCarte [TABLEAU] Liste des points sur les cartes des adhérents
 * @return int Code erreur : 0 -> Tout s'est bien passé | 1 -> Adhérent pas trouvé
 */
int SupprimerAdherent(int *nbAdherent, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[])
{
    int cible;
    char rep = 'N';

    printf("\nBienvenue sur le menu de suppression d'adherents.\nEntrer le numero de la carte de l'adherent que vous souhaitez supprimer : ");
    scanf("%d", &cible);

    // Verification de l'existance de l'adherent

    int trouve = 0;

    for (int i = 0; i < *nbAdherent ; i++)
    {
        if (tabNoCarte[i] == cible)
        {
            trouve = 1;
            break;
        }
    }

    // Si la carte de l'adherent n'existe pas
    if (trouve == 0)
    {
        printf("\nNumero de carte %d inexistant. Souhaitez vous un affichage détaille des adherents (O/N) : ");
        scanf("%*c%c", &rep);

        // Verification de la validité de la réponse
        while (rep != 'N' && rep != 'O')
        {
            printf("Reponse incorrecte. Souhaitez vous un affichage détaille des adherents (O/N) : ");
            scanf("%*c%c", &rep);
        }
        
        if (rep == 'O')
        {
            // APPEL DE L'AFFICHAGE DES ADHERENTS
        }
    }

    if (rep == 'O')
        {
            printf("Souhaitez vous entrer un autre numéro d'adhérent");
        }

    return 0;
    
}