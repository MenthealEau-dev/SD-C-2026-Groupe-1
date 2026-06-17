#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

void initialise_polynome (Tpolynome *polynome)
{
    polynome ->debut = NULL;
    polynome ->fin = NULL;
    polynome ->taille = 0;
}



int inserer_dans_polynome_vide (Tpolynome *polynome, int coeff)
{
    Telement *nouveauMonome;
    if ((nouveauMonome = (Telement *) malloc(sizeof(Telement))) == NULL){
            return -1;
    }

    nouveauMonome ->monome.coeff = coeff;
    nouveauMonome ->monome.degre = 0;
    nouveauMonome ->suivant = NULL;
    polynome ->debut = nouveauMonome;
    polynome ->fin = nouveauMonome;
    polynome ->taille++;

    return 0;
}


//inserez a la fin du polynome
int inserer_fin_du_polynome(Tpolynome *polynome, int coeff)
{
    Telement *nouveauMonome;
    if ((nouveauMonome = (Telement *) malloc(sizeof(Telement))) == NULL){
            return -1;
    }

    nouveauMonome ->monome.coeff = coeff;
    nouveauMonome ->monome.degre = polynome ->taille;
    polynome ->fin ->suivant = nouveauMonome;
    nouveauMonome ->suivant = NULL;
    polynome ->fin = nouveauMonome;
    polynome ->taille++;

    return 0;
}


//saisi les informations du polynome
int saisi_dans_polynome(Tpolynome *polynome, int coeff)
{
    if (polynome ->taille == 0) inserer_dans_polynome_vide(polynome, coeff);

    else inserer_fin_du_polynome(polynome, coeff);

    return 0;
}


//aficher le polynome
void afficher_polynome (Tpolynome *polynome)
{
    Telement *courant;
    courant = polynome ->debut;

    while (courant != NULL){
        if (courant ->monome.coeff != 0){
            if (courant ->monome.coeff > 0 && courant != polynome ->debut)
                printf("+");
            if (courant ->monome.degre == 0) printf("%d", courant ->monome.coeff);
            else if (courant ->monome.coeff == 1){
                if (courant ->monome.degre == 1) printf("X");
                else printf("X^%d", courant ->monome.degre);
            }
            else if (courant ->monome.coeff == -1){
                if (courant ->monome.degre == 1) printf("-X");
                else printf("-X^%d", courant ->monome.degre);
            }
            else if (courant ->monome.degre ==1) printf("%dX", courant ->monome.coeff);
            else printf("%dX^%d", courant ->monome.coeff, courant ->monome.degre);
        }
        courant = courant ->suivant;
    }
    printf("\n");
}


//saisi informations
int entrez_informations (Tpolynome *polynome1, Tpolynome *polynome2)
{
    int cpt;
    int coeff;
    for (cpt = 1; cpt <3; cpt++){
            int continuer = 1;
            printf("\nEntrez le polynome %d",cpt);
            while(continuer != 0){
                printf("\nEntrez le coefficient du monome : ");
                scanf("%d", &coeff);
                if (cpt == 1)
                    saisi_dans_polynome(polynome1, coeff);
                else
                    saisi_dans_polynome(polynome2, coeff);
                if (coeff ==0){
                    printf("\nY a t-il d'autres monomes\nSi oui taper 1, sinon taper 0 : ");
                    scanf("%d", &continuer);
                }
            }
        }
        return 0;
}


//additione de deux polynomes
Tpolynome *addition_de_polynomes(Tpolynome *polynome1, Tpolynome *polynome2)
{
    Tpolynome *sommePolynome;
    Telement *courant1 = polynome1 ->debut;
    Telement *courant2 = polynome2 ->debut;
    int soe = 0;

    if ((sommePolynome = (Tpolynome*) malloc(sizeof(Tpolynome))) == NULL)
        exit(-1);
    initialise_polynome(sommePolynome);

    while (courant1 != NULL && courant2 != NULL){
        soe = courant1 ->monome.coeff + courant2 ->monome.coeff;
        saisi_dans_polynome(sommePolynome, soe);
        courant1 = courant1 ->suivant;
        courant2 = courant2 ->suivant;
    }

    while(courant1 != NULL){
        saisi_dans_polynome(sommePolynome, courant1 ->monome.coeff);
        courant1 = courant1 ->suivant;
    }

    while(courant2 != NULL){
        saisi_dans_polynome(sommePolynome, courant2 ->monome.coeff);
        courant2 = courant2 ->suivant;
    }
    return sommePolynome;
}



//menu pour les operations
int menu()
{
    int choix;
    printf("*====================================*\n");
    printf("*             BIENVENUE              *\n");
    printf("**************************************\n");
    printf("*                MENU                *\n");
    printf("*------------------------------------*");
    printf("\n*  1. ADDITION DE DEUX POLYNOMES     *");
    printf("\n*  2. SOUSTRACTION DE DEUX POLYNOMES *");
    printf("\n*  3. QUITTER                        *");
    printf("\n=====================================*");
    printf("\n Faites votre choix : ");
    scanf("%d",&choix);
    return choix;
}
