#include <stdio.h>
#include <stdlib.h>
#include "Ordinateur.h"
#include "FonctionsTries.h"
#include "Mesfonctions.h"
#include <locale.h>

#define TAB_MAX 300


// Fonction 5 de répartition par spécialité

void repartitonSpecialite (Tordinateur **listeOrdinateur, int nbreOrdi)
{
    Tordinateur **tmpPtr;
    int deja [6] = {0, 0, 0, 0, 0, 0, 0};
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        if(strcmp((*tmpPtr)->specialite, "GM") == 0)
        {
           if(!deja[0])
            {
                printf("\n Voici les ordinateur de spécialité GM: ");
                deja[0] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie, (*tmpPtr)->ram, (*tmpPtr)->prixEstime);
        }

        if(strcmp((*tmpPtr)->specialite, "IS") == 0)
        {
           if(!deja[1])
            {
                printf("\n\n Voici les ordinateur de spécialité IS: ");
                deja[1] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie);
        }

        if(strcmp((*tmpPtr)->specialite, "GC") == 0)
        {
           if(!deja[2])
            {
                printf("\n Voici les ordinateur de spécialité GC: ");
                deja[2] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie);
        }

        if(strcmp((*tmpPtr)->specialite, "LT") == 0)
        {
           if(!deja[3])
            {
                printf("\n Voici les ordinateur de spécialité LT: ");
                deja[3] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie);
        }

        if(strcmp((*tmpPtr)->specialite, "IABD") == 0)
        {
           if(!deja[4])
            {
                printf("\n Voici les ordinateur de spécialité IABD: ");
                deja[4] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie);
        }

        if(strcmp((*tmpPtr)->specialite, "GE") == 0)
        {
           if(!deja[5])
            {
                printf("\n Voici les ordinateur de spécialité GE: ");
                deja[5] = 1;
            }
            printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie);
        }

    }

}

// Fonction 6 de répartition par Marque

void repartitionMarque (Tordinateur **listeOrdinateur, int nbreOrdi)
{
    Tordinateur **tmpPtr;
    int deja [4] = {0, 0, 0, 0};
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        if(strcmp((*tmpPtr)->marque, "HP") == 0)
        {
           if(!deja[0])
            {
                printf("\n Voici les ordinateur de Marque HP: ");
                deja[0] = 1;
            }
            printf("\n L'ordinateur de numéro de série %s ", (*tmpPtr)->numSerie);
        }

         if(strcmp((*tmpPtr)->marque, "DELL") == 0)
        {
           if(!deja[1])
            {
                printf("\n Voici les ordinateur de Marque DELL: ");
                deja[1] = 1;
            }
            printf("\n L'ordinateur de numéro de série %s ", (*tmpPtr)->numSerie);
        }
         if(strcmp((*tmpPtr)->marque, "LENOVO") == 0)
        {
           if(!deja[2])
            {
                printf("\n Voici les ordinateur de Marque LENOVO: ");
                deja[2] = 1;
            }
            printf("\n L'ordinateur de numéro de série %s ", (*tmpPtr)->numSerie);
        }
         if(strcmp((*tmpPtr)->marque, "TOSHIBA") == 0)
        {
           if(!deja[3])
            {
                printf("\n Voici les ordinateur de Marque TOSHIBA: ");
                deja[3] = 1;
            }
            printf("\n L'ordinateur de numéro de série %s ", (*tmpPtr)->numSerie);
        }
    }
}

// Fonction 7 de tri par vitesse de processeurs

void trier_parVitesse(Tordinateur **listeOrdinateur, int nbreOrdi)
{
    Tordinateur **tmpPtr;
    Tordinateur **tmpPtr1;
    Tordinateur **tmpPtr2;
    int i = 0;
    Tordinateur **relai;
    for (tmpPtr1 = listeOrdinateur; tmpPtr1 < (listeOrdinateur + (nbreOrdi-1)); tmpPtr1 ++)
    {
        for (tmpPtr2 = (listeOrdinateur+1); tmpPtr2 <(listeOrdinateur + nbreOrdi); tmpPtr2 ++)
        {
            if ((*tmpPtr2)->vitesseCPU < (*tmpPtr1)->vitesseCPU)
            {
                relai = *tmpPtr1;
                *tmpPtr1 = *tmpPtr;
                *tmpPtr2 = relai;
            }
        }
        (*(listeOrdinateur + i)) = (*tmpPtr1);
        (*(listeOrdinateur + (i+1))) = (*relai);
        i++;
    }
    printf("\n Voici la liste des ordinateurs triés: ");
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        printf("\n  L'ordinateur de vitesse CPU =  %f", (*tmpPtr)->vitesseCPU);
    }
}




