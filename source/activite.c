#include "../header/global.h"
#include "../header/activite.h"
#include "../header/adherent.h"
#include "../header/menus.h"

void modif_crea_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{
    clean;
    int choix = 0;

    printf("=================================================================================\n");
    printf("                       Gestion des activites\n");
    printf("=================================================================================\n");

    //affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

    printf("   Souhaitez vous : \n");
    printf("   ---------------\n\n");
    printf(" - 1.) Creer une activite.\n - 2.) Modifier une activite. \n - 3.) Supprimer une activite.\n - 4.) Afficher les Activites\n - 5) retour menu principal.\n\n");
    printf(" - Votre reponse : ");
    scanf("%d%*c", &choix);

    switch (choix)
    {
        case 1 :clean;
            creer_activite(Tab_numero_activite,  Tab_nom_activite, Tab_tarif_activite, Tab_nbr_entree_activite, nbActivite);
         break;

        case 3 :         
        supprimer_activite(Tab_numero_activite,  Tab_nom_activite, Tab_tarif_activite, Tab_nbr_entree_activite, nbActivite);
         break;

         case 2 : 
         clean;
         modifier_activite(Tab_numero_activite,  Tab_nom_activite, Tab_tarif_activite, Tab_nbr_entree_activite, nbActivite);
         break;

         case 4 : 
         clean;    
             printf("=================================================================================\n");
            printf("                       Affichage des activites\n");
            printf("=================================================================================\n\n\n");
            affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);
            char trash;
            wait;
            break;

        case 5 : return;

        
    }

}

void creer_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{

    printf("=================================================================================\n");
    printf("                            Creer une activite\n");
    printf("=================================================================================\n"); 
    
    int i = 0, position = 0, valeur_temp =0;
    char reponse;

    for (i = 0; i < 100; i ++)
    {
        if ( Tab_numero_activite[i] == 0)
         {
            position = i;
             i = 190;
         }

        else  position = 123;
    }

            if (position == 123)
            {
                printf("\n ---> L'espace de stockage est trop faible, veuillez supprimer des activites.\n\n");
                printf(" - Souhaitez vous supprimer une activites ? \n\n - ( O / N ) : ");
                scanf("%c%*c", &reponse);

                while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
                {
                    printf("\n\n ---> Erreur de saisie !\n\n");
                    printf("   Saisir a nouveau : \n");
                    printf("   -----------------");
                    printf("\n\n   - ( O / N ) : ");
                    scanf("%c%*c", &reponse);
                }

                if (reponse == 'O' || reponse == 'o')
                supprimer_activite(Tab_numero_activite,  Tab_nom_activite, Tab_tarif_activite, Tab_nbr_entree_activite, nbActivite);
                else return;
            }

            printf("\n\n Quel est le nom de l'activite ? : \n");
            printf(    " -------------------------------\n\n - Votre reponse : ");
            scanf("%s", Tab_nom_activite[position]);

            nbActivite = nbActivite +1;

            printf("\n\n - Quel est son numero  : ");

            scanf("%d", &valeur_temp);
            Tab_numero_activite[position] = valeur_temp;

           for (i = 0; i < 100; i ++)
            {

                if (i == position) i = i +1;

                while ( Tab_numero_activite[i] == Tab_numero_activite[position])
                {   
                    printf("\n\n ---> Numero deja pris, reessayer : ");

                 scanf("%d", &valeur_temp);
                 Tab_numero_activite[position] = valeur_temp;

                 i = 0 ;

                }
            }      


            printf("\n\n - Quel est son Tarif : ");
    
            scanf("%d", &valeur_temp);

            Tab_tarif_activite[position] = valeur_temp;

            printf(" \n\nL'activite %s a bien ete creee ! \n \n Son numero est le %d\n Son tarif est de %d\n\n",
                     Tab_nom_activite[position], Tab_numero_activite[position], Tab_tarif_activite[position]);

        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

        char trash;
        wait;


}

