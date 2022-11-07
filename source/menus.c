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
                printf("Appuyez sur entree pour continuer...");
                scanf("%c", &trash);
        }
    }
}

#include "../header/menus.h"
#include "../header/adherent.h"


/**
 * @brief Permet l'affichage de GestionCompteAdherent
 * 
 * @return int Choix de l'utilisateur
 */
int AffichageGestionCompteAdherent(void)
{
    int choix;
    
    clean
    printf("===============================================================\n");
    printf("\t\tMENU GESTION D'UN COMPTE ADHERENT\n");
    printf("===============================================================\n");

    printf("\nChoix disponible :\n");
    printf("\t0. Retour au menu principal\n");
    printf("\t1. Afficher les infos d'un adherent\n");
    printf("\t2. Recharger une carte\n");
    printf("\t3. Desactiver/activer une carte\n");

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
 * @param nbAdherents [POINTEUR - Taille Logique] Nombre d'adhérents 
 * @param taillePhysique [Taille Physique]
 */
void GestionCompteAdherent(int tabNoCarte[], int tabEtatCarte[], int tabPointCarte[], int *nbAdherents, int taillePhysique)
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
                printf("Appuyez sur entree pour continuer...");
                scanf("%c", &trash);
        }
    }
}