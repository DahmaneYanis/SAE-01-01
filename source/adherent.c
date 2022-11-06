#include "../header/adherent.h"

/**
 * @brief Affiche le message d'aide demandé
 * 
 * @param page Numéro de message d'aide demandé
 */
void help(int page){
    
    if (page == 1)
    {
        printf("\nPour naviguer a travers la liste des adherents tapez :\n");
        printf("\t- \"0\" pour quitter.\n\t- Sur \"-\", puis le nombre de page que vous souhaitez passer en arriere\n\t  Exemple \"-1\" permet de revenir a la page precedente\n\t- Le nombre de page que vous souhaitez passer en avant\n\t  Exemple \"1\" permet d'aller a la page suivante\n\t- N'importe quoi d'autre afin d'afficher ce message d'aide\n");
    }
}

/**
 * @brief Supprime un adherent
 * 
 * @param nbAdherents [POINTEUR - Taille Logique] Nombre d'adhérents total 
 * @param tabNoCarte [TABLEAU] Liste des numéros de cartes des adhérents
 * @param tabEtatCarte [TABLEAU] Liste des états des cartes des adhérents
 * @param tabPointCarte [TABLEAU] Liste des points sur les cartes des adhérents
 */
void SupprimerAdherent(int *nbAdherents, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[])
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


        for (int i = 0; i < *nbAdherents ; i++)
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
            scanf(" %c", &rep);

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Souhaitez vous un affichage detaille des adherents (O/N) : ");
                scanf(" %c", &rep);
            }
            
            if (rep == 'O')
            {
                AfficheAdherents(tabNoCarte, tabEtatCarte, tabPointCarte, *nbAdherents);
            }
        }

        // Si la carte a été trouvée

        else
        {
            clean
            printf("Adherent trouve. Voici ses informations :\nNumero de carte : %d\nEtat de la carte : %d\nPoint(s) sur la carte : %d\nConfirmez vous la suppression de l'adherent (O/N) : ", tabNoCarte[indice], tabEtatCarte[indice], tabPointCarte[indice]);
            scanf(" %c", &rep);

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Confirmez vous la suppression de l'adherent %d (O/N) : ", tabNoCarte[indice]);
                scanf(" %c", &rep);
            }
            // Suppression de l'adherent
            if (rep == 'O')
            {
                for (int i = indice; i < *nbAdherents ; i++)
                {
                    tabNoCarte[i] = tabNoCarte[i+1];
                    tabEtatCarte[i] = tabEtatCarte[i+1];
                    tabPointCarte[i] = tabPointCarte[i+1];
                }
                
                clean
                printf("Adherent supprime.\n");

            *nbAdherents -= 1;
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
        scanf(" %c", &rep);
        clean

        while (rep != 'N' && rep != 'O')
        {
            clean
            printf("Reponse incorrecte. Souhaitez vous entrer un autre numero d'adherent (O/N) : ");
            scanf(" %c", &rep);
        }

        if(rep == 'N')
        {
            clean
            exit = 1;
            printf("Retour au menu principal.\n");
        }
    }   
}

/**
 * @brief Affiche tout les adhérents
 * 
 * @param tabNoCarte [TABLEAU] Liste des cartes des adhérents
 * @param tabEtatCarte [TABLEAU] Liste des états des cartes des adhérents
 * @param tabPointCarte [TABLEAU] Liste des points des adhérents
 * @param nbAdherents [TAILLE LOGIQUE] Nombre d'adhérents
 */
void AfficheAdherents(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents)
{
    int commande, actif = 1;
    int nbPages = nbAdherents/10 + 1, noPage = 1;
    char trash;

    //Détermine les adhérents à afficher au début
    int min = 0, max;

    if (nbAdherents>= 10)
        max = 9;
    else
        max = nbAdherents;

    // Boucle d'affichage
    while (actif)
    {
        clean
        printf("LISTE DES ADHERENTS\n");

        printf("\n\t| NUMERO ADHERENT | ETAT DE LA CARTE | CREDIT DE LA CARTE |\n");

        for (int i = min; i < max; i++)
        {
            ligne();    
            printf("\t| %15d | %16d | %18d |\n", tabNoCarte[i], tabEtatCarte[i], tabPointCarte[i]);

        }

        printf("\n\t\t\t     PAGE %d/%d", noPage, nbPages); // Affichage du numéro de page

        printf("\nCommande : ");
        scanf("%d", &commande);

        // Traitement de la commande
        if (commande == 0)
        {
            actif = 0;
        }
        else
        {
            if (noPage+commande > nbPages || noPage+commande < 1)
            {
                help(1);
                printf("\nAppuyer sur entree pour continuer...");
                scanf("%*c%c", &trash);
            }
            else
            {
                noPage+=commande;
            }
        }
        
        //Détermine la page (et son contenu) à  afficher
        min = (noPage-1)*10;
        if (noPage*10 > nbAdherents)
            max = nbAdherents;
        else
            max = noPage*10;
    }         
}

