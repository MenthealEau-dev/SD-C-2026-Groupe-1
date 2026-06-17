#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

int main()
{
    Tpolynome *polynome1;
    Tpolynome *polynome2;
    Tpolynome *sommePolynome;
    int choix;

    if ((polynome1 = (Tpolynome *) malloc(sizeof(Tpolynome))) == NULL){
        exit(-1);
    }if ((polynome2 = (Tpolynome *) malloc(sizeof(Tpolynome))) == NULL){
        exit(-1);
    }
    initialise_polynome(polynome1);
    initialise_polynome(polynome2);
    choix = menu();

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
        break;
    case 2:
        entrez_informations(polynome1,polynome2);
        afficher_polynome(polynome1);
        afficher_polynome(polynome2);
        break;
    case 3:
        break;
    default:
        printf("Choix invalide.\n");
    }
    return 0;
}
