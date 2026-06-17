#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynome.h"

void initialiser_polynome(Tpolynome*polynome)
{
    polynome->first = NULL;
    polynome->last = NULL;
    polynome->taille = 0;
}

int  inserer_dans_polynome(Tpolynome *polynome, int coef,int exp)

{

    Tterme*nouveau = (Tterme*)malloc(sizeof(Tterme));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->coef = coef;
    nouveau->exp = exp;
    nouveau->next = NULL;

    // Cas 1 : polynôme vide ou insertion en tête
     if (polynome->first == NULL) {
        polynome->first = nouveau;
        polynome->last = nouveau;
        polynome->taille++;
        return 1;
    }

    else{
        nouveau->next = NULL;
        polynome->last->next = nouveau;
        polynome->last = nouveau;
        polynome->taille++;
        return 1;
    }
}
void afficher_polynome(Tpolynome*polynome)
 {

    if (polynome->first == NULL) {
        printf("P = 0\n");
        return;
    }

    Tterme *courant = polynome->first;

    while (courant != NULL) {
        if(courant != polynome->first ){
            if (courant->coef >=0 ) {
                printf("+");
            }
            else {
                    printf("-");
            }
            }
        // Afficher le coefficient
        printf("%d", abs(courant->coef));

        // Afficher la variable x
        if (courant->exp > 0) {
            printf("x");
            if (courant->exp > 1) {
                printf("^%d", courant->exp);
            }
        }

        courant = courant->next;
    }
    printf("\n");
}

Tpolynome additionner_polynome(Tpolynome *P1, Tpolynome *P2) {
    Tpolynome resultat;
    initialiser_polynome(&resultat);

    Tterme *courant1 = P1->first;
    Tterme *courant2 = P2->first;

    // Parcours simultané des deux polynômes
    while (courant1 != NULL && courant2 != NULL) {
        if (courant1->exp == courant2->exp) {
            inserer_dans_polynome(&resultat, courant1->coef + courant2->coef, courant1->exp);
            courant1 = courant1->next;
            courant2 = courant2->next;
        } else if (courant1->exp > courant2->exp) {
            inserer_dans_polynome(&resultat, courant1->coef, courant1->exp);
            courant1 = courant1->next;
        } else {
            inserer_dans_polynome(&resultat, courant2->coef, courant2->exp);
            courant2 = courant2->next;
        }
    }

    // Ajouter les termes restants
    while (courant1 != NULL) {
        inserer_dans_polynome(&resultat, courant1->coef, courant1->exp);
        courant1 = courant1->next;
    }
    while (courant2 != NULL) {
        inserer_dans_polynome(&resultat, courant2->coef, courant2->exp);
        courant2 = courant2->next;
    }

    return resultat;
}

