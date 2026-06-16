#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

/* =========== liste.c=================*/


/* Initialisation de la liste */

void initialiser_liste(TListe *liste)
{
    liste->first = NULL;
    liste->last = NULL;
    liste->taille = 0;
}

/* 1-Création de la fonction d'insertion dans une liste vide */

int inserer_dans_liste_vide(TListe *liste, int valeur)
{
    TElement *nouveau;
    if((nouveau = (TElement*)malloc(sizeof(TElement))) == NULL)
        exit(1);
    nouveau->value = valeur;
    nouveau->next = liste->first;
    liste->first = liste->last = nouveau;
    liste->taille++;

    return 0;
}
/* 2-Création de la fonction d'insertion en tête de liste */

int inserer_en_tete_de_liste(TListe *liste , int valeur)
{
    TElement *nouveau;
    if((nouveau = (TElement*)malloc(sizeof(TElement))) == NULL)
        exit(1);
    nouveau->value = valeur;
    nouveau->next = liste->first;
    liste->first = nouveau;
    liste->taille++;

    return 0;

}

/* 3-Création de la fonction d'insertion en fin de liste */

int inserer_en_queue_de_liste(TListe *liste, int valeur)
{
    TElement *nouveau;
    if((nouveau = (TElement*)malloc(sizeof(TElement))) == NULL)
        exit(1);
    nouveau->value = valeur;
    nouveau->next = NULL;
    liste->last->next = nouveau;
    liste->last = nouveau;
    liste->taille++;

    return 0;
}

/*4-Création de la fonction d'insertion à une position donnée */

int inserer_en_position(TListe *liste, int valeur, int position)
{
    int choix;
    if(liste->taille < 2)
    {
       printf("\nPour ce faire, nous allons procéder à l'insertion en fin de liste");
       printf("\n\nVoulez vous procéder à cette insertion? Si oui taper 1 sinon taper 0 : ");
       scanf("%d",&choix);
       if(choix == 1)
        inserer_en_queue_de_liste(liste,valeur);
    }
    else
    {
        if(position == liste->taille)
        {
            printf("\nVeuillez utiliser le menu d'insertion en fin de liste (Menu 3)! Merci ");
            printf("\n\nVoulez vous procéder à cette insertion? Si oui tapez 1,sinon tapez 0 : ");
            scanf("%d",&choix);
            if(choix == 1)
                inserer_en_queue_de_liste(liste,valeur);
        }
        else
        {
            TElement *courant;
            if((courant = (TElement*)malloc(sizeof(TElement))) == NULL)
                exit(1);
            courant = liste->first;
            for(int cpt = 0; cpt < position - 1; ++cpt)
            {
                courant = courant->next;
            }
            TElement *nouveau;
            if((nouveau = (TElement*)malloc(sizeof(TElement))) == NULL)
                exit(1);
            nouveau->value = valeur;
            nouveau->next = courant->next;
            courant->next = nouveau;
            liste->taille++;
        }
    }
    return 0;
}

/* 5-Création de la fonction de suppression en début de liste */

int supprimer_en_debut_de_liste(TListe *liste)
{
    if(liste->taille == 0)
        exit(1);
    TElement *elementsup;
    if((elementsup = (TElement*)malloc(sizeof(TElement))) == NULL)
        exit(1);
    elementsup = liste->first;
    liste->first = liste->first->next;
    if(liste->taille == 1)
        liste->last = NULL;
    free(elementsup);
    liste->taille--;

    return 0;
}

/* 6-création de la fonction de suppression à une position donnée */

int supprimer_dans_liste(TListe *liste, int position)
{
    int choix;
    if(liste->taille <= 1)
    {
        if(position == 1)
        {
            printf("\nAucun élément après la position 1");
            printf("\n\nVotre liste ne contient qu'un seul élément.");
            printf("\n\nEssayez vous de détruire la liste?");
            printf("\n\nSi oui tapez 1, sinon tapez 0 : ");
            scanf("%d",&choix);
            if(choix == 1)
                detruire_liste(liste);
        }
    }
    else
    {
        if(position == liste->taille)
            printf("\nAucun élément n'existe après la position %d\n", liste->taille);
        else{
            TElement *courant;
            if((courant = (TElement*)malloc(sizeof(TElement))) == NULL)
                exit(1);
            courant = liste->first;
            for(int cpt = 0; cpt < position - 1; cpt++)
            {
                courant = courant->next;
            }
            TElement *elementsup;
            if((elementsup = (TElement*)malloc(sizeof(TElement))) == NULL)
                exit(1);
            elementsup = courant->next;
            courant->next =courant->next->next;
            free(elementsup);
            liste->taille--;
        }
    }
    return 0;

}

/* 7-Création de la fonction pour détruire la liste */

void detruire_liste (TListe * liste)
{
    printf("\n\nDestruction en cours....");
    while (liste->taille > 0)
        supprimer_en_debut_de_liste(liste);
    printf("\n\nVotre liste a bien été supprimée");
}

/* Création de la fonction d'affichage de la liste */

void afficher (TListe * liste)
{
    if(liste->taille != 0)
    {
        int cpt = 0;
        TElement *balayeur;
        balayeur = liste->first;
        printf("\nCONTENU DE LA LISTE\n");
        printf("\n%d elements:\t deb = %d \t\t fin = %d\n",
        liste->taille,
        liste->first->value,
        liste->last->value);

        printf("\n|POSITION\t|ADRESSE\t\t|DONNEE\t\t|SUIVANT");
        printf("\n------------------------------------------------------------------");
        while (balayeur != NULL)
        {
            printf ("\n|%d\t\t|%p\t\t|%d\t\t|%p|",
                     ++cpt,
                     balayeur,
                     balayeur->value,
                     balayeur->next);
            printf("\n------------------------------------------------------------------");
            balayeur = balayeur->next;
        }
        printf("\n");
        printf ("\n%d elements:\tADR_deb = %p  \t ADR_fin = %p\n",
        liste->taille,
        liste->first,
        liste->last);
    }
}




/* Création de la fonction de menu */

int menu()
{
    int choix;
    printf("\n");
    printf ("\n==================================================");
    printf ("\n*          GESTION DE LISTE D'ENTIERS            *");
    printf ("\n==================================================");
    printf ("\n*             BIENVENUE AU MENU                  *");
    printf ("\n*------------------------------------------------*");
    printf ("\n*    1. Ajout dans une liste vide                *");
    printf ("\n*    2. Ajout au début de la liste               *");
    printf ("\n*    3. Ajout à la fin de la liste               *");
    printf ("\n*    4. Ajout après une position spécifiée       *");
    printf ("\n*    5. Suppression au début de la liste         *");
    printf ("\n*    6. Suppression après une position spécifiée *");
    printf ("\n*    7. Destruction de la liste                  *");
    printf ("\n*    8. Quitter le Menu                          *");
    printf ("\n==================================================");
    printf ("\nFaites votre choix : ");
    scanf ("%d", &choix);

    return choix;

}

/* Création de la fonction de saisie d'information */

void saisir_informations(int *valeur)
{
    printf("\nEntrer un élément : ");
    scanf("%d", valeur);
}

/*============== fin liste.c ==================*/
