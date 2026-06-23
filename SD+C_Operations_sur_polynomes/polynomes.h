#ifndef POLYNOMES_H
#define POLYNOMES_H

/*================polynomes.h==================*/

/*Création et définition de la structure TMonome*/

typedef struct TMonome TMonome;
struct TMonome
{
    int coef;
    int degre;
};

/*Création et définition de la structure TCellule*/

typedef struct TCellule TCellule;
struct TCellule
{
    TMonome monome;
    TCellule *next;
};

/*Création et définition de la structure TPolynome*/

typedef struct TPolynome TPolynome;
struct TPolynome
{
    TCellule *first;
    TCellule *last;
    int taille;
};


/*Prototypes des fonctions sur l'opérations des polynomes*/

// 1-Prototype de la fonction de création et d'initialisation d'un polynome

TPolynome *creer_initialiser_poly();

// 2-1-1-Prototype de la fonction d'insertion dans une liste vide

int inserer_dans_liste_vide(TPolynome *polynome, int coef, int degre);

// 2-1-2-Prototype de la fonction d'insertion en fin de liste

int inserer_en_queue_de_liste(TPolynome *polynome, int coef, int degre);

//2-1-Prototype de la fonction d'insertion dans une liste

int inserer_dans_liste(TPolynome *polynome, int coef, int degre);

// 2-Prototype de la fonction de saisie des informations d'un polynome

void saisir_infoPolynome(TPolynome *polynome, int indice);

/*==============fin polynomes.h==================*/

#endif // POLYNOMES_H
