#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "polynome.h"   // ton fichier d'en-tête où sont déclarées les fonctions et structures

int main()
{
     setlocale(LC_ALL,"");
    Tpolynome P1, P2, Somme;
    initialiser_polynome(&P1);
    initialiser_polynome(&P2);

    int n, coef, exp;

    // Saisie du premier polynôme
    printf("Combien de termes contient votre 1er polynome ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Terme %d - Coefficient : ", i+1);
        scanf("%d", &coef);
        printf("Terme %d - Exposant : ", i+1);
        scanf("%d", &exp);
        inserer_dans_polynome(&P1, coef, exp);
    }

    // Saisie du deuxième polynôme
    printf("\nCombien de termes contient votre 2eme polynome ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Terme %d - Coefficient : ", i+1);
        scanf("%d", &coef);
        printf("Terme %d - Exposant : ", i+1);
        scanf("%d", &exp);
        inserer_dans_polynome(&P2, coef, exp);
    }

    // Affichage des polynômes
    printf("\nP1 = "); afficher_polynome(&P1);
    printf("P2 = "); afficher_polynome(&P2);

    // Calcul et affichage de la somme
    Somme = additionner_polynome(&P1, &P2);
    printf("\nP1 + P2 = "); afficher_polynome(&Somme);

    return 0;
}
