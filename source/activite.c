#include "../header/global.h"
#include "../header/activite.h"
#include "../header/adherent.h"
#include "../header/menus.h"

void Affichage_entree()
{
    printf("\n\n Affichage des entrees par activite dans la journee\n");
    printf(" --------------------------------------------------\n\n\n");


}

void Affichage_activite()
{
    printf("\n\n Affichage des activites\n");
    printf(" --------------------------------------------------\n\n\n");
}


void Supprimer_activite()
{
    printf("\n\n Supprimer une activite\n");
    printf(" --------------------------------------------------\n\n\n");
}

void Gestion_activite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents )
{
    char reponse ='g';


    int num_adherant = 0, activite = 0, verif = 0, i = 1;

    printf("================================================================\n");
    printf("                  Effectuer une Activite\n");
    printf("================================================================\n\n\n");

    printf("   L'Adherant possede t'il un compte ?\n");
    printf("   ----------------------------------\n\n");
    printf("   - ( O / N ) : ");

    scanf("%c%*c",&reponse);



    while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
    {
        printf("\n\n ---> Erreur de saisie !\n\n");
        printf("   Saisir a nouveau : \n");
        printf("   -----------------");
        printf("\n\n   - ( O / N ) : ");
        scanf("%c%*c", &reponse);
    }

        if (reponse == 'N' || reponse == 'n')
    {
       printf("\n\n   Souhaitez-vous creer une compte : \n");
           printf("   --------------------------------\n\n");
        printf("   - ( O / N ) : ");
       scanf("%c%*c", &reponse);

       if (reponse == 'N' || reponse == 'n')   return;
       else CreerAdherent(Tab_numero_carte_adherent, Tab_Etat_carte, Tab_credit_carte, &nbAdherents, 100); // creation adherent 
    }

    printf("\n\n   Quel est votre numero d'adherent ? : \n");
    printf(    "   -----------------------------------\n\n");
    printf("   - Votre reponse : ");
    scanf("%d", &num_adherant);

    verif = verif_adherent( num_adherant,  Tab_Presence_adherent,  nbAdherents,  Tab_numero_carte_adherent); // Verifie que la personne ne soit pas déjà venu

    if (verif == 1) 
    {
        printf("\n ---> Adherent deja venu au centre aujourd'hui ! \n");
        return;
    }

        if (verif == 2) 
    {
        printf("\n ---> Adherent non existant ! \n");
        return;
    }

    while (verif != 1 && i <= 3)
    {
        verif = effectuer_activite(Tab_credit_carte,Tab_tarif_activite,num_adherant, nbr_activite, Tab_numero_carte_adherent, nbAdherents, Tab_Etat_carte);
        i = i +1;
    }
    
    if (verif >3 ) printf("\n ---> vous avez déjà fait 3 activités dans la journée !\n      Revenez demain !\n\n");
}

int effectuer_activite( int Tab_credit_carte[], int Tab_tarif_activite[], int num_adherant, int nbr_activite, int Tab_numero_carte_adherent[], int nbAdherents, int Tab_Etat_carte[])
{
    int activite = 0, verif = 0, position = 0;
    char reponse;
    printf("\n\n - Quelle activite l'adherent souhaite t'il faire :  \n");
    printf(    "   -----------------------------------------------\n");
    Affichage_activite();

    printf("\n\n   Choississez le numero de l'activite souhaitee : \n");
    printf(    "   ----------------------------------------------\n");
    printf("   - Votre reponse : ");
    scanf("%d%*c", &activite);

    position = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);

    verif = Tab_credit_carte[position] - Tab_tarif_activite[activite];

    printf("\n test 23 : valezur de vrif : %d", verif);



    printf("\n valeur credit adhent : %d\n", Tab_credit_carte[position]);



    printf("\n valeur tarif : %d \n", Tab_tarif_activite[activite]);
   
   while (verif < 0)
   {
        printf("\n ---> Credits insufisant !\n");
        printf("\n Souhaitez-vous recharger votre carte ?\n ");
        printf(  " ------------------------------------\n");
        printf("   - ( O / N ) : ");
        scanf("%c%*c", &reponse);

            while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
             {
                printf("\n\n ---> Erreur de saisie !\n\n");
                 printf("   Saisir a nouveau : \n");
                printf("   -----------------");
                printf("\n\n   - ( O / N ) : ");
                scanf("%c%*c", &reponse);
            }

        if (reponse == 'O' || reponse == 'o') RechargeCarte(num_adherant,Tab_numero_carte_adherent, Tab_Etat_carte, Tab_credit_carte, nbAdherents);
        else return 1;



       verif = Tab_credit_carte[num_adherant] - Tab_tarif_activite[activite];  
   }

   Tab_credit_carte[num_adherant] = verif;

   printf("\n   Souhaitez-vous faire une activite a nouveau ? \n");
    printf( "   -------------------------------------------\n");
    printf("   - ( O / N ) : ");
   scanf("%c%*c", &reponse);

    while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
    {
        printf("\n\n ---> Erreur de saisie !\n\n");
        printf("   Saisir a nouveau : \n");
        printf("   -----------------");
        printf("\n\n   - ( O / N ) : ");
        scanf("%c%*c", &reponse);
    }

   if (reponse == 'O' || reponse =='o') return 0;
   else return 1;

}


int verif_adherent(int num_adherant, int Tab_Presence_adherent[], int nbAdherents, int Tab_numero_carte_adherent[])
{
    int i = 0, verif = 6 ;

    i = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);


    if (verif != 1) return 2;

    for (i = 0; i <100; i ++)
    {
        if (Tab_Presence_adherent[i] == num_adherant) return 1;
    }

    return 0;
}