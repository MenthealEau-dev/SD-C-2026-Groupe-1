#ifndef LISTE_H
#define LISTE_H

/*========== liste.h=============*/


typedef struct TElement TElement;
struct TElement
{
    int value;
    TElement *next;
};

typedef struct TListe TListe;
struct TListe
{
    TElement *first;
    TElement *last;
    int taille;
};
/* Prototype de la fonction d'initialisation de la liste */

void initialiser_liste(TListe *liste);

/* 1-Prototype de la fonction d'insertion dans une liste vide */

int inserer_dans_liste_vide(TListe *liste, int valeur);

/* 2-Prototype de la fonction d'insertion en tête de liste */

int inserer_en_tete_de_liste(TListe *liste , int valeur);

/* 3-Protoype de la fonction d'insertion en fin de liste */

int inserer_en_queue_de_liste(TListe *liste, int valeur);

/* 4-Prototype de la fonction d'insertion à une position spécifique */

int inserer_en_position(TListe *liste, int valeur, int position);

/* 5-Prototype de la fonction de suppression au début de la liste */

int supprimer_en_debut_de_liste(TListe *liste);

/* 6-Prototype de la fonction de suppression à une position donnée */

int supprimer_dans_liste(TListe *liste, int position);

/* 7-Prototype de la fonction pour detruire la liste */

void detruire_liste (TListe * liste);

/* Prototype de la fonction d'affichage de la liste */

void afficher (TListe * liste);

/* Prototype de la fonction de menu */

int menu();

/* Prototype de la fonction de saisie d'informations */

void saisir_informations(int *valeur);


/*=======fin liste.h============*/

#endif // LISTE_H
