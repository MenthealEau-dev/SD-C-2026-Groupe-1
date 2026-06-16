#include <stdio.h>
#include <stdlib.h>
#include "FonctionsTries.h"
#include "Mesfonctions.h"
#include <locale.h>

#define TAB_MAX 300

// Fonction 5 de répartition par spécialité

void repartitonSpecialite(Tordinateur **listeOrdinateur, int nbreOrdi)
{

     if (nbreOrdi == 0 )
    {
        printf("\n Votre park est vide pour le moment! Veuillez saisir les informations d'au moins un ordinateur! Merci\n ");
    }
    else
    {
        Tordinateur **tmpPtr1;
        Tordinateur **tmpPtr2;
        Tordinateur **tmpPtr3;
        int deja;

        for (tmpPtr1 = listeOrdinateur; tmpPtr1 < listeOrdinateur + nbreOrdi; tmpPtr1++)
        {
            if (*tmpPtr1 != NULL)
            {
                deja = 0;
                for (tmpPtr2 = listeOrdinateur; tmpPtr2 < tmpPtr1; tmpPtr2++)
                {
                    if (*tmpPtr2 != NULL && strcmp((*tmpPtr1)->specialite, (*tmpPtr2)->specialite) == 0)
                    {
                        deja = 1;
                    }
                }
                if (deja == 0)
                {
                    printf("\n --------Voici les ordinateur de spécialité %s: -------\n", (*tmpPtr1)->specialite);
                    for (tmpPtr3 = listeOrdinateur; tmpPtr3 < listeOrdinateur + nbreOrdi; tmpPtr3++)
                    {
                        if (*tmpPtr3 != NULL && strcmp((*tmpPtr3)->specialite, (*tmpPtr1)->specialite) == 0)
                        {
                            printf("\n L'ordinateur %s de numéro de série %s \n", (*tmpPtr3)->marque, (*tmpPtr3)->numSerie);
                        }
                    }
                }
            }
        }
    }
}

// Fonction 6 de répartition par Marque WILFRIED

void repartitionMarque(Tordinateur **listeOrdinateur, int nbreOrdi)
{
     if (nbreOrdi == 0 )
    {
        printf("\n Votre park est vide pour le moment! Veuillez saisir les informations d'au moins un ordinateur! Merci\n ");
    }
    else
    {
        Tordinateur **tmpPtr1;
        Tordinateur **tmpPtr2;
        Tordinateur **tmpPtr3;
        int deja;

        for (tmpPtr1 = listeOrdinateur; tmpPtr1 < listeOrdinateur + nbreOrdi; tmpPtr1++)
        {
            if (*tmpPtr1 != NULL)
            {
                deja = 0;
                for (tmpPtr2 = listeOrdinateur; tmpPtr2 < tmpPtr1; tmpPtr2++)
                {
                    if (*tmpPtr2 != NULL && strcmp((*tmpPtr1)->marque, (*tmpPtr2)->marque) == 0)
                    {
                        deja = 1;
                    }
                }

                if (deja == 0)
                {
                    printf("\n --------Voici les ordinateur de Marque %s: --------\n", (*tmpPtr1)->marque);

                    for (tmpPtr3 = listeOrdinateur; tmpPtr3 < listeOrdinateur + nbreOrdi; tmpPtr3++)
                    {
                        if (*tmpPtr3 != NULL && strcmp((*tmpPtr3)->marque, (*tmpPtr1)->marque) == 0)
                        {
                            printf("\n L'ordinateur %s de numéro de série %s \n", (*tmpPtr3)->marque, (*tmpPtr3)->numSerie);
                        }
                    }
                }
            }
        }
    }
}

// Fonction 7 de tri par vitesse de processeurs

void trier_parVitesse(Tordinateur **listeOrdinateur, int nbreOrdi)
{
     if (nbreOrdi == 0 )
    {
        printf("\n Votre park est vide pour le moment! Veuillez saisir les informations d'au moins un ordinateur! Merci\n ");
    }
    else
    {
        Tordinateur **tmpPtr1;
        Tordinateur **tmpPtr2;
        Tordinateur **tmpPtr3;
        int deja = 0;

        for (tmpPtr1 = listeOrdinateur; tmpPtr1 < listeOrdinateur + nbreOrdi; tmpPtr1++)
        {
            if (*tmpPtr1 != NULL)
            {
                deja = 0;
            }
            for (tmpPtr2 = listeOrdinateur; tmpPtr2 < tmpPtr1; tmpPtr2++)
            {
                if(*tmpPtr2 != NULL && (*tmpPtr1)->vitesseCPU ==(*tmpPtr2)->vitesseCPU)
                {
                    deja = 1;
                }
            }
            if (deja == 0)
            {
                printf("\n --------Voici les ordinateur de Vitesse de Processeur %.2f--------\n", (*tmpPtr1)->vitesseCPU);

                for (tmpPtr3 = listeOrdinateur; tmpPtr3 < listeOrdinateur + nbreOrdi; tmpPtr3++)
                {
                    if (*tmpPtr3 != NULL &&(*tmpPtr3)->vitesseCPU ==(*tmpPtr1)->vitesseCPU)
                    {
                        printf("\n L'ordinateur %s de numéro de série %s \n", (*tmpPtr3)->marque, (*tmpPtr3)->numSerie);
                    }

                }
            }
        }
    }
}