void modifier_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{

    printf("=================================================================================\n");
    printf("                            Modifier une activite\n");
    printf("=================================================================================\n"); 
    
    int i = 0, position = 0, valeur_temp =0, num = 0;
    char reponse;

    affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

    printf("\n\n Quel est le numero de l'activite a modifier : ");
    scanf("%d%*c", &num);

        for ( int i = 0; i < 100; i ++)
        {
            if ( Tab_numero_activite[i] == num)
            {
                position = i;
                i = 190;
            }
            else position = 200;
        }

        while (position == 200)
            {
                printf("\n ---> Activite inexistante  ! \n\n");
                printf(" - Souhaitez vous recommencer ? \n\n - ( O / N ) : ");
                scanf("%c%*c", &reponse);

                while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
                {
                    printf("\n\n ---> Erreur de saisie !\n\n");
                    printf("   Saisir a nouveau : \n");
                    printf("   -----------------");
                    printf("\n\n   - ( O / N ) : ");
                    scanf("%c%*c", &reponse);
                }

                if (reponse == 'O' || reponse == 'o') 
                {
                     printf(" \n\nQuelle activite souhaitez vous modifier  : ");
                    scanf("%d%*c", &num);

                    for ( int i = 0; i < 100; i ++)
                    {
                        if ( Tab_numero_activite[i] == num)
                        {
                            position = i;
                            

                i = 190;
                        }
                        else position = 200;
                    }
                }
                else return;
            }


        printf(" \nSouhaitez vous  changer le nom ? \n\n");
        printf(" - ( O /N ) : ");
        scanf("%c%*c",&reponse);

        while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
        {
            printf("\n\n ---> Erreur de saisie !\n\n");
            printf("   Saisir a nouveau : \n");
            printf("   -----------------");
            printf("\n\n   - ( O / N ) : ");
            scanf("%c%*c", &reponse);
        }

        if ( reponse == 'o' || reponse == 'O')
        {
            printf("\n\n Quel est le nouveau nom de l'activite : ");
            scanf("%s%*c", Tab_nom_activite[position]);

                clean;
            printf("=================================================================================\n");
            printf("                            Modifier une activite\n");
            printf("=================================================================================\n"); 

            affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);
        }            

        printf(" Souhaitez vous  changer le numero  ? \n\n");
        printf(" - ( O /N ) : ");
        scanf("%c%*c",&reponse);

        while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
        {
            printf("\n\n ---> Erreur de saisie !\n\n");
            printf("   Saisir a nouveau : \n");
            printf("   -----------------");
            printf("\n\n   - ( O / N ) : ");
            scanf("%c%*c", &reponse);
        }

        if ( reponse == 'o' || reponse == 'O')
        {
            printf("\n\n Quel est le nouveau numero de l'activite : ");
            scanf("%d%*c", &valeur_temp);
            Tab_numero_activite[position] = valeur_temp;

           for (i = 0; i < 100; i ++)
            {

                if (i == position) i = i +1;

                while ( Tab_numero_activite[i] == Tab_numero_activite[position])
                {   
                    printf("\n\n Numero deja pris, reessayer : ");

                 scanf("%d%c", &valeur_temp);
                 Tab_numero_activite[position] = valeur_temp;

                 i = 0 ;

                }
            }

                clean;
            printf("=================================================================================\n");
            printf("                            Modifier une activite\n");
            printf("=================================================================================\n"); 
             affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);
        }            

        printf(" Souhaitez vous  changer le Tarif  ? \n\n");
        printf(" - ( O /N ) : ");
        scanf("%c%*c",&reponse);

        while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
        {
            printf("\n\n ---> Erreur de saisie !\n\n");
            printf("   Saisir a nouveau : \n");
            printf("   -----------------");
            printf("\n\n   - ( O / N ) : ");
            scanf("%c%*c", &reponse);
        }

        if ( reponse == 'o' || reponse == 'O')
        {
            printf("\n\n Quel est le nouveau tarif de l'activite : ");

            printf("\n\n Quel est son Tarif : ");
            scanf("%d%*c", &valeur_temp);

            Tab_tarif_activite[position] = valeur_temp; 

                clean;
            printf("=================================================================================\n");
            printf("                            Modifier une activite\n");
            printf("=================================================================================\n");         
        } 

         printf(" L'activite %s a bien ete modifie ! \n \n Son numero est le %d\n Son tarif est de %d\n\n",
                Tab_nom_activite[position], Tab_numero_activite[position], Tab_tarif_activite[position]);

        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

        char trash;
        wait;


}

