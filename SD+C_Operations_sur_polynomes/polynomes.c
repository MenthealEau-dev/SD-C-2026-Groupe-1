#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "polynomes.h"

/*================polynomes.c=====================*/

// 1-Création de la fonction de création et d'initialisation d'un polynome

TPolynome *creer_initialiser_poly()
{
    TPolynome *polynome;
    if((polynome = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
        exit(1);
    polynome->first = NULL;
    polynome->last = NULL;
    polynome->taille = 0;

    return polynome;
}

// 2-1-1-Création de la fonction d'insertion dans une liste vide

int inserer_dans_liste_vide(TPolynome *polynome, int coef, int degre)
{
    TCellule *nouveau;
    if((nouveau = (TCellule*)malloc(sizeof(TCellule))) == NULL)
        exit(1);
    nouveau->monome.coef = coef;
    nouveau->monome.degre = degre;
    nouveau->next = polynome->first;
    polynome->first = nouveau;
    polynome->last = nouveau;
    polynome->taille++;

    return 0;
}

// 2-1-2-Création de la fonction d'insertion en fin de liste

int inserer_en_queue_de_liste(TPolynome *polynome, int coef, int degre)
{
    TCellule *nouveau;
    if((nouveau = (TCellule*)malloc(sizeof(TCellule))) == NULL)
        exit(1);
    nouveau->monome.coef = coef;
    nouveau->monome.degre = degre;
    nouveau->next = NULL;
    polynome->last->next = nouveau;
    polynome->last = nouveau;
    polynome->taille++;

    return 0;
}

// 2-1-Création de la fonction d'insertion dans une liste

int inserer_dans_liste(TPolynome *polynome, int coef, int degre)
{
    if(polynome->taille == 0)
        inserer_dans_liste_vide(polynome,coef,degre);
    else
        inserer_en_queue_de_liste(polynome,coef,degre);

    return 0;
}

// 2-Création de la fonction de saisie des informations d'un polynome

void saisir_infoPolynome(TPolynome *polynome, int indice)
{
    int exposant = 0;
    int choix = 1;
    printf("\nINFORMATIONS DU POLYNOME N° %d : \n", indice);
    printf("\nVeuillez taper :\n'1' Pour répondre 'Oui'\n'0' Pour répondre 'Non' aux questions! Merci\n");
    while(choix == 1)
    {
        while(choix == 1)
        {
            int coefficient;
            printf("\nEntrer le coefficient du monône de degré %d ", exposant);
            printf("\nTapez '0' s'il y'en a pas : ");
            scanf("%d", &coefficient);
            inserer_dans_liste(polynome,coefficient,exposant);
            exposant++;
            if(coefficient == 0)
            choix = 0;
        }
        printf("\nY'a t'il d'autres monômes à ajouter au polynôme? ");
        scanf("%d",&choix);
    }
}
/*==============fin polynomes.c===================*/
