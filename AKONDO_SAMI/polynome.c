#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynome.h"

// Fonction de création et d'initialisation

TPolynome* creation_initialisation()
{
    TPolynome *Polynome = (TPolynome*)malloc(sizeof(TPolynome));
    if (Polynome == NULL)
    {
        printf("Allocation échouée !!\n");
        exit(1);
    }
    Polynome->debut = NULL;
    Polynome->fin = NULL;
    Polynome->taille = 0;
    return Polynome;
}

// Fonction d'insertion dans une liste vide

int inserer_Liste_Vide (TPolynome *Polynome, int coef, int degre)
{
    TMaillon *nouveauMonome;
    if ((nouveauMonome = (TMaillon*)malloc(sizeof(TMaillon))) == NULL)
    {
        printf("Allocation échouée !! ");
        exit(1);
    }
    nouveauMonome ->Monome.coef = coef;
    nouveauMonome ->Monome.degre = degre;
    nouveauMonome -> next = Polynome -> debut;
    Polynome -> debut = nouveauMonome;
    Polynome -> fin = nouveauMonome;
    Polynome -> taille ++;
    return 0;
}

// Fonction d'insertion en fin de liste

int inserer_Fin_Liste(TPolynome *Polynome, int coef, int degre)
{
    TMaillon *nouveauMonome;
    if ((nouveauMonome = (TMaillon*)malloc(sizeof(TMaillon))) == NULL)
    {
        printf("Allocation échouée !! ");
        exit(1);
    }
    nouveauMonome ->Monome.coef = coef;
    nouveauMonome ->Monome.degre = degre;
    nouveauMonome -> next = NULL;
    Polynome -> fin -> next = nouveauMonome;
    Polynome -> fin = nouveauMonome;
    Polynome -> taille ++;
    return 0;
}

// Fonction d'insertion générale

int inserer_Liste(TPolynome *Polynome, int coeffi, int expo)
{
    if (coeffi != 0)
    {
        if (Polynome -> taille == 0)
        {
            inserer_Liste_Vide (Polynome, coeffi, expo);

        }else{
            inserer_Fin_Liste(Polynome, coeffi, expo);

        }
    }
    return 0;
}

// Fonction de saisie des informations

void saisie_informations (TPolynome *Polynome, int cpt)
{

    int choix = 1;
    printf("Commencez la saisie des monômes de votre polynôme %d \n", cpt);
    printf("1 pour oui et 0 pour non \n");
    while (choix == 1)
    {
            int expo;
            int coeffi;
            printf("Entrez le coefficient de votre monome\n");
            scanf("%d", &coeffi);
            printf("Entrez le degre de votre monome \n");
            scanf("%d", &expo);
            inserer_Liste(Polynome, coeffi, expo);
            cpt ++;

            printf("Voulez vous ajouter d'autres monômes ??? ");
            scanf("%d", &choix);
    }
}

TPolynome* trier_Liste (TPolynome *Polynome)
{
    if (Polynome == NULL || Polynome->taille <= 1)
    {
        return Polynome;
    }

    TMaillon *nouveauDebut = NULL;
    TMaillon *nouveauFin = NULL;
    TMaillon *current = Polynome->debut;

    while (current != NULL)
    {
        TMaillon *next = current->next;
        next = current->next;
        current->next = NULL;

        if (nouveauDebut == NULL || current->Monome.degre > nouveauDebut->Monome.degre)
        {
            current->next = nouveauDebut;
            nouveauDebut = current;
            if (nouveauFin == NULL)
            {
                nouveauFin = current;
            }
        }
        else
        {
            TMaillon *temp = nouveauDebut;
            while (temp->next != NULL && temp->next->Monome.degre > current->Monome.degre)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;

            if (current->next == NULL)
            {
                nouveauFin = current;
            }
        }
        current = next;
    }
    Polynome->debut = nouveauDebut;
    Polynome->fin = nouveauFin;

    return Polynome;
}


void afficher (TPolynome *Polynome, int cpt)
{
    if (Polynome == NULL || Polynome -> debut == NULL){

        printf("\n Polynome vide \n");
        return ;
    }

    int first = 1;
    TMaillon *current;
    current = Polynome -> debut;

    while(current != NULL)
    {
        if (current -> Monome.coef != 0){

            if(!first && current ->  Monome.coef > 0 )
            {
                printf("+");
            }
            if (current -> Monome.degre == 0)
            {
                printf("%d", current -> Monome.coef);

            }else if (current -> Monome.degre == 1){

                if(current -> Monome.coef == 1)
                    printf("x");
                else if (current -> Monome.coef == -1)
                    printf("-x");
                else
                    printf("%dx", current -> Monome.coef);

            }else{

                if(current -> Monome.coef == 1)
                    printf("x^%d", current -> Monome.degre);
                else if (current -> Monome.coef == -1)
                    printf("-x^%d", current -> Monome.degre);
                else
                    printf("%dx^%d", current -> Monome.coef, current -> Monome.degre);
                first = 0;
            }
            current = current -> next;
        }
    }
    printf("\n");
}


