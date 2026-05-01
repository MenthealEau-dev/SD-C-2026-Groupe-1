#include <stdio.h>
#include <stdlib.h>
#include "Ordinateur.h"
#include "Mesfonctions.h"
#include "FonctionsTries.h"
#include <locale.h>

#define TAB_MAX 300

// Fonction 1 de saisie des informations de tous les ordinateurs
Tordinateur *saisir_listeOrdinateur(int nbreOrdi)
{
    Tordinateur **listeOrdinateur;
    Tordinateur **tmpPtr;
    int cpt = 0;
    printf("\n Entrer le nombre d'ordinateurs : ");
    scanf("%d", &nbreOrdi);
    while (nbreOrdi > TAB_MAX || nbreOrdi <= 0)
    {
        printf("\n Le nombre d'ordinateur est supérieur au nombre maximal permis, réessayez!");
        scanf("%d", &nbreOrdi);
    }
    listeOrdinateur = (Tordinateur**)malloc(nbreOrdi*sizeof (Tordinateur*));
    if (listeOrdinateur == NULL)
    {
        printf("Allocation échoué");
        exit (1);
    }
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        (*tmpPtr) = ajouter_ordinateur(cpt);
        cpt++;
    }

    return listeOrdinateur;
}


 // Création de la fonction de saisie des informations
Tordinateur *ajouter_ordinateur(int cpt)
{
    Tordinateur *nouvelOrdinateur;
    nouvelOrdinateur = (Tordinateur*)malloc(sizeof(Tordinateur));
    if (nouvelOrdinateur == NULL)
    {
        printf("\n Allocation échoué");
        exit (1);
    }
    printf("\n --------Information de l'ordinateur %d----------", cpt+1);
    printf("\n Entrer le numéro de la carte: ");
    scanf("%d", &nouvelOrdinateur->numCarte);
    printf("\n Entrer la spécialité du détenteur: ");
    scanf("%s", nouvelOrdinateur->specialite);
    printf("\n Entrer le numéro de série: " );
    scanf("%s", nouvelOrdinateur->numSerie);
    printf("\n Entrer la marque: ");
    scanf("%s", nouvelOrdinateur->marque);
    printf("\n Entrer la vitesse du CPU: ");
    scanf("%f", &nouvelOrdinateur->vitesseCPU);
    printf("\n Entrer la ram: ");
    scanf("%d", &nouvelOrdinateur->ram);
    printf("\n Entrer la taille du disque dur: ");
    scanf("%d", &nouvelOrdinateur->tailleDisque);
    printf("\n Entrer le prix estimé de l'ordinateur: ");
    scanf("%d", &nouvelOrdinateur->prixEstime);
    printf("\n");

    return nouvelOrdinateur;

}


// Fonction 2 de suppression d'un ordinateur
void supprimer_Ordinateur(Tordinateur **listeOrdinateur, int nbreOrdi)
{
        int indice;
        printf("\n Veuillez entrer l'indice de l'ordinateur que vous voulez supprimer:  ");
        scanf("%d",&indice);
        while (indice > nbreOrdi || indice <= 0 )
        {
            printf("\ Aucune correspondance pour cet indice. Réessayez! ");
            scanf("%d", &indice);
        }

        free(listeOrdinateur + (indice -1));
        *(listeOrdinateur + (indice -1)) = NULL;
        printf("\n Votre ordinateur a bien été supprimé de la liste de vos ordinateurs. Merci! \n");
}


// Fonction 3 pour lister l'ensemble des informations
void informations_desOrdinateurs( Tordinateur **listeOrdinateur, int nbreOrdi)
{
    Tordinateur **tmpPtr;
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + (nbreOrdi); tmpPtr ++)
    {
        while((*tmpPtr) ==  NULL)
        {
            tmpPtr = tmpPtr + 1;
        }
        printf("\n L'ordinateur %s de numéro de série %s ayant une ram %d a un prix estimé à %d FCFA \n", (*tmpPtr)->marque,(*tmpPtr)->numSerie, (*tmpPtr)->ram, (*tmpPtr)->prixEstime);
    }
}


// Fonction 4 d'affichage des informations d'un ordinateur
void afficher_details_d_un_ordinateur (Tordinateur ** listeOrdinateur, int nbreOrdi)

// indice c'est l'indice du pc dont l'utilisateur veut lire les informations
{
        int indice;
        Tordinateur **tmpPtr;
        printf("\n Veuillez entrer l'indice de l'ordinateur que vous recherchez:  ");
        scanf("%d",&indice);
        while ( (indice > nbreOrdi) || (indice <= 0 ) || (*(listeOrdinateur + (indice -1))== NULL))
        {
            printf("\ Aucune correspondance pour cet indice. Réessayez! ");
            scanf("%d", &indice);
        }
        tmpPtr = listeOrdinateur + (indice -1);
        printf("\n ---------Information de l'ordinateur sélectionné---------");
        printf("\n Numéro de carte: %d", (*tmpPtr)->numCarte);
        printf("\n Spécialié: %s", (*tmpPtr)->specialite);
        printf("\n Numéro de série: %s", (*tmpPtr)->numSerie);
        printf("\n Marque: %s", (*tmpPtr)->marque);
        printf("\n Vitesse du CPU: %f", (*tmpPtr)->vitesseCPU);
        printf("\n Ram: %d", (*tmpPtr)->ram);
        printf("\n Taille du disque dur: %d", (*tmpPtr)->tailleDisque);
        printf("\n Prix estimé de l'ordinteur: %d \n", (*tmpPtr)->prixEstime);
}


// Fonction 8 pour la somme du prix des ordinateurs
void calculer_sommePrix(Tordinateur **listeOrdinateur , int nbreOrdi)
{

    int sommep = 0;
    Tordinateur **tmpPtr;
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        sommep = sommep + ((*tmpPtr)->prixEstime);
    }
    printf("\n La somme totale du prix des ordinateurs s'élève à %d FCFA", sommep);

}
