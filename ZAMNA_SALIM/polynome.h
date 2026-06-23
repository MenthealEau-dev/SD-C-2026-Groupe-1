#ifndef POLYNOME_H_INCLUDED
#define POLYNOME_H_INCLUDED


//définition du monome
typedef struct Tmonome Tmonome;

struct Tmonome
{
    int coeff;
    int degre;
};


//définition du type element
typedef struct Telement Telement;

struct Telement
{
    Tmonome monome;
    struct Telement *suivant;
};


//définition du type polynome
typedef struct Tpolynome Tpolynome;

struct Tpolynome
{
    Telement *debut;
    Telement *fin;
    int taille;
};


//initialisation du polynome
void initialise_polynome (Tpolynome *polynome);


//inserez dans polynome vide
int inserer_dans_polynome_vide (Tpolynome *polynome, int coeff);


//inserez a la fin du polynome
int inserer_fin_du_polynome (Tpolynome *polynome, int coeff);

//saisir du polynome
int saisi_dans_polynome (Tpolynome *polynome, int coeff);


//saisi des informations
int entrez_informations (Tpolynome *polynome1, Tpolynome *polynome2);


//afficher polynome
void afficher_polynome (Tpolynome *polynome);


//liberer memoire
void liberer_polynome(Tpolynome *polynome);


//afficher le menu
int menu();


//addition de deux polynomes
Tpolynome *addition_de_polynomes(Tpolynome *polynome1, Tpolynome *polynome2);


//soustraction de deux polynomes
Tpolynome *soustraction_de_polynomes(Tpolynome *polynome1, Tpolynome *polynome2);


//
#endif // POLYNOME_H_INCLUDED
