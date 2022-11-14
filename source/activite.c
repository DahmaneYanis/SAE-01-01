#include "../header/global.h"
#include "../header/activite.h"
#include "../header/adherent.h"
#include "../header/menus.h"

/**
 * @brief  Affiche un menu pour supprimer, créer, modifier et afficher les activités, et appelle ensuite les fonctions en question. 
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param nbActivite  [ Taille Logique] Nombre d'activités total
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 */
void modif_crea_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{
    clean;
    int choix = 0;

    printf("=================================================================================\n");
    printf("                       Gestion des activites\n");
    printf("=================================================================================\n\n\n");

    //affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

    printf("   Choix disponibles : \n");
    printf("   ---------------\n\n");
    printf(" - 0. Retour au menu principal.\n - 1. Creer une activite.\n - 2. Modifier une activite. \n - 3. Supprimer une activite.\n - 4. Afficher les Activites\n\n");
    printf("Votre reponse : ");
    scanf("%d%*c", &choix);

    while ( choix < 0 || choix > 4)
    {
        printf("\n\n ---> Erreur de saisie !\n\n");
        printf("   Saisir a nouveau : \n");
        printf("   -----------------");
        printf("\n\n   - ( O / N ) : ");
        scanf("%d%*c", &choix);
    }

    switch (choix)
    {
        case 1 :
            clean;
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
            printf("                       Affichage des activites \n");
            printf("=================================================================================\n\n\n");
            affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

            char trash;
            wait;
            break;

        case 0 : return;
    }

}


/**
 * @brief  Permet de créer  une activité 
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param nbActivite  [ Taille Logique] Nombre d'activités total
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 */
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

            printf("\n\n Quel est le nom de l'activite ?  \n");
            printf(    " ------------------------------\n\n - Votre reponse : ");
            scanf("%s", Tab_nom_activite[position]);

            nbActivite = nbActivite +1;


            clean;
            printf("=================================================================================\n");
            printf("                            Creer une activite\n");
            printf("=================================================================================\n\n"); 

            printf("\n\n  Quel est son numero  ?\n");
            printf(    "  ---------------------\n\n");
            printf(" - Votre reponse : ");

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

            clean;
            printf("=================================================================================\n");
            printf("                            Creer une activite\n");
            printf("=================================================================================\n"); 

            printf("\n\n   Quel est son Tarif ? \n");
            printf(    "   -------------------\n\n");
            printf(" - Votre reponse : ");
    
            scanf("%d", &valeur_temp);

            Tab_tarif_activite[position] = valeur_temp;

            clean;
            printf("=================================================================================\n");
            printf("                            Creer une activite\n");
            printf("=================================================================================\n\n"); 

            printf(" \n\n L'activite %s a bien ete creee ! \n",  Tab_nom_activite[position]);
            printf(     "  ------------------------------\n\n");
            printf(" -> Son numero est le %d\n -> Son tarif est de %d\n\n\n", Tab_numero_activite[position], Tab_tarif_activite[position]);

        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

        char trash;
        wait;


}


