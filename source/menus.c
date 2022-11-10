#include "../header/chargement.h"
#include "../header/activite.h"
#include "../header/adherent.h"
#include "../header/menus.h"

/**
 * @brief Permet l'affichage de GestionAdherent
 * 
 * @return int Choix de l'utilisateur
 */
int AffichageGestionAdherent(void)
{
    int choix;
    
    clean
    printf("=========================================================\n");
    printf("\t\tMENU GESTION DES ADHERENTS\n");
    printf("=========================================================\n");

    printf("\nChoix disponible :\n");
    printf("\t0. Retour au menu principal\n");
    printf("\t1. Afficher tout les adherents\n");
    printf("\t2. Creer un nouvel adherent\n");
    printf("\t3. Supprimer un adherent\n");

    printf("\nChoix : ");
    scanf("%d", &choix);
    return choix;
}

/**
 * @brief Menu des gestions des adhérents
 * 
 * @param tabNoCarte [TABLEAU] Liste des adherents
 * @param tabEtatCarte [TABLEAU] Etats des cartes
 * @param tabPointCarte [TABLEAU] Crédit des cartes
 * @param nbAdherents [POINTEUR - Taille Logique] Nombre d'adhérents 
 * @param taillePhysique [Taille Physique]
 */
void GestionAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique)
{
    int actif = 1;
    int choix;
    char trash;

    while(actif)
    {
        choix = AffichageGestionAdherent();
        switch(choix)
        {
            case 0 : actif = 0; break;
            case 1 : AfficheAdherents(tabNoCarte, tabEtatCarte, tabPointCarte, *nbAdherents);break;
            case 2 : CreerAdherent(tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents, taillePhysique);break;
            case 3 : SupprimerAdherent(nbAdherents, tabNoCarte, tabEtatCarte, tabPointCarte);break;
            default : 
                clean 
                printf("\nChoix invalide.\n");
                wait
        }
    }
}

/**
 * @brief Permet l'affichage de GestionCompteAdherent
 * 
 * @return int Choix de l'utilisateur
 */
int AffichageGestionCompteAdherent(int cible)
{
    int choix;
    
    AfficheBandeauGCA();
    printf("[ADHERENT %d]\n", cible);

    printf("\nChoix disponible :\n");
    printf("\t0. Retour au menu principal\n");
    printf("\t1. Afficher les infos d'un adherent\n");
    printf("\t2. Recharger une carte\n");
    printf("\t3. Desactiver/activer une carte\n");
    printf("\t4. Changer d'adherent\n");

    printf("\nChoix : ");
    scanf("%d", &choix);
    return choix;
}

/**
 * @brief Menu gestion d'un compte adhérent
 * 
 * @param tabNoCarte [TABLEAU] Liste des adherents
 * @param tabEtatCarte [TABLEAU] Etats des cartes
 * @param tabPointCarte [TABLEAU] Crédit des cartes
 * @param nbAdherents [Taille Logique] Nombre d'adhérents 
 */
void GestionCompteAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int nbAdherents)
{
    int actif = 1;
    int choix, cible;
    char trash;

    cible = CibleAdherent(tabNoCarte, nbAdherents); // Numéro de la carte de l'adhérent que l'on va traiter

    while(actif)
    {
        choix = AffichageGestionCompteAdherent(cible);
        switch(choix)
        {
            case 0 : actif = 0; break;
            case 1 : AfficheInfosAdherent(cible, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents); wait break;
            case 2 : RechargeCarte(cible, tabNoCarte, tabEtatCarte, tabPointCarte, nbAdherents); break;
            case 3 : actif = 0/*code temporaire à remplacer par Appel de la fontion Activation/Desactivation de la carte*/; break;
            case 4 : cible = CibleAdherent(tabNoCarte, nbAdherents); break;
            default : 
                clean 
                AfficheBandeauGCA();
                printf("\nChoix invalide.\n");
                wait
        }
    }
}

/**
 * @brief Récupère le numéro de carte de l'adhérent à traiter
 * 
 * @return int Numéro de carte de l'adhérent cible
 */
int CibleAdherent(int tabNoCarte[], int nbAdherents)
{
    int cible;
    
    int trouve = 0;
    int indice = 0;

    clean
    while(!trouve)
    {
        AfficheBandeauGCA();
        if(indice == -1)
        {
            printf("\nNumero de l'adherent inexistant.");
        }
        printf("\nNumero de carte de l'adherent a traiter : ");
        scanf("%d", &cible);
        indice = TrouverAdherent(tabNoCarte, nbAdherents, cible, &trouve);

        clean
        
    }
    
    return cible;
}

/**
 * @brief Affichage du bandeau du menu GestionCompteAdherent
 * 
 */
void AfficheBandeauGCA(void)
{
    clean
    printf("===============================================================\n");
    printf("\t\tMENU GESTION D'UN COMPTE ADHERENT\n");
    printf("===============================================================\n");
}


/*======================================================================================================*/

