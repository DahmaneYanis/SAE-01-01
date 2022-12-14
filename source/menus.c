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
    scanf("%d%*c", &choix);
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
            case 3 : Gestion_carte( tabNoCarte,  tabEtatCarte, cible, nbAdherents); break;
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


/**
 * @brief [FONCTION GLOBALE] Menu principal 
 * 
 */
void MenuGlobal(void)
{  
    int actif = 1, choix;
    int trash;

    int tabNoCarte[100] = {0}, tabEtatCarte[100] = {0}, tabPoint[100] = {0};

    int Tab_nb_activite_adherent[100] = {0};
    int nbAdherents = chargement_tableaux_adherent(tabNoCarte, tabEtatCarte, tabPoint); // Chargement des adhérents


    int Tab_nbr_entree_activite[100] ={0};
    char Tab_nom_activite[100][20];
    int tabNoAct[100] ={0}, tabPrixAct[100] ={0};
    int nbActivite = chargement_tableaux_activite(tabNoAct, tabPrixAct, Tab_nom_activite); // Chargement des activités
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
                case 3 :modif_crea_activite(tabNoAct, Tab_nom_activite, tabPrixAct, tabEntree, nbActivite); break;
               
                case 4 : Gestion_activite(tabNoAct, tabPrixAct, tabEntree, tabNoCarte, tabEtatCarte, tabPoint, tabPresence, nbActivite, nbAdherents, Tab_nom_activite, Tab_nb_activite_adherent); break;
            }
        }
   }


   dechargement_adherent( tabNoCarte, tabEtatCarte, tabPoint);
   dechargement_activite( tabNoAct, tabPrixAct, Tab_nom_activite);
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
    scanf("%d%*c", &choix);
    return choix;
}
