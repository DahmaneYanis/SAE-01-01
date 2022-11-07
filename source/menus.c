#include "../header/menus.h"
#include "../header/adherent.h"


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