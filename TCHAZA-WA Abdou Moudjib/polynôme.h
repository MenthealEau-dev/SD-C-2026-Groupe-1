#ifndef POLYNOME_H
#define POLYNOME_H

/* ============================================
   Structure d'un noeud de la liste chaînée
   ============================================ */
typedef struct Noeud {
    int exposant;
    double coefficient;
    struct Noeud *suivant;
} Noeud;

/* ============================================
   Déclarations des fonctions
   ============================================ */
Noeud *creer_noeud(int exposant, double coefficient);
Noeud *inserer_terme(Noeud *tete, int exposant, double coefficient);
Noeud *saisir_polynome();
void   afficher_polynome(Noeud *tete);
void   liberer_polynome(Noeud *tete);
Noeud *additionner(Noeud *p1, Noeud *p2);
Noeud *soustraire(Noeud *p1, Noeud *p2);

#endif
