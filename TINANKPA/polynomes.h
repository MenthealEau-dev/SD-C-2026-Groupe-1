#ifndef POLYNOMES_H
#define POLYNOMES_H

//Definition de la structure d'un monome
typedef struct Monome {
    int coefficient;
    int degre;
    struct Monome *suivant;
} Monome;

//Definition de la structure d'un polynome
typedef struct Polynome {
    Monome *tete;
} Polynome;

/*PROTOTYPES DES FONCTIONS*/

void Initialisation(Polynome *p); //Initialisation

void Ajouter_Poly(Polynome *p, int degre, int coeff);//Ajout d'un monome

void Afficher_Poly(Polynome *p);//Afficher polynome

Polynome* Additionner(Polynome *p1, Polynome *p2);//Addition des listes(a refaire)

Polynome* Soustraire(Polynome *p1, Polynome *p2);//Soustraction des listes(a refaire)

#endif