void supprimer_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{
    clean;
    printf("=================================================================================\n");
    printf("                          Supprimer une activite\n");
    printf("=================================================================================\n"); 

    int i = 0, position = 0, valeur_temp =0, num  = 0;
    char reponse;

            affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

            printf("\n\n Quel est le numero de l'activite a supprimer  : ");
            scanf("%d%*c", &num);

        for ( int i = 0; i < 100; i ++)
        {
            if ( Tab_numero_activite[i] == num)
            {
                position = i;

                i = 190;
            }
            else position = 200;
        }

        while (position == 200)
            {
                printf("\n ---> Activite inexistante  ! \n\n");
                printf(" - Souhaitez vous recommencer ? \n\n - ( O / N ) : ");
                scanf("%c%*c", &reponse);

                while ( reponse != 'O' && reponse !='o' && reponse !='n' && reponse != 'N')
                {
                    printf("\n\n ---> Erreur de saisie !\n\n");
                    printf("   Saisir a nouveau : \n");
                    printf("   -----------------");
                    printf("\n\n   - ( O / N ) : ");
                    scanf("%c%*c", &reponse);
                }

                if (reponse == 'O' || reponse == 'o') 
                {
                     printf(" \n\nQuelle activite souhaitez vous supprimer  ? : ");
                    scanf("%d%*c", &num);

                    for ( int i = 0; i < 100; i ++)
                    {
                        if ( Tab_numero_activite[i] == num)
                        {
                            position = i;
                            

                i = 190;
                        }
                        else position = 200;
                    }
                }
                else return;
            }

            Tab_numero_activite[position] =  0;

        clean;
    printf("=================================================================================\n");
    printf("                          Supprimer une activite\n");
    printf("=================================================================================\n");
   

        printf(" \n\n L'activite %s ( numero %d ) a bien ete supprimee ! \n\n", Tab_nom_activite[position], num);

        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

        char trash;
        wait

}

void affichage_activite( int Tab_numero_activite[], int Tab_tarif_activite[], char Tab_nom_activite[100][20], int nbActivite, int Tab_nbr_entree_activite[])
{
    printf("   ====================================================================================================\n");
    printf("   | Nom de l'activite | Numero de l'activite | Tarif de l'activite | Nombre d'entree dans la journee |\n");
    printf("   |-------------------|----------------------|---------------------|---------------------------------|\n");

    for ( int i = 0; i < nbActivite; i ++)
    {
        if (Tab_numero_activite[i] != 0)  printf("   |%13s      | %11d          | %11d         | %15d                 | \n",
                                     Tab_nom_activite[i], Tab_numero_activite[i], Tab_tarif_activite[i], Tab_nbr_entree_activite[i]);
    }
    printf("   ====================================================================================================\n");
}

void Gestion_activite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents,  char Tab_nom_activite[100][20],  int Tab_nb_activite_adherent[100])
{
    char reponse ='g';
    int verif_2 = 0;

    clean;
    scanf("%*c");

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

    verif = verif_adherent(num_adherant,Tab_Presence_adherent, nbAdherents, Tab_numero_carte_adherent,  Tab_nb_activite_adherent);

if ( verif_2 == 4)
{
    printf(" ---> Adherent deja fait son nombre max d'activite ! \n\n");

    return;
    
}

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

    if (verif == 3) {

    return;
    }

    while (verif != 1  || verif != 3 || verif_2 != 4 )
    {
        if (verif ==2 ) return;
        verif_2 = verif_adherent(num_adherant,Tab_Presence_adherent, nbAdherents, Tab_numero_carte_adherent,  Tab_nb_activite_adherent);


        verif = effectuer_activite( num_adherant, Tab_numero_activite,  Tab_tarif_activite,  Tab_nbr_entree_activite,  Tab_numero_carte_adherent, Tab_Etat_carte,  Tab_credit_carte,   Tab_Presence_adherent, nbr_activite,  nbAdherents,  Tab_nom_activite, Tab_nb_activite_adherent);
    }
    
    if (verif >3 ) printf("\n ---> vous avez déjà fait 3 activités dans la journée !\n      Revenez demain !\n\n");

    
}