/**
 * @brief Fonction qui ne sert qu'à AfficheAdherents et qui permet d'éviter la répétition de ligne
 * 
 */
void ligne(void)
{
    printf("\t|");
    for (int i = 0; i < 57; i++)
    {

        if(i == 17 || i == 36)
            printf("|");
        else
            printf("-");    
    }
    printf("|\n");
}

/**
 * @brief Affiche les informations d'un adhérent
 * 
 * @param noCarte Numéro d'adhérent pour lequel on cherche des informations
 * @param tabNoCarte [TABLEAU] Liste des adherents
 * @param tabEtatCarte [TABLEAU] Liste des états des cartes des adherents
 * @param tabPointCarte [TABLEAU] Liste des crédits pour chaque adhérent
 * @param nbAdherents [Taille Logique] Nombre d'adherents total
 * @return int [CODE ERR] 0 -> Tout s'est bien passé | -1 -> Numéro de carte introuvable
 */
int AfficheInfosAdherent(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents)
{
    int trouve = 0, indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve); // Vérifier l'éxistance de l'adherent

    // Affichage
    clean

    // Traitement du résultat de la recherche
    if (!trouve && indice != -1)
    {
        printf("Adherent %d introuvable.\n", noCarte);

        return -1;
    }
    else
    {
        printf("Information de l'adherent %d : \n", noCarte);
        printf("\n\t| NUMERO ADHERENT | ETAT DE LA CARTE | CREDIT DE LA CARTE |\n");
        ligne();
        printf("\t| %15d | %16d | %18d |\n", tabNoCarte[indice], tabEtatCarte[indice], tabPointCarte[indice]);
        
        return 0;
    }
}

/**
 * @brief Permet de déterminer si un adhérent existe et si oui de récupérer son indice
 * 
 * @param tabNoCarte [TABLEAU] Liste des adhérents
 * @param nbAdherents [Taille Logique] Nombre d'adhérents
 * @param noCarte Numéro d'adhérent que l'on cherche
 * @param trouve [POINTEUR] Vaut par défaut 0. Prend la valeur 1 si l'adhérent est trouvé
 * @return int -1 -> Adhérent introuvable | Autre -> Indice de l'adherent
 */

int TrouverAdherent(int tabNoCarte[], int nbAdherents, int noCarte, int *trouve)
{
    // Vérifier l'existance du numéro de carte et si existe récupération de son indice
    for (int i = 0; i < nbAdherents; i++)
    {
        if (tabNoCarte[i] == noCarte)
        {   
            *trouve = 1;
            return i;

        }
    }

    return -1;
}

void RechargeCarte(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents)
{
    clean
    char rep;
    int trouve = 0, actif = 1;
    int indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);

    while (actif)
    {
        if (!trouve && indice == -1)
        {
            printf("Adherent %d introuvable. Souhaitez-vous rechercher un autre adherent (O/N) : ", noCarte);
            scanf(" %c", &rep); 

            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Souhaitez vous entrer un autre numero d'adherent (O/N) : ");
                printf("\nrep : %c\n", rep);
                scanf(" %c", &rep);
                printf("\nRep : %c\n", rep);
            }

            if(rep == 'N')
            {
                clean
                printf("\nRetour au menu principal.\n");
                actif = 0 ;
            }
            else
            {
                clean
                printf("Numero d'adherent a recharger : ");
                scanf(" %d", &noCarte);

                indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
            }
        }
        else
        {
            AfficheInfosAdherent(noCarte, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents);
            actif = 0;
        }
    }
}
