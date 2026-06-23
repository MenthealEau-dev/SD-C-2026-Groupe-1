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

/*==============fin polynomes.h==================*/

#endif // POLYNOMES_H
