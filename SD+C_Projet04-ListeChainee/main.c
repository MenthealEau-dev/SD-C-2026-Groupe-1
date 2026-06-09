/*

********************************************************

  Programme :  Gestion des ordinateurs
              par des étudiants en SD+C .
  Nom : SD+C - Gestion d'entiers à partir
                d'une liste chaînée
   Auteurs :
            1. ABIDI Mawusé Jean-Marie Gédéon (GM)
            2. AKONDO Samihatou               (GC)
            3. AKOTSU Yao Aurelien Placide    (GM)
            4. AGBOGAN Komlan Marcel          (GC)
            5. BARA Oussonè Bryann           (IA&BD)
            6. ETOH Fortunatus                (GM)
            7. TCHA-ZAWA Abdou Moudjib       (IA&BD)
            8. TINANKPA Wilfried kodjo       (IA&BD)
            9. ZAMNA Mahamat Salim            (GM)


  IDE : Code::Blocks
  Chargé de l'UE : Monsieur AKAKPO
  Niveau : L1 Semestre 2
  Date de création : 07/06/2026
  Date de rendu : 09/06/2026

********************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "liste.h"


int main()
{
    setlocale(LC_ALL,"");
    int choix = 0;
    int valeur;
    int position = 0;
    TListe *liste;
    if((liste = (TListe*)malloc(sizeof(TListe))) == NULL)
        exit(1);
    initialiser_liste(liste);
    while(choix != 8)
    {
        choix = menu();
        switch(choix)
        {
        case 1:
            if(liste->taille == 0){
                printf("AJOUT DANS UNE LISTE VIDE\n");
                saisir_informations(&valeur);
                inserer_dans_liste_vide(liste,valeur);
                afficher(liste);
            }
            else{
                printf("\nVotre liste n'est plus vide");
            }
            break;
        case 2:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("AJOUT AU DEBUT DE LA LISTE\n");
                saisir_informations(&valeur);
                inserer_en_tete_de_liste(liste,valeur);
                afficher(liste);
            }
            break;
        case 3:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("AJOUT A LA  FIN DE LA LISTE\n");
                saisir_informations(&valeur);
                inserer_en_queue_de_liste(liste,valeur);
                afficher(liste);
            }
            break;
        case 4:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("AJOUT APRES UNE POSITION SPECIFIQUE\n");
                while(position < 1 || position > liste->taille)
                {
                    printf("Veuillez entrer une position positive non nulle inférieure ou égale à %d : ", liste->taille );
                    scanf("%d", &position);
                }
                saisir_informations(&valeur);
                inserer_en_position(liste,valeur,position);
                afficher(liste);
                position = 0;
            }
            break;
        case 5:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("SUPPRESSION AU DEBUT DE LA LISTE\n");
                if(liste->taille == 1){
                    printf("Voulez vous détruire la liste?");
                    printf("\nSi oui tapez 1 si non tapez 0 : ");
                    scanf("%d",&position);
                    if(position == 1)
                        detruire_liste(liste);
                }
                else{
                    supprimer_en_debut_de_liste(liste);
                    afficher(liste);
                }
            }
            break;
        case 6:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("SUPPRESSION APRES UNE POSITION SPECIFIQUE\n");
                while(position < 1 || position > liste->taille)
                {
                    printf("Veuillez entrer une position positive non nulle inférieure ou égale à %d : ", liste->taille );
                    scanf("%d", &position);
                }
                supprimer_dans_liste(liste,position);
                if(liste->taille != 0)
                    afficher(liste);
                position = 0;
            }
            break;
        case 7:
            if(liste->taille == 0){
                printf("Votre liste est vide. Veuillez vous référer au menu 1.");
            }
            else{
                printf("DESTRUCTION DE LA LISTE");
                detruire_liste(liste);
            }
            break;
        case 8:
            break;
        default:
            printf("Veuillez choisir un menu correct compris entre 1 et 8! Merci ");
            break;
        }
    }
    printf("\nMerci d'avoir visité notre menu!\n");

    return 0;
}
