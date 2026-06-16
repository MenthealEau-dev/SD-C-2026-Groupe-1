/*
************************************
Programme : Polynome_Addition

Auteur : TINANKPA Wilfried Kodjo

Groupe : 01

IDE : Code::Blocks

Chargé de l'UE : M.AKAKPO

Niveau : L1 Semestre 2

Date de rendu : 16/06/2026
************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

int main() {

    int choix, c, d;

    Polynome *p1 = (Polynome*)malloc(sizeof(Polynome));
    Polynome *p2 = (Polynome*)malloc(sizeof(Polynome));
    Initialisation(p1);
    Initialisation(p2);

    choix = 0;
    while (choix != 5) {
        printf("\n------MENU------\n");
        printf("1 - Ajouter un monome dans P1\n");
        printf("2 - Ajouter un monome dans P2\n");
        printf("3 - Afficher P1 + P2\n");
        printf("4 - Afficher P1 - P2\n");
        printf("5 - Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Coefficient : ");
                scanf("%d", &c);
                printf("Degre : ");
                scanf("%d", &d);
                Ajouter_Poly(p1, d, c);
                printf("P1 : ");
                Afficher_Poly(p1);
                break;

            case 2:
                printf("Coefficient : ");
                scanf("%d", &c);
                printf("Degre : ");
                scanf("%d", &d);
                Ajouter_Poly(p2, d, c);
                printf("P2 : ");
                Afficher_Poly(p2);
                break;

            case 3: {
                Polynome *somme = Additionner(p1, p2);
                printf("P1 + P2 : ");
                Afficher_Poly(somme);
                free(somme);
                break;
            }

            case 4: {
                Polynome *diff = Soustraire(p1, p2);
                printf("P1 - P2 : ");
                Afficher_Poly(diff);
                free(diff);
                break;
            }

            case 5:
                break;

            default:
                printf("Choix invalide.\n");

        }//Fin du switch

    }//Fin du while

    printf("\nFIN DU PROGRAMME\n");
    return 0;

}//Fin du main
