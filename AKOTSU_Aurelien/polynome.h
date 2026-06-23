#ifndef POLYNOME_H
#define POLYNOME_H

//pour un usage academique,le nombre maximum de polynome gerable est limite a 100
#define MAX 100


//cration des differentes structures d'un polynome
typedef struct TValue TValue;
struct TValue 
{
    int deg;
    float coef;
};

typedef struct TMonome TMonome ;
struct TMonome
{
    TValue monome;
    TMonome* next;
};

typedef struct TPolynome TPolynome;
struct TPolynome
{
    TMonome* debut;
    TMonome* fin;
    int taille;
};



//fonction d'initialisation d'un polynome vide
void initialisation(TPolynome* polynome);

//fonction d'allocation dynamique d'un monome
void allocationMonome(TMonome** nouveau);

//fonction d'allocation dynamique d'un polynome
void allocationPolynome(TPolynome** p);

//fonction de saisie du coefficient et du degre d'un monome
void remplirChamp(TPolynome* polynome ,TMonome* nouveau);

//fonction d'ajout d'un monome dans un polynome(cas de la saisie des monomes par l'utilisateur)
void saisirMonome(TPolynome* polynome);

//fonction de saisie complete d'un polynome(par ulilisateur)
void saisirPolynome(TPolynome* polynome);

//fonction d'affichage d'un polynome
void affichagePolynome(TPolynome* polynome);


void affichageTableau(TPolynome* tabPolynome[], int pos);

//fonction de liberation de tous les monomes d'un polynome
void liberationPolynome(TPolynome* polynome);

void addMonome(TPolynome* somme,int deg , float coef);

//fonction de recuperation des positions des polynomes a utiliser
void demanderPosition(int* pos1 , int* pos2);

//fonction de recherche d'un monome a partir de son degre
TMonome* rechercherMonome(TPolynome* polynome , int deg);

//fonction verifiant si un degre existe dans un polynome
int existeDegre(TPolynome* polynome , int deg);

//fonction de creation et d'ajout d'un polynome
TPolynome* ajoutPolynome(int* pos);

//fonction de calcul de la somme de deux polynomes
TPolynome* additionPolynome(TPolynome* tabPolynome[], int pos1 , int pos2);

//fonction de calcul de la difference de deux polynomes
TPolynome* soustractionPolynome(TPolynome* tabPolynome[], int pos1 , int pos2);

//fonction de tri des monomes selon les degres decroissants
void trierPolynome(TPolynome* polynome);

//fonction d'affichage du menu principal
int menu();
#endif