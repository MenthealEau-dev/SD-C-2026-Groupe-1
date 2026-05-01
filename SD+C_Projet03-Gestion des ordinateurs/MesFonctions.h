
#include "Ordinateur.h"
#define TAB_MAX 300

// prototype 1 de la fonction de saisie des informations de tous les oridinatateurs

Tordinateur *saisir_listeOrdinateur(int nbreOrdi);

// prototype  de la fonction de saisie des informations d'un oridinataur

Tordinateur* ajouter_ordinateur(int cpt);

// prototype 2 de la fonction de suppression d'un ordinateur

void supprimer_Ordinateur(Tordinateur **listeOrdinateur, int nbreOrdi);

// prototype 3 de la fonction d'affichage des informations générales de tous les oridinateurs

void informations_desOrdinateurs( Tordinateur **listeOrdinateur, int nbreOrdi);

// prototype 4 de la fonction d'affichage des informations d'un ordinateur

void afficher_details_d_un_ordinateur (Tordinateur ** listeOrdinateur, int nbreOrdi);

// prototype 8 de la fonction de calcul du prix total des ordinateurs

void calculer_sommePrix(Tordinateur **listeOrdinateur, int nbreOrdi);
