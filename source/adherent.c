#include "../header/adherent.h"

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
    int cible, boucle = 0;
    char rep;

    int trouve = 0;
    int indice = 0;
    
    int exit = 0;

    clean
    printf("\nBienvenue sur le menu de suppression d'adherents.\n");
    
    while (!exit)
    {
        trouve = 0;
        indice = 0;

        printf("Entrer le numero de la carte de l'adherent que vous souhaitez supprimer : ");
        scanf("%d", &cible);
        clean

        // Verification de l'existance de l'adherent


        for (int i = 0; i < *nbAdherent ; i++)
        {
            if (tabNoCarte[i] == cible)
            {
                trouve = 1;
                indice = i;
                break;
            }
        }

        // Si la carte de l'adherent n'existe pas
        if (trouve == 0)
        {
            printf("\nNumero de carte %d inexistant. Souhaitez vous un affichage detaille des adherents (O/N) : ", cible);
            scanf("%*c%c", &rep);

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Souhaitez vous un affichage detaille des adherents (O/N) : ");
                scanf("%*c%c", &rep);
            }
            
            if (rep == 'O')
            {
                // AfficheAdherents(); --> APPEL DE L'AFFICHAGE DES ADHERENTS
            }
        }

        // Si la carte a été trouvée

        else
        {
            clean
            printf("Adherent trouve. Voici ses informations :\nNumero de carte : %d\nEtat de la carte : %d\nPoint(s) sur la carte : %d\nConfirmez vous la suppression de l'adherent (O/N) : ", tabNoCarte[indice], tabEtatCarte[indice], tabPointCarte[indice]);
            scanf("%*c%c", &rep);

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Confirmez vous la suppression de l'adherent %d (O/N) : ", tabNoCarte[indice]);
                scanf("%*c%c", &rep);
            }
            // Suppression de l'adherent
            if (rep == 'O')
            {
                for (int i = indice; i < *nbAdherent ; i++)
                {
                    tabNoCarte[i] = tabNoCarte[i+1];
                    tabEtatCarte[i] = tabEtatCarte[i+1];
                    tabPointCarte[i] = tabPointCarte[i+1];
                }
                
                clean
                printf("Adherent supprime.\n");

            *nbAdherent -= 1;
            }

            // Suppression annulée
            else
            {
                clean
                printf("Suppression annulee.\n");
            }
        }

        // Test pour savoir si on supprime encore un adhérent ou si on retourne au menu principal
        printf("\nSouhaitez vous entrer un autre numero d'adherent (O/N) : ");
        scanf("%*c%c", &rep);
        clean

        while (rep != 'N' && rep != 'O')
        {
            clean
            printf("Reponse incorrecte. Confirmez vous la suppression de l'adherent %d (O/N) : ", tabNoCarte[indice]);
            scanf("%*c%c", &rep);
        }

        if(rep == 'N')
        {
            clean
            exit = 1;
            printf("Retour au menu principal.\n");
        }
    }   
}
