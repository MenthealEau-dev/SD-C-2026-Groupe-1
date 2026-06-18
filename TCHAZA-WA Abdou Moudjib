#include <stdio.h>
#include <stdlib.h>
#include "polynome.h"

/* ============================================
   Programme principal
   ============================================ */
int main() {
    Noeud *poly1    = NULL;
    Noeud *poly2    = NULL;
    Noeud *resultat = NULL;
    int choix;

    printf("=== Addition et Soustraction de Polynômes ===\n\n");

    printf("--- Polynôme 1 ---\n");
    poly1 = saisir_polynome();
    printf("Polynôme 1 : ");
    afficher_polynome(poly1);

    printf("\n--- Polynôme 2 ---\n");
    poly2 = saisir_polynome();
    printf("Polynôme 2 : ");
    afficher_polynome(poly2);

    printf("\nQuelle opération voulez-vous effectuer ?\n");
    printf("  1. Addition      (P1 + P2)\n");
    printf("  2. Soustraction  (P1 - P2)\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    printf("\n");

    if (choix == 1) {
        resultat = additionner(poly1, poly2);
        printf("Résultat (P1 + P2) : ");
        afficher_polynome(resultat);
    } else if (choix == 2) {
        resultat = soustraire(poly1, poly2);
        printf("Résultat (P1 - P2) : ");
        afficher_polynome(resultat);
    } else {
        printf("Choix invalide.\n");
    }

    liberer_polynome(poly1);
    liberer_polynome(poly2);
    liberer_polynome(resultat);

    return 0;
}
