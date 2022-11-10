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


        printf("Entrer le numero de la carte de l'adherent que vous souhaitez supprimer : ");
        scanf("%d", &cible);
        clean

        // Verification de l'existance de l'adherent
        trouve = 0;
        indice = TrouverAdherent(tabNoCarte, *nbAdherents, cible, &trouve);

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
            _rep_

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Souhaitez vous un affichage detaille des adherents (O/N) : ");
                _rep_
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
            AfficheInfosAdherent(cible, tabNoCarte, tabEtatCarte, tabPointCarte, *nbAdherents);
            
            printf("\nConfirmez vous la suppression de l'adherent (O/N) : ");
            _rep_

            // Verification de la validité de la réponse
            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Confirmez vous la suppression de l'adherent %d (O/N) : ", tabNoCarte[indice]);
                _rep_
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
        _rep_
        clean

        while (rep != 'N' && rep != 'O')
        {
            clean
            printf("Reponse incorrecte. Souhaitez vous entrer un autre numero d'adherent (O/N) : ");
            _rep_
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
                wait
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

/**
 * @brief Recharge une carte d'adhérent
 * 
 * @param noCarte Carte à rechargée
 * @param tabNoCarte [TABLEAU] Liste des adhérents
 * @param tabEtatCarte [TABLEAU] Liste des états des cartes des adhérents
 * @param tabPointCarte [TABLEAU] Liste des crédits des cartes des adhérents
 * @param nbAdherents [Taille Logique] Nombre d'adhérents total
 */
void RechargeCarte(int noCarte, int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents)
{
    clean
    char rep;
    int trouve = 0, actif = 1;

    int indice;
    int trash, credit;

    while (actif)
    {
        indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve); // Récupération de l'indice de l'adhérent si il existe

        // Si l'adhérent cherché n'existe pas
        if (!trouve && indice == -1)
        {
            printf("Carte adherente introuvable. Souhaitez-vous rechercher un autre adherent (O/N) : ", noCarte);
            _rep_ 

            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Souhaitez vous entrer un autre numero d'adherent (O/N) : ");
                _rep_
            }

            // Abandon de la recharge
            if(rep == 'N')
            {
                clean
                printf("\nRetour au menu principal.\n");
                actif = 0 ;
            }

            // Relancement de la fonction pour une autre carte adhérent
            else
            {
                clean
                printf("Numero carte d'adherent a recharger : ");
                scanf(" %d", &noCarte);

                indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
            }
        }

        // Adhérent trouvé
        else
        {
            AfficheInfosAdherent(noCarte, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents);
            
            printf("\nVoulez-vous toujours recharger la carte numero %d (O/N) : ", noCarte);
            _rep_

            while (rep != 'N' && rep != 'O')
            {
                clean
                printf("Reponse incorrecte. Voulez-vous toujours recharger la carte numero %d (O/N) : ", noCarte);
                _rep_
            }

            // Annulation de la recharge
            if (rep == 'N')
            {
                clean
                printf("Transaction annulee.\nSouhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                _rep_

                while (rep != 'N' && rep != 'O')
                {
                    clean
                    printf("Reponse incorrecte. Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                    _rep_
                }

                // Fin de programme
                if (rep == 'N')
                    actif = 0;

                // Relancment du programme avec une nouvelle carte adhérente
                else
                {
                    clean
                    printf("Numero carte d'adherent a recharger : ");
                    scanf(" %d", &noCarte);

                    indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
                }
            }
            
            // Validation de la volonté de recharger
            else
            {
                // Récupération du nombre de crédit à ajouter
                clean
                printf("Combien souhaitez-vous ajouter de credit : ");
                scanf(" %d", &credit);

                // Vérification de l'état de la carte

                // Si la carte est activée
                if (tabEtatCarte[indice] == 1)
                {
                    tabPointCarte[indice] += credit;
                    AfficheInfosAdherent(noCarte, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents);
                
                    printf("\nTransaction de %d credits faite.\n", credit);
                    printf("Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                    _rep_

                    while (rep != 'N' && rep != 'O')
                    {
                        clean
                        printf("Reponse incorrecte. Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                        _rep_
                    }

                    // Nouveau rechargement de carte
                    if (rep == 'O')
                    {
                        clean
                        printf("Numero carte d'adherent a recharger : ");
                        scanf(" %d", &noCarte);

                        indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
                    }

                    // Fin de programme
                    else
                        actif = 0;
                }

                // Si la carte est désactivée
                else
                {
                    clean
                    printf("Etat de la carte actuel : %d", tabEtatCarte[indice]);
                    printf("\nVoulez-vous la reactiver (O/N) : ");
                    _rep_

                    while (rep != 'N' && rep != 'O')
                    {
                        clean
                        printf("Reponse incorrecte.\nEtat de la carte actuel : %d. Voulez-vous reactiver la carte numero %d (O/N) : ", tabEtatCarte[indice], noCarte);
                        _rep_
                    }

                    // Réactivation de la carte et ajout des crédits
                    if (rep == 'O')
                    {
                        tabEtatCarte[indice] = 1;
                        tabPointCarte[indice] += credit;
                        clean
                        AfficheInfosAdherent(noCarte, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents);
                    
                        printf("\nTransaction de %d credits faite.\n", credit);
                        printf("Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                        _rep_

                        while (rep != 'N' && rep != 'O')
                        {
                            clean
                            printf("Reponse incorrecte. Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                            _rep_
                        }

                        // Nouveau rechargement de carte
                        if (rep == 'O')
                        {
                            clean
                            printf("Numero carte d'adherent a recharger : ");
                            scanf(" %d", &noCarte);

                            indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
                        }

                        // Fin de programme
                        else
                            actif = 0;
                    }

                    // Etat de la carte non modifié
                    else
                    {
                        clean
                        printf("Souhaitez-vous effectuer quand meme la transaction de %d credit (O/N) : ", credit);
                        _rep_
                    
                        while (rep != 'N' && rep != 'O')
                        {
                            clean
                            printf("Reponse incorrecte. Souhaitez-vous effectuer quand meme la transaction de %d credit (O/N) : ", credit);
                            _rep_
                        }
                        
                        // Mettre des crédits sans réactiver la carte
                        if (rep == 'O')
                        {
                            tabPointCarte[indice] += credit;
                            AfficheInfosAdherent(noCarte, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents);

                            printf("\nTransaction de %d credits faite.\n", credit);
                            printf("Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                            _rep_

                            while (rep != 'N' && rep != 'O')
                            {
                                clean
                                printf("Reponse incorrecte. Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                                _rep_
                            }

                            // Nouveau rechargement de carte
                            if (rep == 'O')
                            {
                                clean
                                printf("Numero carte d'adherent a recharger : ");
                                scanf(" %d", &noCarte);

                                indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
                            }

                            // Fin de programme
                            else
                                actif = 0;
                        }

                        // Annulation de la transaction car carte annulée
                        else
                        {
                            clean
                            printf("Transaction annulee.\nSouhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                            _rep_

                            while (rep != 'N' && rep != 'O')
                            {
                                clean
                                printf("Reponse incorrecte. Souhaitez-vous faire une nouvelle transaction de credit (O/N) : ");
                                _rep_
                            }

                            // Fin de programme
                            if (rep == 'N')
                                actif = 0;

                            // Relancment du programme avec une nouvelle carte adhérente
                            else
                            {
                                clean
                                printf("Numero carte d'adherent a recharger : ");
                                scanf(" %d", &noCarte);

                                indice = TrouverAdherent(tabNoCarte, nbAdherents, noCarte, &trouve);
                            }
                        }   
                    }
                }
            }
        }
    }
}

/**
 * @brief Creer un nouvel adherent à la fin du tableau si la taille physique le permet
 * 
 * @param tabNoCarte [TABLEAU] Liste des adherents
 * @param tabEtatCarte [TABLEAU] Etats des adherents
 * @param tabPointCarte [TABLEAU] Credit des adherents
 * @param nbAdherents  [POINTEUR - Taille Logique] Nombre d'adhérents total
 * @param taillePhysique [Taille Physique]
 */
void CreerAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique)
{
    int dispo = 0, indice = 0, actif = 1;
    int i;

    int credit;
    char rep;
    
    while(actif)
    {
        // Verification de la posibilité de créer un nouvel adhérent (taille physique du tableau)
        if (taillePhysique <=  *nbAdherents)
        {
            printf("Taille physique du tableau pas assez elevee.\n");
            return;
        }

        i = 1;

        // Recherche d'un numéro disponible 
        while(!dispo)
        {
            dispo = 1;
            for (int j = 0 ; j < *nbAdherents ; j++)
            {
                if (tabNoCarte[j] == i)
                    dispo = 0;
            }

            if(dispo)
                indice = i;
    
            i++;
        }

        // Ajout de l'adhérent à la fin du tableau (tableau trié plus tard)
        *nbAdherents+=1; // ++ ne marche pas

        clean
        printf("Credit de l'adherent : ");
        scanf("%d", &credit);

        tabNoCarte[*nbAdherents-1] = indice;
        tabEtatCarte[*nbAdherents-1] = 1;
        tabPointCarte[*nbAdherents-1] = credit;

        clean
        printf("Adherent cree.\n");
        AfficheInfosAdherent(indice, tabNoCarte, tabEtatCarte, tabPointCarte, *nbAdherents);
        printf("\nSouhaitez vous un affichage detaille des adherents (O/N) : ");
        _rep_

        // Verification de la validité de la réponse
        while (rep != 'N' && rep != 'O')
        {
            clean
            printf("Reponse incorrecte. Souhaitez vous un affichage detaille des adherents (O/N) : ");
            _rep_
        }

        if (rep == 'O')
        {
            AfficheAdherents(tabNoCarte, tabEtatCarte, tabPointCarte, *nbAdherents);
        }

        clean
        printf("Souhaitez vous creer un autre adherent (O/N) : ");
        _rep_

        // Verification de la validité de la réponse
        while (rep != 'N' && rep != 'O')
        {
            clean
            printf("Reponse incorrecte. Souhaitez vous creer un autre adherent (O/N) : ");
            _rep_
        }

        if (rep == 'N')
        {
            actif = 0;
        }
        else 
            dispo = 0;
    }
}