/**
 * @brief  Permet de modifier une activité  
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param nbActivite  [ Taille Logique] Nombre d'activités total
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 */
void modifier_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{

    printf("=================================================================================\n");
    printf("                            Modifier une activite\n");
    printf("=================================================================================\n\n\n"); 
    
    int i = 0, position = 0, valeur_temp =0, num = 0;
    char reponse;

    affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

    printf("\n\n Quel est le numero de l'activite a modifier ( tapez 0 pour annuler ) ? \n");
    printf(    " ---------------------------------------------------------------------\n\n");
    printf(" - Votre reponse : ");
    scanf("%d%*c", &num);

    if (num == 0) return;

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
                    printf("\n\n Quel est le numero de l'activite a modifier ( tapez 0 pour annuler ) ? \n");
                    printf(    " ---------------------------------------------------------------------\n\n");
                    printf(" - Votre reponse : ");
                    scanf("%d%*c", &num);

                    if (num == 0) return;

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


        printf(" \n Souhaitez vous  changer le nom ? \n");
        printf(   " -------------------------------\n\n");
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
            printf("\n\n Quel est le nouveau nom de l'activite ?\n ");
            printf(    " --------------------------------------\n\n");
            printf(" - Votre reponse : ");
            scanf("%s%*c", Tab_nom_activite[position]);
        }
        clean;
        printf("=================================================================================\n");
        printf("                            Modifier une activite\n");
         printf("=================================================================================\n\n\n"); 
        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);           

        printf(" \n\nSouhaitez vous  changer le numero  ? \n");
        printf(" ----------------------------------\n\n");
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
            printf("\n\n Quel est le nouveau numero de l'activite :\n ");
            printf(    " -----------------------------------------\n\n");
            printf("- Votre reponse : ");
            scanf("%d%*c", &valeur_temp);
            Tab_numero_activite[position] = valeur_temp;

           for (i = 0; i < 100; i ++)
            {
                while ( (Tab_numero_activite[i] == Tab_numero_activite[position]) && i != position)
                {   
                    printf("\n\n ---> Numero deja pris, reessayer : ");

                 scanf("%d%c", &valeur_temp);
                 Tab_numero_activite[position] = valeur_temp;

                 i = 0;

                }
            }
        } 

        clean;
        printf("=================================================================================\n");
        printf("                            Modifier une activite\n");
        printf("=================================================================================\n\n\n"); 
        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);           

        printf("\n\n Souhaitez vous  changer le Tarif  ? \n");
        printf(" ----------------------------------\n\n");
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
            printf("\n\n Quel est le nouveau tarif de l'activite ?\n ");
            printf(    " ----------------------------------------\n\n");
            printf(" - Votre reponse : ");

            scanf("%d%*c", &valeur_temp);

            Tab_tarif_activite[position] = valeur_temp; 
         
        } 

        clean;
        printf("=================================================================================\n");
        printf("                            Modifier une activite\n");
        printf("=================================================================================\n\n\n");


         printf("\n\n L'activite %s a bien ete modifie !\n", Tab_nom_activite[position]);
         printf(    " ---------------------------------\n\n");
         printf("\n \n -> Son numero est le %d\n -> Son tarif est de %d\n\n", Tab_numero_activite[position], Tab_tarif_activite[position]);

        affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

        char trash;
        wait;


}


