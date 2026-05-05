/*

********************************************************

  Programme :  Gestion des ordinateurs
              par des étudiants en SD+C .
  Nom : SD+C - Les fondamentaux – Exercice 3
  Ecrit en formalisme pointeur
  Auteurs :
            1. ABIDI Mawusé Jean-Marie Gédéon (GM)
            2. AKONDO Samihatou (GC)
            3. AKOTSU Yao Aurelien Placide (GM)
            4. AGBOGAN Komlan Marcel (GC)
            5. BARA Oussonè Bryann (IA&BD)
            6. ETOH Fortunatus (GM)
            7. TCHA-ZAWA Abdou Moudjib (IA&BD)
            8. TINANKPA Wilfried kodjo (IA&BD)
            9. ZAMNA Mahamat Salim (GM)

  IDE : Code::Blocks
  Chargé de l'UE : Monsieur AKAKPO
  Niveau : L1 Semestre 2
  Date de création : 27/04/2026
  Date de rendu : 29/04/2026

********************************************************
*/


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

    printf("\n=== MENU PRINCIPAL ===\n");
        printf("1: AJOUTER UN ORDINATEUR\n");
        printf("2: SUPPRIMER UN ORDINATEUR\n");
        printf("3: LISTE DES ORDINATEURS\n");
        printf("4: DETAIL D'UN ORDINATEUR\n");
        printf("5: REPARTITION PAR SPECIALITE\n");
        printf("6: REPARTITION PAR MARQUE\n");
        printf("7: TRI PAR VITESSE DU CPU\n");
        printf("8: VALEUR TOTALE DU PARK\n");
        printf("0: EXIT\n");
    while (sortie != 1)
    {
        printf("\n VEUILLEZ CHOISIR UN MENU\n");
        scanf("%d",&menu);
        switch(menu)
        {
            case 1:
                printf("MENU AJOUT D'ORDINATEUR \n");
                park = saisir_listeOrdinateur(nbreOrdi);
                break;
            case 2:
                printf("MENU SUPPRESSION D'ORDINATEUR \n");
                supprimer_Ordinateur(&(**park), nbreOrdi);
                break;
            case 3:
                printf("MENU LISTE DES ORDINATEURS \n");
                informations_desOrdinateurs(park, nbreOrdi);
                break;
            case 4:
                printf("MENU DETAIL D'UN ORDINATEUR \n");
                afficher_details_d_un_ordinateur (park, nbreOrdi);
                break;
            case 5:
                printf("MENU DE REPARTITION PAR SPECIALITE \n");
                repartitonSpecialite(park, nbreOrdi);
                break;
            case 6:
                printf("MENU DE REPARTITION PAR MARQUE \n");
                repartitionMarque (park, nbreOrdi);

                break;
            case 7:
                printf("MENU DE REPATITION PAR VITESSE DU CPU \n");
                trier_parVitesse(park, nbreOrdi);
                break;
            case 8:
                printf("MENU VALEUR TOTALE DU PARK \n ");
                calculer_sommePrix(park, nbreOrdi);
                break;
            case 0:
                printf("\n MERCI D'AVOIR VISITE LE MENU \n");
                sortie = 1;
                break;
            default:
                printf("VEUILLEZ CHOISIR UN MENU COMPRIS ENTRE 0 ET 8 \n");
                break;

        }
    }


free(park);
park=NULL;

return 0;
}
