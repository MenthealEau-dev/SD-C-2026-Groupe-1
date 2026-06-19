#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

int main()
{
    Tpolynome *polynome1;
    Tpolynome *polynome2;
    Tpolynome *sommePolynome;
    Tpolynome *differencePolynome;
    int choix;

    if ((polynome1 = (Tpolynome *) malloc(sizeof(Tpolynome))) == NULL){
        exit(-1);
    }if ((polynome2 = (Tpolynome *) malloc(sizeof(Tpolynome))) == NULL){
        exit(-1);
    }
    choix = menu();

    while (choix != 3){
        initialise_polynome(polynome1);
        initialise_polynome(polynome2);
        switch (choix)
        {
        case 1:
            entrez_informations(polynome1,polynome2);
            printf("\nVotre Premier Polynome est : ");
            afficher_polynome(polynome1);

            printf("\nVotre Deuxieme Polynome est : ");
            afficher_polynome(polynome2);

            printf("\nLa sommme de vos Polynomes est : ");
            sommePolynome = addition_de_polynomes(polynome1,polynome2);
            afficher_polynome(sommePolynome);
            liberer_polynome(sommePolynome);
            printf("\n");
            break;
        case 2:
            entrez_informations(polynome1,polynome2);
            printf("\nVotre Premier Polynome est : ");
            afficher_polynome(polynome1);

            printf("\nVotre Deuxieme Polynome est : ");
            afficher_polynome(polynome2);

            differencePolynome = soustraction_de_polynomes(polynome1,polynome2);
            printf("\nLa difference de vos Polynomes est : ");
            afficher_polynome(differencePolynome);
            liberer_polynome(differencePolynome);
            printf("\n");
            break;
        case 3:
            printf("\nAu revoir!!");
            break;
        default:
            printf("Choix invalide.\n");
        }
        choix = menu();
    }
    liberer_polynome(polynome1);
    liberer_polynome(polynome2);
    return 0;
}
