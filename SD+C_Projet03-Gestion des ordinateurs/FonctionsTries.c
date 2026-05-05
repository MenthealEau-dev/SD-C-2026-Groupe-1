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
    int i;
    int deja [6] = {0, 0, 0, 0, 0, 0, 0};
    for (tmpPtr = listeOrdinateur; tmpPtr < listeOrdinateur + nbreOrdi; tmpPtr ++)
    {
        for (i = 0; i < nbreOrdi; i ++)
        {
             if(strcmp((*tmpPtr)->specialite, (*listeOrdinateur + i)->specialite) == 0)
            {
                if(!deja[0])
                    {
                        printf("\n Voici les ordinateur de spécialité %s ", (*listeOrdinateur + i)->specialite);
                        deja[0] = 1;
                    }
                printf("\n L'ordinateur %s de numéro de série %s ", (*tmpPtr)->marque,(*tmpPtr)->numSerie, (*tmpPtr)->ram, (*tmpPtr)->prixEstime);
            }
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
                relai = tmpPtr1;
                tmpPtr1 = tmpPtr2;
                tmpPtr2 = relai;
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
