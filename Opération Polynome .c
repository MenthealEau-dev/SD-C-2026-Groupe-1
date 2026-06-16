#include <stdio.h>
#include <stdlib.h>

typedef struct TMonome TMonome;
struct TMonome
{
    int expo;
    int coef;
    struct TMonome *suivant;
};

typedef struct TPolynome TPolynome;
struct TPolynome 
{
    TMonome *donnee;
};

TPolynome* allocation() 
{
    TPolynome *poly = (TPolynome*) malloc(sizeof(TPolynome));
    if (poly == NULL) {
        printf("Allocation echouee\n");
        exit(1);
    }
    poly->donnee = NULL;
    return poly;
}

void ajouter_monome(TPolynome *poly, int coef, int expo) 
{
    if (coef == 0) return;

    TMonome *actuel = poly->donnee;
    TMonome *precedent = NULL;

    while (actuel != NULL && actuel->expo > expo) 
    {
        precedent = actuel;
        actuel = actuel->suivant;
    }

    if (actuel != NULL && actuel->expo == expo) 
    {
        actuel->coef += coef;
        if (actuel->coef == 0) 
        {
            if (precedent == NULL) poly->donnee = actuel->suivant;
            else precedent->suivant = actuel->suivant;
            free(actuel);
        }
        return;
    }

    TMonome *nouveau = (TMonome*) malloc(sizeof(TMonome));
    if (nouveau == NULL) exit(1);
    nouveau->coef = coef;
    nouveau->expo = expo;
    nouveau->suivant = actuel;

    if (precedent == NULL) poly->donnee = nouveau;
    else precedent->suivant = nouveau;
}

void saisiePolynome(TPolynome *poly, int indice) 
{
    int coef, expo;
    printf("\n--- Saisie du Polynome %d ---\n", indice);
    printf("(Pour arreter, entrez un exposant negatif)\n");

    while (1) 
    {
        printf("Entrer l'exposant : ");
        if (scanf("%d", &expo) != 1) return;
        if (expo < 0) break;

        printf("Entrer le coefficient : ");
        if (scanf("%d", &coef) != 1) return;

        ajouter_monome(poly, coef, expo);
    }
}

TPolynome* sommer_polynomes(TPolynome* t_poly[], int nb_poly) 
{
    TPolynome *somme = allocation();
    for (int i = 0; i < nb_poly; i++) 
    {
        TMonome *courant = t_poly[i]->donnee;
        while (courant != NULL) 
        {
            ajouter_monome(somme, courant->coef, courant->expo);
            courant = courant->suivant;
        }
    }
    return somme;
}

TPolynome* soustraire_polynomes(TPolynome* t_poly[], int nb_poly) 
{
    TPolynome *difference = allocation();
    
    if (nb_poly > 0) 
    {
        TMonome *courant = t_poly[0]->donnee;
        while (courant != NULL) 
        {
            ajouter_monome(difference, courant->coef, courant->expo);
            courant = courant->suivant;
        }
    }

    for (int i = 1; i < nb_poly; i++) 
    {
        TMonome *courant = t_poly[i]->donnee;
        while (courant != NULL) 
        {
            ajouter_monome(difference, -(courant->coef), courant->expo);
            courant = courant->suivant;
        }
    }
    return difference;
}

void afficher_polynome(TPolynome *poly) 
{
    if (poly == NULL || poly->donnee == NULL) 
    {
        printf("0\n");
        return;
    }

    TMonome *courant = poly->donnee;
    int premier = 1;

    while (courant != NULL) 
    {
        int c = courant->coef;
        int e = courant->expo;

        if (!premier && c > 0) printf("+ ");
        if (c < 0) 
        {
            printf("- ");
            c = -c;
        }

        if (e == 0) printf("%d ", c);
        else if (e == 1) 
        {
            if (c == 1) printf("x ");
            else printf("%dx ", c);
        } else 
        {
            if (c == 1) printf("x^%d ", e);
            else printf("%dx^%d ", c, e);
        }

        premier = 0;
        courant = courant->suivant;
    }
    printf("\n");
}

void enregistrer_polynome_fichier(TPolynome *poly, const char *nom_fichier) 
{
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) 
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    if (poly == NULL || poly->donnee == NULL) 
    {
        fprintf(fichier, "0\n");
        fclose(fichier);
        return;
    }

    TMonome *courant = poly->donnee;
    int premier = 1;

    while (courant != NULL) 
    {
        int c = courant->coef;
        int e = courant->expo;

        if (!premier && c > 0) fprintf(fichier, "+ ");
        if (c < 0) 
        {
            fprintf(fichier, "- ");
            c = -c;
        }

        if (e == 0) fprintf(fichier, "%d ", c);
        else if (e == 1) 
        {
            if (c == 1) fprintf(fichier, "x ");
            else fprintf(fichier, "%dx ", c);
        } else 
        {
            if (c == 1) fprintf(fichier, "x^%d ", e);
            else fprintf(fichier, "%dx^%d ", c, e);
        }

        premier = 0;
        courant = courant->suivant;
    }
    fprintf(fichier, "\n");
    fclose(fichier);
    printf("\nResultat enregistre avec succes dans le fichier '%s'.\n", nom_fichier);
}

void liberer_polynome(TPolynome *poly) 
{
    if (poly == NULL) return;
    TMonome *actuel = poly->donnee;
    while (actuel != NULL) 
    {
        TMonome *temp = actuel;
        actuel = actuel->suivant;
        free(temp);
    }
    free(poly);
}

int main() 
{
    int n, choix;
    TPolynome *resultat = NULL;

    printf("=== MENU OPERATION POLYNOMES ===\n");
    printf("1. Additionner des polynomes\n");
    printf("2. Soustraire des polynomes \n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1 || (choix != 1 && choix != 2)) 
    {
        printf("Choix invalide.\n");
        return 1;
    }

    printf("Combien de polynomes voulez-vous manipuler ? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    TPolynome **tableau_polynomes = (TPolynome**) malloc(n * sizeof(TPolynome*));

    for (int i = 0; i < n; i++) 
    {
        tableau_polynomes[i] = allocation();
        saisiePolynome(tableau_polynomes[i], i + 1);
    }

    printf("\n==================================\n");
    for (int i = 0; i < n; i++) 
    {
        printf("P%d : ", i + 1);
        afficher_polynome(tableau_polynomes[i]);
    }
    printf("----------------------------------\n");

    if (choix == 1) 
    {
        resultat = sommer_polynomes(tableau_polynomes, n);
        printf("Somme finale : ");
    } else 
    {
        resultat = soustraire_polynomes(tableau_polynomes, n);
        printf("Difference finale : ");
    }
    
    afficher_polynome(resultat);
    printf("==================================\n");

    enregistrer_polynome_fichier(resultat, "resultat.txt");

    for (int i = 0; i < n; i++) 
    {
        liberer_polynome(tableau_polynomes[i]);
    }
    free(tableau_polynomes);
    liberer_polynome(resultat);

    return 0;
}
    