int effectuer_activite(int num_adherant, int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents,  char Tab_nom_activite[100][20],  int Tab_nb_activite_adherent[100])
{
    
    clean;
    printf("================================================================\n");
    printf("                  Effectuer une Activite\n");
    printf("================================================================\n\n\n");

    int activite = 0, verif = 0, position_adherent = 0, position_activite;
    char reponse;
    printf("\n\n\n - Les activite disponibles  :  \n");
    printf(    "   -----------------------------\n\n\n");
   
    affichage_activite( Tab_numero_activite, Tab_tarif_activite, Tab_nom_activite, nbr_activite, Tab_nbr_entree_activite);

    printf("\n\n   Choississez le numero de l'activite souhaitee : \n");
    printf(    "   ----------------------------------------------\n");
    printf("   - Votre reponse : ");
    scanf("%d%*c", &activite);

    position_adherent = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);

    verif = verif_activite(Tab_numero_activite, activite, nbr_activite);

    while ( verif == -1)
    {
        printf("\n ---> Activite inexistante ! \n\n");
        printf("   Souhaitez vous poursuivre ?  \n");
        printf("   --------------------------\n\n");
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

        if ( reponse == 'n' || reponse == 'N') return 1;
        else
        {
            clean;
        printf("================================================================\n");
        printf("                  Effectuer une Activite\n");
        printf("================================================================\n\n\n");

     printf("\n\n\n - Les activite disponibles  :  \n");
    printf(    "   -----------------------------\n\n\n");
   
    affichage_activite( Tab_numero_activite, Tab_tarif_activite, Tab_nom_activite, nbr_activite, Tab_nbr_entree_activite);

          printf("\n\n - Quelle activite l'adherent souhaite t'il faire :  \n");
        printf(    "   -----------------------------------------------\n");
    
        affichage_activite( Tab_numero_activite, Tab_tarif_activite, Tab_nom_activite, nbr_activite, Tab_nbr_entree_activite);

        printf("\n\n   Choississez le numero de l'activite souhaitee : \n");
        printf(    "   ----------------------------------------------\n");
        printf("   - Votre reponse : ");
        scanf("%d%*c", &activite);

        verif = verif_activite(Tab_numero_activite, activite, nbr_activite);
        }
    }

    position_activite = verif;

    verif = Tab_credit_carte[position_adherent] - Tab_tarif_activite[position_activite-1];  
   
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
        scanf("%*c");



       verif = Tab_credit_carte[position_adherent] - Tab_tarif_activite[position_activite-1];  
   }

   Tab_credit_carte[position_adherent] = verif;

   printf("\n L'activite %s a bien ete realise !\n l'adherent numero %d possede encore %d credit. \n", Tab_nom_activite[position_activite-1], Tab_numero_carte_adherent[position_adherent], Tab_credit_carte[position_adherent]);

Tab_nb_activite_adherent[position_adherent]= Tab_nb_activite_adherent[position_adherent] +1;
Tab_nbr_entree_activite[position_activite] = Tab_nbr_entree_activite[position_activite] +1 ;

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
   if (reponse == 'N' || reponse == 'n' ) return 2;

}


int verif_adherent(int num_adherant, int Tab_Presence_adherent[], int nbAdherents, int Tab_numero_carte_adherent[],  int Tab_nb_activite_adherent[100])
{
    int i = 0, verif = 6 , position = 0;

    position = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);


    if (verif != 1) return 2;

    for (i = 0; i <100; i ++)
    {
        if (Tab_Presence_adherent[i] == num_adherant) return 1;
    } 


    if ( Tab_nb_activite_adherent[position] >= 3) return 4;


 
    return 0;
}



int verif_activite(int Tab_numero_activite[],int  activite, int nbActivite)
{
    for (int i = 0; i <nbActivite; i ++ )
    {
        if (Tab_numero_activite[i] == activite) return i+1;
    }

    return -1;
}