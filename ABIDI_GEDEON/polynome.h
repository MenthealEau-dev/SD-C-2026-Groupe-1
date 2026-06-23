#ifndef POLYNOME_H
#define POLYNOME_H

typedef struct Tterme Tterme ;
struct Tterme
{
    int coef ;
    int exp ;
    Tterme*next;
};
typedef struct Tpolynome Tpolynome;
struct Tpolynome
{
    Tterme *first;
    Tterme *last;
    int taille;
};

void initialiser_polynome(Tpolynome*polynome);

void afficher_polynome(Tpolynome*polynome);

int inserer_dans_polynome(Tpolynome *polynome, int coef,int exp);

Tpolynome additionner_polynome(Tpolynome*P1,Tpolynome*P2);

#endif // !1
