#include <stdio.h>
#include <stdlib.h>
#include "polynomes.h"

void Initialisation(Polynome *p) {
    p->tete = NULL;
}

/*Insere un monome en gardant la liste triee par degre decroissant */
void Ajouter_Poly(Polynome *p, int degre, int coeff) {
    Monome *nouveau = (Monome*)malloc(sizeof(Monome));
    nouveau->coefficient = coeff;
    nouveau->degre = degre;
    nouveau->suivant = NULL;

    /*Liste vide où nouveau degre est le plus grand */
    if (p->tete == NULL || degre > p->tete->degre) {
        nouveau->suivant = p->tete;
        p->tete = nouveau;
        return;
    }

    /*On cherche la bonne position */
    Monome *courant = p->tete;
    while (courant->suivant != NULL && courant->suivant->degre > degre) {
        courant = courant->suivant;
    }
    nouveau->suivant = courant->suivant;
    courant->suivant = nouveau;
}

void Afficher_Poly(Polynome *p) {
    Monome *courant = p->tete;
    if (courant == NULL) {
        printf("P(x) = 0\n");
        return;
    }
    /*Afficher le premier monome*/
    printf("P(x) = ");
    printf("%dx^%d", courant->coefficient, courant->degre);
    courant = courant->suivant;

    /*Verification des signes d'affichage*/
    while (courant != NULL) {
        if(courant->coefficient == 0){
            printf("0");
        }
        if(courant->coefficient >= 0) printf(" + %dx^%d", courant->coefficient, courant->degre);
        else printf(" %dx^%d", courant->coefficient, courant->degre);

        courant = courant->suivant;
        }

    printf("\n");
}

/*Ici concatenation au lieu d'addition*/
Polynome* Additionner(Polynome *p1, Polynome *p2) {
    Polynome *res = (Polynome*)malloc(sizeof(Polynome));
    Initialisation(res);

    Monome *courant = p1->tete;
    while (courant != NULL) {
        Ajouter_Poly(res, courant->degre, courant->coefficient);
        courant = courant->suivant;
    }
    courant = p2->tete;
    while (courant != NULL) {
        Ajouter_Poly(res, courant->degre, courant->coefficient);
        courant = courant->suivant;
    }
    return res;
}


/*Ici concatenation au lieu de soustraction avec changement de signe*/
Polynome* Soustraire(Polynome *p1, Polynome *p2) {
    Polynome *res = (Polynome*)malloc(sizeof(Polynome));
    Initialisation(res);

    Monome *courant = p1->tete;
    while (courant != NULL) {
        Ajouter_Poly(res, courant->degre, courant->coefficient);
        courant = courant->suivant;
    }
    courant = p2->tete;
    while (courant != NULL) {
        Ajouter_Poly(res, courant->degre, -(courant->coefficient));
        courant = courant->suivant;
    }
    return res;
}
