#include "../header/menus.h"
#include "../header/adherent.h"


int AffichageGestionAdherent(void)
{
    int choix;
    
    clean
    printf("====================================================\n");
    printf("\t\tMENU GESTION ADHERENT\n");
    printf("====================================================\n");

    printf("\nChoix disponible :\n");
    printf("\t0. Retour au menu principal\n");
    printf("\t1. Afficher tout les adherents\n");
    printf("\t2. Creer un nouvel adherent\n");
    printf("\t3. Supprimer un adherent\n");

    printf("\nChoix : ");
    scanf("%d", &choix);
    return choix;
}

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