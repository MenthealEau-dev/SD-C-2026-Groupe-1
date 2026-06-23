#ifndef POLYNOME_H
#define POLYNOME_H



typedef struct TMonome TMonome;

struct TMonome
{
    int coef;
    int degre;
};


typedef struct TMaillon TMaillon;

struct TMaillon
{
    TMonome Monome;
    TMaillon *next;
};

typedef struct TPolynome TPolynome;

struct TPolynome
{
    TMaillon *debut;
    TMaillon *fin;
    int taille;
};


// Création et initialisation de ma liste (Polynôme )


TPolynome* creation_initialisation();

// Fonction de saisie des polynômes

void saisie_informations (TPolynome *Polynome, int cpt);

// Fonction de tri

TPolynome* trier_Liste (TPolynome *Polynome);

// Fonction d'affichage des polynômes

void afficher (TPolynome *Polynome, int cpt);

//Fonction d'insertion dans une liste (polynôme) vide

int inserer_Liste_Vide (TPolynome *Polynome, int coef, int degre);

// Fonction en fin de liste

int inserer_Fin_Liste(TPolynome *Polynome, int coef, int degre);

// Fonction d'insertion générale

int inserer_Liste(TPolynome *Polynome, int coef, int degre);

// Fonction d'addition de polynômes

TPolynome* additionner_Polynome(TPolynome *Polynome1, TPolynome *Polynome2);

// Fonction de soustraction des polynômes

TPolynome* soustraire_Polynome(TPolynome *Polynome1, TPolynome *Polynome2);

// Fonction de menu

int menuComplet ();

// Fonction de destruction

void detruire (TPolynome *Polynome);


#endif // POLYNOME_H
