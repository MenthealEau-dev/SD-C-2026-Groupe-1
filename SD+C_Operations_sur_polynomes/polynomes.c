#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "polynomes.h"

/*================polynomes.c=====================*/

// 1-Création de la fonction de création et d'initialisation d'un polynome

TPolynome *creer_initialiser_poly()
{
    TPolynome *polynome;
    if((polynome = (TPolynome*)malloc(sizeof(TPolynome))) == NULL)
        exit(1);
    polynome->first = NULL;
    polynome->last = NULL;
    polynome->taille = 0;

    return polynome;
}

/*==============fin polynomes.c===================*/
