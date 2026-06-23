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

// 3-Création de la fonction d'affichage d'un polynôme

void afficher_polynome(TPolynome *polynome, int indice)
{
    printf("\nAFFICHAGE : ");
    if (polynome == NULL || polynome->first == NULL) {
        printf("0 (Polynome vide)\n");
        return;
    }
    int premier = 1;// Gestion du signe du premier élement
    TCellule *balai;
    balai = polynome->first;
    while(balai != NULL)
    {
        if(balai->monome.coef != 0)
        {
            if(!premier && balai->monome.coef > 0)
                printf("+");
            if(balai->monome.degre == 0)
                printf("%d ",balai->monome.coef);
            else if(balai->monome.degre == 1)
                printf("%dx ",balai->monome.coef);
            else
                printf("%dx^%d ",balai->monome.coef, balai->monome.degre);
            premier = 0;
        }
        balai = balai->next;
    }
    printf("\n");
}

// 4-Création de la fonction d'addition de deux polynômes

TPolynome *additionner_polynomes(TPolynome *polynome1, TPolynome *polynome2)
{
    int sumCoef, sumDegre;
    TPolynome *relai;
    if((relai = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
        exit(1);
    relai->first = relai->last = NULL;
    relai->taille = 0;
    TCellule *balai1;
    TCellule *balai2;
    balai1 = polynome1->first;
    balai2 = polynome2->first;
    while(balai1 != NULL && balai2 != NULL)
    {
        sumCoef = (balai1->monome.coef) + (balai2->monome.coef);
        sumDegre = balai1->monome.degre;
        inserer_dans_liste(relai,sumCoef,sumDegre);
        balai1 = balai1->next;
        balai2 = balai2->next;
    }
    if(balai1 == NULL)
    {
        while(balai2 != NULL)
        {
            inserer_en_queue_de_liste(relai,balai2->monome.coef,balai2->monome.degre);
            balai2 = balai2->next;
        }
    }
    if(balai2 == NULL)
    {
        while(balai1 != NULL)
        {
            inserer_en_queue_de_liste(relai,balai1->monome.coef,balai1->monome.degre);
            balai1 = balai1->next;
        }
    }
    return relai;
}

// 5-Création de la fonction de soustraction de deux polynômes

TPolynome *soustraire_polynomes(TPolynome *polynome1, TPolynome *polynome2)
{
    int sumCoef, sumDegre;
    TPolynome *relai;
    if((relai = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
        exit(1);
    relai->first = relai->last = NULL;
    relai->taille = 0;
    TCellule *balai1;
    TCellule *balai2;
    balai1 = polynome1->first;
    balai2 = polynome2->first;
    while(balai1 != NULL && balai2 != NULL)
    {
        sumCoef = (balai1->monome.coef) - (balai2->monome.coef);
        sumDegre = balai1->monome.degre;
        inserer_dans_liste(relai,sumCoef,sumDegre);
        balai1 = balai1->next;
        balai2 = balai2->next;
    }
    if(balai1 == NULL)
    {
        while(balai2 != NULL)
        {
            inserer_en_queue_de_liste(relai,-(balai2->monome.coef),balai2->monome.degre);
            balai2 = balai2->next;
        }
    }
    if(balai2 == NULL)
    {
        while(balai1 != NULL)
        {
            inserer_en_queue_de_liste(relai,balai1->monome.coef,balai1->monome.degre);
            balai1 = balai1->next;
        }
    }
    return relai;
}

// 6-Création de la fonction de destruction d'un polynôme

void detruire_polynome(TPolynome *polynome)
{
        if(polynome->taille == 0)
            return;
        TCellule *elementsup;
        TCellule *supsuivant;
        elementsup = polynome->first;
        while(elementsup != NULL)
        {
            supsuivant =elementsup->next;
            free(elementsup);
            elementsup = supsuivant;
        }
        polynome->first = NULL;
        polynome->last = NULL;
        polynome->taille = 0;

}

//0-Création de la fonction de menu

int menuGeneral()
{
    int choix;
    printf ("\n==================================================");
    printf ("\n*   ADDITION ET SOUSTRACTION DE DEUX POLYNOMES   *");
    printf ("\n==================================================");
    printf ("\n*             BIENVENUE AU MENU                  *");
    printf ("\n*------------------------------------------------*");
    printf ("\n*    1. Addition de deux polynômes               *");
    printf ("\n*    2. Soustraction de deux polynômes           *");
    printf ("\n*    3. Quitter le Menu                          *");
    printf ("\n==================================================");
    printf ("\nFaites votre choix : ");
    scanf ("%d", &choix);

    return choix;
}

/*==============fin polynomes.c===================*/
