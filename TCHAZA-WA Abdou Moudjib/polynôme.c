#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

/* ============================================
   Créer un nouveau noeud
   ============================================ */
Noeud *creer_noeud(int exposant, double coefficient) {
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    nouveau->exposant = exposant;
    nouveau->coefficient = coefficient;
    nouveau->suivant = NULL;
    return nouveau;
}

/* ============================================
   Insérer un terme dans la liste
   (triée par exposant décroissant)
   ============================================ */
Noeud *inserer_terme(Noeud *tete, int exposant, double coefficient) {
    if (coefficient == 0) return tete;

    // Cas 1 : liste vide
    if (tete == NULL) {
        return creer_noeud(exposant, coefficient);
    }

    // Cas 2 : même exposant que la tête
    if (tete->exposant == exposant) {
        tete->coefficient += coefficient;
        if (tete->coefficient == 0) {
            Noeud *temp = tete->suivant;
            free(tete);
            return temp;
        }
        return tete;
    }

    // Cas 3 : exposant plus grand que la tête
    if (exposant > tete->exposant) {
        Noeud *nouveau = creer_noeud(exposant, coefficient);
        nouveau->suivant = tete;
        return nouveau;
    }

    // Cas 4 : parcourir pour trouver la bonne position
    Noeud *courant = tete;
    while (courant->suivant != NULL && courant->suivant->exposant > exposant) {
        courant = courant->suivant;
    }

    if (courant->suivant != NULL && courant->suivant->exposant == exposant) {
        courant->suivant->coefficient += coefficient;
        if (courant->suivant->coefficient == 0) {
            Noeud *temp = courant->suivant;
            courant->suivant = temp->suivant;
            free(temp);
        }
    } else {
        Noeud *nouveau = creer_noeud(exposant, coefficient);
        nouveau->suivant = courant->suivant;
        courant->suivant = nouveau;
    }

    return tete;
}

/* ============================================
   Saisir un polynôme
   ============================================ */
Noeud *saisir_polynome() {
    int nb_termes, exposant;
    double coeff;
    Noeud *tete = NULL;

    printf("Combien de termes dans le polynôme ? ");
    scanf("%d", &nb_termes);

    for (int i = 0; i < nb_termes; i++) {
        printf("  Terme %d :\n", i + 1);
        printf("    Exposant    : ");
        scanf("%d", &exposant);
        printf("    Coefficient : ");
        scanf("%lf", &coeff);
        tete = inserer_terme(tete, exposant, coeff);
    }
    return tete;
}

/* ============================================
   Afficher un polynôme
   ============================================ */
void afficher_polynome(Noeud *tete) {
    if (tete == NULL) {
        printf("0\n");
        return;
    }

    Noeud *courant = tete;
    int premier = 1;

    while (courant != NULL) {
        double c = courant->coefficient;
        int e    = courant->exposant;

        if (!premier && c > 0) printf(" + ");
        else if (c < 0)        printf(" - ");

        double val = (c < 0) ? -c : c;

        if (e == 0) {
            printf("%.4g", val);
        } else if (e == 1) {
            if (val != 1) printf("%.4g", val);
            printf("x");
        } else {
            if (val != 1) printf("%.4g", val);
            printf("x^%d", e);
        }

        premier = 0;
        courant = courant->suivant;
    }
    printf("\n");
}

/* ============================================
   Libérer la mémoire d'un polynôme
   ============================================ */
void liberer_polynome(Noeud *tete) {
    Noeud *courant = tete;
    while (courant != NULL) {
        Noeud *temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}

/* ============================================
   Addition de deux polynômes
   ============================================ */
Noeud *additionner(Noeud *p1, Noeud *p2) {
    Noeud *resultat = NULL;

    Noeud *courant = p1;
    while (courant != NULL) {
        resultat = inserer_terme(resultat, courant->exposant, courant->coefficient);
        courant = courant->suivant;
    }

    courant = p2;
    while (courant != NULL) {
        resultat = inserer_terme(resultat, courant->exposant, courant->coefficient);
        courant = courant->suivant;
    }

    return resultat;
}

/* ============================================
   Soustraction de deux polynômes (p1 - p2)
   ============================================ */
Noeud *soustraire(Noeud *p1, Noeud *p2) {
    Noeud *resultat = NULL;

    Noeud *courant = p1;
    while (courant != NULL) {
        resultat = inserer_terme(resultat, courant->exposant, courant->coefficient);
        courant = courant->suivant;
    }

    courant = p2;
    while (courant != NULL) {
        resultat = inserer_terme(resultat, courant->exposant, -(courant->coefficient));
        courant = courant->suivant;
    }

    return resultat;
}
