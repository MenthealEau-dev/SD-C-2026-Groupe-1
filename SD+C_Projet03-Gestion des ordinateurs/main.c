#include <stdio.h>
#include <stdlib.h>
#include "Mesfonctions.h"
#include "Ordinateur.h"
#include "FonctionsTries.h"
#include <locale.h>



int main(void)
{
    setlocale(LC_ALL, "");
    Tordinateur ** park;
    Tordinateur ** pointeur_tab = NULL;
    int menu;
    int nbreOrdi;
    int sortie = 0;
    int i = 0;

    printf("CHER CLIENT! BIENVENUE A VOTRE MEMU D'OPERATION\n\n");
    printf("1: AJOUTER UN ORDINATEUR\n 2: SUPPRIMER UN ORDINATEUR\n 3: LISTE DES ORDINATEURS\n");
    printf("4: DETAIL D'UN ORDINATEUR\n 5: REPARTITION PAR SPECIALITE\n");
    printf("6: REPARTITION PAR MARQUE \n 7: REPARTITION PAR VITESSE DU CPU\n 8:VALEUR TOTAL DU PARK\n 0:EXIT\n");
    while (sortie != 1)
    {
        printf("\n VEUILLEZ CHOISIR UN MENU\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                printf("BIENVENUE DANS LE MENU AJOUT D'ORDINATEUR \n");
                park = saisir_listeOrdinateur(nbreOrdi);
                break;
            case 2:
                printf("BIENVENUE DANS LE MENU SUPPRESSION D'ORDINATEUR \n");
                supprimer_Ordinateur(park, nbreOrdi);
                break;
            case 3:
                printf("BIENVENUE DANS LE MENU LISTE DES ORDINATEURS \n");
                informations_desOrdinateurs(park,nbreOrdi);
                break;
            case 4:
                printf("BIENVENUE DANS LE MENU DETAIL D'UN ORDINATEUR \n");
                afficher_details_d_un_ordinateur (park, nbreOrdi);
                break;
            case 5:
                printf("BIENVENUE DANS LE MENU DE REPARTITION PAR SPECIALITE \n");
                repartitonSpecialite(park, nbreOrdi);
                break;
            case 6:
                printf("BIENVENUE DANS LE MENU DE REPARTITION PAR MARQUE \n");
                repartitionMarque (park, nbreOrdi);
                break;
            case 7:
                printf("BIENVENUE DANS LE MENU DE REPATITION PAR VITESSE DU CPU \n");
                trier_parVitesse(park, nbreOrdi);
                break;
            case 8:
                printf("BIENVENUE DANS LE MENU VALEUR TOTALE DU PARK \n ");
                calculer_sommePrix(park, nbreOrdi);
                break;
            case 0:
                printf("MERCI D'AVOIR VISITE LE MENU \n");
                sortie = 1;
                break;
            default:
                printf("VEUILLEZ CHOISIR UN MENU COMPRIS ENTRE 0 ET 8 \n");
                break;

        }
    }


free(park);
park=NULL;

}