void MenuActivite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents ) // Menu des activités
{
    int choix = 0; //Variable qui récupère la volonté de l'utilisateur
    system("cls");

    printf("\n Menu des Activites\n");                                          //On affiche pour la première fois le menu
    printf(" ------------------\n\n");     
    printf("\n- 1.) Afficher le nombre d'entree par activite dans la journee\n");
    printf("- 2.) Afficher toutes les activites\n");
    printf("- 3.) Creer / modifier une activite\n");
    printf("- 4.) Supprimer une activite\n\n\n");
    scanf("%d%*c",&choix);  //On récupère le choix de l'utilisateur

    while(choix < 1 || choix > 5 ) // Tant que le choix est inférieur à 1 ou supérieur à 4, on renvoie le menu
    {
    system("cls");

    printf("\n\nERREUR DANS LA SAISIE DU CHOIX ! \n\n - Veuillez choisir a nouveau\n----------------------------------------\n\n ");

    printf("\n Menu des Activites\n");
    printf(" ------------------\n\n"); //On affiche le menu
    printf("\n- 1.) Afficher le nombre d'entree par activite dans la journee\n");
    printf("- 2.) Afficher toutes les activites\n");
    printf("- 3.) Creer / modifier une activite\n");
    printf("- 4.) Supprimer une activite\n\n\n");

    scanf("%d%*c",&choix);  //On récupère le choix de l'utilisateur à nouveau
    clean; // Commande pour vider le terminal sous windows 
    }

    switch (choix)
    {
    case 1 : Affichage_entree(); // Affiche le nombre d'entrées par activités dans la journée 
    break;

    case 2 : Affichage_activite(); // Affiche toutes les activités
    break;

    case 3 : ; // Pour créer ou modifier une activité 
    break;

    case 4 : Supprimer_activite(); // Pour supprimer une activité 
    break;

    case 5 : Gestion_activite( Tab_numero_activite, Tab_tarif_activite, Tab_nbr_entree_activite, Tab_numero_carte_adherent, Tab_Etat_carte, Tab_credit_carte, Tab_Presence_adherent, nbr_activite, nbAdherents );
    }
}

/**
 * @brief [FONCTION GLOBALE] Menu principal 
 * 
 */
void MenuGlobal(void)
{
    int actif = 1, choix;
    int trash;
    int tabNoCarte[100], tabEtatCarte[100], tabPoint[100];
    int nbAdherents = chargement_tableaux_adherent(tabNoCarte, tabEtatCarte, tabPoint); // Chargement des adhérents

    int tabNoAct[100], tabPrixAct[100];
    int nbActivite = chargement_tableaux_activite(tabNoAct, tabPrixAct); // Chargement des activités
    int tabEntree[100] = {0}, tabPresence[100] = {0};


    int taillePhysique = 100;
    
    // Gestion de problème de fichier
    if (nbAdherents == -1 || nbActivite == -1)
    {
        clean
        AfficheBandeauMP();
        printf("\nUne erreur est survenue : fichier introuvable.\nMerci de verifier la validite de votre fichier adherent.don et votre fichier activite.don dans le dossier donnees\n");
    }

    else
    {
        while(actif)
        {
            clean
            choix = AffichageMenuPrincipal();

            switch(choix)
            {
                case 0:
                    //enregistrement_tableaux_activite(tabNoAct, tabPrixAct);
                    //enregistrement_tableaux_adherent(tabNoAct, tabEtatCarte, tabPrixAct);
                    printf("Enregistrement fait.\n");
                    actif = 0;
                    break;
                case 1 : GestionAdherent(tabNoCarte, tabEtatCarte, tabPoint, &nbAdherents, taillePhysique); break;
                case 2 : GestionCompteAdherent(tabNoCarte, tabEtatCarte, tabPoint, nbAdherents); break;
                case 3 : MenuActivite(tabNoAct, tabPrixAct, tabEntree, tabNoCarte, tabEtatCarte, tabPoint, tabPresence, nbActivite, nbAdherents); break;
                case 4 : Gestion_activite(tabNoAct, tabPrixAct, tabEntree, tabNoCarte, tabEtatCarte, tabPoint, tabPresence, nbActivite, nbAdherents); break;
            }
        }
    }
}

/**
 * @brief Affichage du bandeau du Menu Principal
 * 
 */
void AfficheBandeauMP(void)
{
    clean
    printf("============================================\n");
    printf("\t\tMENU PRINCIPAL\n");
    printf("============================================\n");
}

/**
 * @brief Permet l'affichage du menu principal
 * 
 * @return int Choix de l'utilisateur
 */
int AffichageMenuPrincipal(void)
{
    int choix;
    
    AfficheBandeauMP();

    printf("\nChoix disponible :\n");
    printf("\t0. Quitter le programme\n");
    printf("\t1. Menu Gestion des adherents\n");
    printf("\t2. Menu Gestion d'un adherent\n");
    printf("\t3. Menu Activites\n");
    printf("\t4. Effectuer une activite\n");

    printf("\nChoix : ");
    scanf("%d", &choix);
    return choix;
}