/**
 * @brief  Permet de supprimer une activité 
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param nbActivite  [ Taille Logique] Nombre d'activités total
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 */
void supprimer_activite(int Tab_numero_activite[], char  Tab_nom_activite[100][20], int Tab_tarif_activite[], int Tab_nbr_entree_activite[], int nbActivite)
{
    clean;
    printf("=================================================================================\n");
    printf("                          Supprimer une activite\n");
    printf("=================================================================================\n\n\n"); 

    int i = 0, position = 0, valeur_temp =0, num  = 0;
    char reponse;

            affichage_activite( Tab_numero_activite,  Tab_tarif_activite, Tab_nom_activite, nbActivite,  Tab_nbr_entree_activite);

            printf("\n\n Quel est le numero de l'activite a supprimer ( tapez 0 pour annuler ) ? \n");
            printf(    " ----------------------------------------------------------------------\n\n");
            printf(" - Votre reponse : ");
            scanf("%d%*c", &num);
            if ( num == 0) return;

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
                     printf(" \n\nQuelle activite souhaitez vous supprimer ( tapez 0 pour annuler ) ?\n");
                     printf(    " ----------------------------------------------------------------------\n\n");
                    printf(" - Votre reponse : ");
                    scanf("%d%*c", &num);

                    if ( num == 0) return;

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


/**
 * @brief  Permet de d'afficher une activité 
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param nbActivite  [ Taille Logique] Nombre d'activités total
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 */
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


/**
 * @brief Permet de lancer la consommation d'une activité, après avoir vérifié la validité du profil de l'adhérent. 
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 * @param Tab_numero_carte_adherent[ TABLEAU ] Liste de tous les numéros des cartes des adhérents 
 * @param Tab_Etat_carte[TABLEAU ] Liste des tous les etats des cartes adhérents
 * @param Tab_credit_carte[ TABLEAU ] Liste de tous les crédits de chaque adhérents 
 * @param Tab_Presence_adherent[TABLEAU ] Liste de la présence ou non dans adhérents dans le centre pour la journée 
 * @param nbr_activite [ TAILLE LOGIQUE ] Nombre d'activités total
 * @param  nbAdherents [ TAILLE LOGIQUE  ] Nombre d'adhérents total
 * @param Tab_nb_activite_adherent[ TABLEAU ] Liste du nombre d'activités réalisées par un ahdérent dans la journée. 
 */
void Gestion_activite(int  Tab_numero_activite[], int Tab_tarif_activite[],int  Tab_nbr_entree_activite[],int  Tab_numero_carte_adherent[], int  Tab_Etat_carte[], int  Tab_credit_carte[], int  Tab_Presence_adherent[], int nbr_activite, int nbAdherents,  char Tab_nom_activite[100][20],  int Tab_nb_activite_adherent[100])
{
    char reponse ='g';
    clean;


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

    verif = verif_adherent(num_adherant,Tab_Presence_adherent, nbAdherents, Tab_numero_carte_adherent,  Tab_nb_activite_adherent, Tab_Etat_carte);
  

    if ( verif == -1)
    {
        char trash;
        wait; 
        return;
    }

    while (verif < 3 && verif >= 0)
    {
        verif = verif + effectuer_activite( num_adherant, Tab_numero_activite,  Tab_tarif_activite,  Tab_nbr_entree_activite,  Tab_numero_carte_adherent, Tab_Etat_carte,  Tab_credit_carte,   Tab_Presence_adherent, nbr_activite,  nbAdherents,  Tab_nom_activite, Tab_nb_activite_adherent);
    }

    if (verif >= 3) 
    {
        printf("\n\n ---> L'adherent a fait ses 3 activites maximum dans la journee. Il doit attendre demain pour recommencer\n\n");
        char trash;
        wait;
    }

}


/**
 * @brief Permet de faire une activité et de vérifier la validité de l'activité choisie. 
 * 
 * @param num_adherant [ VARIABLE ] Numéro de l'adherent effectuant l'acitivité 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param Tab_nom_activite [TABLEAU] Liste du nouveau des activités 
 * @param Tab_tarif_activite [TABLEAU] Liste des tarifs des activités 
 * @param Tab_nbr_entree_activite [TABLEAU] Liste du nombre d'entrée par activité dans la journée.
 * @param Tab_numero_carte_adherent[ TABLEAU ] Liste de tous les numéros des cartes des adhérents 
 * @param Tab_Etat_carte[TABLEAU ] Liste des tous les etats des cartes adhérents
 * @param Tab_credit_carte[ TABLEAU ] Liste de tous les crédits de chaque adhérents 
 * @param Tab_Presence_adherent[TABLEAU ] Liste de la présence ou non dans adhérents dans le centre pour la journée 
 * @param nbr_activite [ TAILLE LOGIQUE ] Nombre d'activités total
 * @param  nbAdherents [ TAILLE LOGIQUE  ] Nombre d'adhérents total
 * @param Tab_nb_activite_adherent[ TABLEAU ] Liste du nombre d'activités réalisées par un ahdérent dans la journée. 
 */ 
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
    position_adherent = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);

    printf(    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf(  "\n | ->  Adherent numero : %7d |\n", num_adherant);
    printf(    " | ->  Credit restant  : %7d |\n", Tab_credit_carte[position_adherent]);
    printf(    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n   Choississez le numero de l'activite souhaitee : \n");
    printf(    "   ----------------------------------------------\n");
    printf("   - Votre reponse : ");
    scanf("%d%*c", &activite);

  

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

        if ( reponse == 'n' || reponse == 'N') return -6;
        else
        {
        clean;
        printf("================================================================\n");
        printf("                  Effectuer une Activite\n");
        printf("================================================================\n\n\n");

     printf("\n\n\n - Les activite disponibles  :  \n");
    printf(    "   -----------------------------\n\n\n");

        affichage_activite( Tab_numero_activite, Tab_tarif_activite, Tab_nom_activite, nbr_activite, Tab_nbr_entree_activite);
        printf(    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf(  "\n | ->  Adherent numero : %7d |\n", num_adherant);
        printf(    " | ->  Credit restant  : %7d |\n", Tab_credit_carte[position_adherent]);
        printf(    " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        printf("\n\n   Choississez le numero de l'activite souhaitee : \n");
        printf(    "   ----------------------------------------------\n");
        printf("   - Votre reponse : ");
        scanf("%d%*c", &activite);

        verif = verif_activite(Tab_numero_activite, activite, nbr_activite);
        }
    }

    position_activite = verif;

    verif = Tab_credit_carte[position_adherent] - Tab_tarif_activite[position_activite];  
   
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



        verif = Tab_credit_carte[position_adherent] - Tab_tarif_activite[position_activite];  
   }

   Tab_credit_carte[position_adherent] = verif;

   printf("\n L'activite %s a bien ete realise !\n l'adherent numero %d possede encore %d credit. \n", Tab_nom_activite[position_activite], Tab_numero_carte_adherent[position_adherent], Tab_credit_carte[position_adherent]);
    Tab_Presence_adherent[position_adherent] = 1;

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

   if (reponse == 'O' || reponse =='o') return 1;
   if (reponse == 'N' || reponse == 'n' ) return -10;

}

/**
 * @brief Permet de vérifier l'existence de l'adherent, le fait qu'il ne soit pas encore venu et la validité de sa carte.
 * 
 * @param Tab_numero_carte_adherent[ TABLEAU ] Liste de tous les numéros des cartes des adhérents 
 * @param Tab_Etat_carte[TABLEAU ] Liste des tous les etats des cartes adhérents
 * @param Tab_Presence_adherent[TABLEAU ] Liste de la présence ou non dans adhérents dans le centre pour la journée 
 * @param  nbAdherents [ TAILLE LOGIQUE  ] Nombre d'adhérents total
 * @param Tab_nb_activite_adherent[ TABLEAU ] Liste du nombre d'activités réalisées par un ahdérent dans la journée. 
 */
int verif_adherent(int num_adherant, int Tab_Presence_adherent[], int nbAdherents, int Tab_numero_carte_adherent[],  int Tab_nb_activite_adherent[100], int Tab_Etat_carte[])
{

    int i = 0, verif = 0 , position = 0;

    position = TrouverAdherent(Tab_numero_carte_adherent, nbAdherents, num_adherant, &verif);

    if ( position == -1 )
    {
    printf("\n\n ---> Adherent non existant \n\n");
    return -1;
    }

    for (i = 0; i <100; i ++)
    {
        if (Tab_Presence_adherent[position] == 1)
       {
        printf("\n\n ---> Adherent deja venu aujourd'hui !\n\n");
        return -1;
       }
    } 

    if ( Tab_Etat_carte[position] != 1)
    {
        printf("\n\n ---> La carte de l'adherent est desactive pour la raison suivante : ");
        etat_desac(1, Tab_Etat_carte[position]);
        printf("\n ---> Veuillez reactiver sa carte pour effectuer des activites....\n\n");
        return -1;
    }

    return 0;
}


/**
 * @brief Permet de voir si l'activité existe bien.
 * 
 * @param Tab_numero_activite [TABLEAU] Liste des numéros d'activités 
 * @param nbActivite [ TAILLE LOGIQUE ] Nombre d'activités total
 * @param  activite [ Variable ] numero de l'activité étudiée
 * @param Tab_nb_activite_adherent[ TABLEAU ] Liste du nombre d'activités réalisées par un ahdérent dans la journée. 
 */ 
int verif_activite(int Tab_numero_activite[],int  activite, int nbActivite)
{
    for (int i = 0; i <nbActivite; i ++ )
    {
        if (Tab_numero_activite[i] == activite) return i;
    }

    return -1;
}