TPolynome* additionner_Polynome(TPolynome *Polynome1, TPolynome *Polynome2)
{
    int somDegre;
    int somCoef;
    TPolynome *tmpTpr;
    if ((tmpTpr = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
    {
        printf("Allocation échouée !!");
        exit(1);
    }
    tmpTpr->debut = tmpTpr->fin = NULL;
    tmpTpr->taille = 0;
    TMaillon *current1;
    TMaillon *current2;
    current1 = Polynome1->debut;
    current2 = Polynome2->debut;

    while(current1 != NULL && current2 != NULL)
    {
        if(current1 -> Monome.degre == current2 -> Monome.degre)
        {
            somCoef = (current1 -> Monome.coef) + (current2 -> Monome.coef);
            somDegre = current1 -> Monome.degre;
            inserer_Liste(tmpTpr, somCoef, somDegre);

            if (somCoef != 0){
                inserer_Liste(tmpTpr, somCoef, somDegre);
            }
            current1 = current1 -> next;
            current2 = current2 -> next;

        }else if(current1->Monome.degre > current2->Monome.degre){
            inserer_Liste(tmpTpr, current1->Monome.coef, current1->Monome.degre);
            current1 = current1->next;

        }else{
            inserer_Liste(tmpTpr, current2->Monome.coef, current2->Monome.degre);
            current2 = current2->next;
        }
    }


    if(current2 == NULL)
    {
        while(current1 != NULL)
        {
            inserer_Fin_Liste(tmpTpr, current1 -> Monome.coef, current1 -> Monome.degre);
            current1 = current1 ->next;
        }
    }

    if(current1 == NULL)
    {
        while(current2 != NULL)
        {
            inserer_Fin_Liste(tmpTpr, current2 -> Monome.coef, current2 -> Monome.degre);
            current2 = current2 -> next;
        }
    }
    return tmpTpr;
}

TPolynome* soustraire_Polynome(TPolynome *Polynome1, TPolynome *Polynome2)
{
    int somDegre;
    int somCoef;
    TPolynome *tmpTpr;
    if ((tmpTpr = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
    {
        printf("Allocation échouée !!");
        exit(1);
    }
    tmpTpr->debut = tmpTpr->fin = NULL;
    tmpTpr->taille = 0;
    TMaillon *current1;
    TMaillon *current2;
    current1 = Polynome1->debut;
    current2 = Polynome2->debut;

    while(current1 != NULL && current2 != NULL)
    {
        if(current1 -> Monome.degre == current2 -> Monome.degre)
        {
            somCoef = (current1 -> Monome.coef) - (current2 -> Monome.coef);
            somDegre = current1 -> Monome.degre;
            inserer_Liste(tmpTpr, somCoef, somDegre);

            if (somCoef != 0){
                inserer_Liste(tmpTpr, somCoef, somDegre);
            }
            current1 = current1 -> next;
            current2 = current2 -> next;

        }else if(current1->Monome.degre > current2->Monome.degre){
            inserer_Liste(tmpTpr, current1->Monome.coef, current1->Monome.degre);
            current1 = current1->next;

        }else{
            inserer_Liste(tmpTpr, current2->Monome.coef, current2->Monome.degre);
            current2 = current2->next;
        }
    }


    if(current2 == NULL)
    {
        while(current1 != NULL)
        {
            inserer_Fin_Liste(tmpTpr, current1 -> Monome.coef, current1 -> Monome.degre);
            current1 = current1 ->next;
        }
    }

    if(current1 == NULL)
    {
        while(current2 != NULL)
        {
            inserer_Liste(tmpTpr, -(current2 -> Monome.coef), -(current2 -> Monome.degre));
            current2 = current2 -> next;
        }
    }
    return tmpTpr;
}

void detruire (TPolynome *Polynome)
{
    if (Polynome == NULL)
    {
        return;
    }

    TMaillon *current = Polynome->debut;
    TMaillon *suivant = NULL;

    while (current != NULL)
    {
        suivant = current->next;
        free(current);
        current = suivant;
    }
    free(Polynome);
    Polynome = NULL;
    printf("Mémoire du polynôme libérée avec succès.\n");
}

int menuComplet()
{
    int menu;
    printf("\n****************************************************\n");
    printf("\n*                                                  *\n");
    printf("\n*    1. Affichage de polynômes                     *\n");
    printf("\n*    2. Addition de polynômes                      *\n");
    printf("\n*    3. Soustraction de polynômes                  *\n");
    printf("\n*    4. Quitter                                    *\n");
    printf("\n*                                                  *\n");
    printf("\n****************************************************\n");
    printf("Faites votre choix :\n");
    scanf("%d", &menu);
    return menu;
}

