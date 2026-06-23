#include<stdio.h>
#include<stdlib.h>
#include"polynome.h"

//fonction d'initialisation d'un polynome vide
void initialisation(TPolynome* polynome)
{
    polynome->debut = NULL;
    polynome->fin = NULL;
    polynome->taille = 0;
}

//fonction d'allocation dynamique d'un monome
void allocationMonome(TMonome** nouveau)
{
    *nouveau = (TMonome*)malloc(sizeof(TMonome));
    if(*nouveau == NULL)
    {
        printf("ERREUR D'ALLOCATION\n");
        exit(EXIT_FAILURE);
    }
}

//fonction d'allocation dynamique d'un polynome
void allocationPolynome(TPolynome** p)
{
    *p = (TPolynome*)malloc(sizeof(TPolynome));
    if(*p == NULL)
    {
        printf("ERREUR D'ALLOCATION\n");
        exit(EXIT_FAILURE);
    }
}

/*
char choisirVariable()
{
    char var;
    printf("Quel est le nom de variable dont depend vos polynomes : ");
    scanf("%c",var);
    return var;
}
*/


//fonction de saisie du coefficient et du degre d'un monome
void remplirChamp(TPolynome* polynome ,TMonome* nouveau)
{
    printf("Entrez le degre du monome %d : ", (polynome->taille +1) );
    scanf("%d",&nouveau->monome.deg);
    printf("Entrez le coeficient du monome %d : ",(polynome->taille +1) );
    scanf("%f", &nouveau->monome.coef);
}


//fonction d'ajout d'un monome dans un polynome
void saisirMonome(TPolynome* polynome)
{
    TMonome* nouveau;    
    allocationMonome(&nouveau);
    remplirChamp(polynome ,nouveau);
    if(polynome->taille == 0)
    {
        nouveau->next = polynome->debut;       
        polynome->debut = nouveau;
        polynome->fin = nouveau;
        polynome->taille++;
    }
    else
    {
        polynome->fin->next = nouveau;
        nouveau->next = NULL;
        polynome->fin = nouveau;
        polynome->taille++;
    }
}



//fonction d'affichage d'un polynome
void affichagePolynome(TPolynome* polynome)
{
    TMonome* jump;
    jump = polynome->debut;
    while(jump != NULL)
    {
        if(jump->monome.deg == 0)
        {
            printf("%.2f",jump->monome.coef);
        }
        else if(jump->monome.deg == 1)
        {
            printf("%.2fx",jump->monome.coef);
        }
        else
        {
            printf("%.2fx^%d",jump->monome.coef, jump->monome.deg);
        }
        if(jump->next != NULL)
        {
            if(jump->next->monome.coef >0)
            {
                printf(" + ");
            }
            else
            {
                printf(" ");
            }
        }
        jump = jump->next;
    }
    printf("\n");
}


//fonction de saisie complete d'un polynome
void saisirPolynome(TPolynome* polynome)
{   
    int terme;
    printf("Combien de terme contient votre polynome : ");
    scanf("%d",&terme);
    for(int i = 0; i < terme; i++)
    {
        saisirMonome(polynome);
    }
}


//fonction de tri des monomes selon les degres decroissants
void trierPolynome(TPolynome* polynome)
{
    TMonome* jump1;
    TMonome* jump2;
    TValue temp;

    jump1 = polynome->debut;

    while(jump1 != NULL)
    {
        jump2 = jump1->next;

        while(jump2 != NULL)
        {
            if(jump1->monome.deg < jump2->monome.deg)
            {
                temp = jump1->monome;
                jump1->monome = jump2->monome;
                jump2->monome = temp;
            }

            jump2 = jump2->next;
        }

        jump1 = jump1->next;
    }
}


//fonction de creation et d'ajout d'un polynome dans le tableau
TPolynome* ajoutPolynome(int* pos)
{
    TPolynome* p;
    allocationPolynome(&p);
    initialisation(p);
    saisirPolynome(p);
    trierPolynome(p);
    (*pos)++;
    return p;
}


//fonction d'affichage du menu principal
int menu()
{
    int choix;
    printf("\n");
    printf("***********************************\n");
    printf("BIENVENU DANS LE MENU DES POLYNOMES\n");
    printf("***********************************\n");
    printf("1. AJOUT D'UN POLYNONE\n");
    printf("2. ADDITION DE POLYNOMES\n");
    printf("3. DIFFERENCE DE POLYNOME\n");
    printf("4. AFFICHAGE DES POLYNOMES\n");
    printf("5. QUITTER\n");
    printf("***********************************\n");
    printf("Veuillez faire un choix : ");
    scanf("%d",&choix);
    return choix;

}

//fonction de liberation de tous les monomes d'un polynome
void liberationPolynome(TPolynome* polynome)
{
    TMonome* jump;

    while(polynome->debut != NULL)
    {
        jump = polynome->debut;
        polynome->debut = polynome->debut->next;
        free(jump);
    }

    free(polynome);
}



//fonction d'affichage de tous les polynomes stockes dans le tableau
void affichageTableau(TPolynome* tabPolynome[], int pos)
{
    for(int i =0 ; i<pos ; i++)
    {   
        printf("Polynome %d : \n",i+1);
        affichagePolynome(*(tabPolynome + i));
        printf("-----------------------------------------------------\n");
    }
}



//fonction d'ajout direct d'un monome dans un polynome ulilisee pour la somme te la soustraction
void addMonome(TPolynome* somme,int deg , float coef)
{
    TMonome* new;
    allocationMonome(&new);
    new->monome.coef = coef;
    new->monome.deg = deg;
    if(somme->taille == 0)
    {
        new->next = somme->debut;       
        somme->debut = new;
        somme->fin = new;
        somme->taille++;
    }
    else
    {
        somme->fin->next = new;
        new->next = NULL;
        somme->fin = new;
        somme->taille++;
    }

}


//fonction de recherche d'un monome a partir de son degre
TMonome* rechercherMonome(TPolynome* polynome , int deg)
{
    TMonome* jump;

    jump = polynome->debut;

    while(jump != NULL)
    {
        if(jump->monome.deg == deg)
        {
            return jump;
        }

        jump = jump->next;
    }

    return NULL;
}


//fonction verifiant si un degre existe deja dans un polynome
int existeDegre(TPolynome* polynome , int deg)
{
    TMonome* jump;

    jump = polynome->debut;

    while(jump != NULL)
    {
        if(jump->monome.deg == deg)
        {
            return 1;
        }

        jump = jump->next;
    }

    return 0;
}



//fonction de recuperation des positions des polynomes a utiliser
void demanderPosition(int* pos1 , int* pos2)
{
    int a;
    int b;
    printf("Quelles sont les positions des fonctions dont vous voulez utiliser ? \n");
    printf("La premiere : ");
    scanf("%d", &a);
    printf("La seconde : ");
    scanf("%d", &b);
    *(pos1) = a;
    *(pos2) = b;

}


//fonction de calcul de la somme de deux polynomes
TPolynome* additionPolynome(TPolynome* tabPolynome[], int pos1 , int pos2)
{
    TPolynome* somme;
    TPolynome* pol1;
    TPolynome* pol2;

    TMonome* jump1;
    TMonome* jump2;
    TMonome* trouve;

    allocationPolynome(&somme);
    initialisation(somme);

    pol1 = tabPolynome[pos1];
    pol2 = tabPolynome[pos2];

    jump1 = pol1->debut;

    while(jump1 != NULL)
    {
        trouve = rechercherMonome(pol2 , jump1->monome.deg);

        if(trouve != NULL)
        {
            addMonome(somme,jump1->monome.deg,jump1->monome.coef + trouve->monome.coef);
        }
        else
        {
            addMonome(somme,jump1->monome.deg,jump1->monome.coef);
        }

        jump1 = jump1->next;
    }

    jump2 = pol2->debut;

    while(jump2 != NULL)
    {
        if(!existeDegre(pol1 , jump2->monome.deg))
        {
            addMonome(
                somme,
                jump2->monome.deg,
                jump2->monome.coef
            );
        }

        jump2 = jump2->next;
    }
    trierPolynome(somme);
    return somme;
}




//fonction de calcul de la difference de deux polynomes
TPolynome* soustractionPolynome(TPolynome* tabPolynome[], int pos1 , int pos2)
{
    TPolynome* difference;
    TPolynome* pol1;
    TPolynome* pol2;

    TMonome* jump1;
    TMonome* jump2;
    TMonome* trouve;

    allocationPolynome(&difference);
    initialisation(difference);

    pol1 = tabPolynome[pos1];
    pol2 = tabPolynome[pos2];

    jump1 = pol1->debut;

    while(jump1 != NULL)
    {
        trouve = rechercherMonome(pol2 , jump1->monome.deg);

        if(trouve != NULL)
        {
            addMonome(difference,jump1->monome.deg,jump1->monome.coef - trouve->monome.coef);
        }
        else
        {
            addMonome(difference,jump1->monome.deg,jump1->monome.coef);
        }

        jump1 = jump1->next;
    }

    jump2 = pol2->debut;

    while(jump2 != NULL)
    {
        if(!existeDegre(pol1 , jump2->monome.deg))
        {
            addMonome(difference,jump2->monome.deg,-jump2->monome.coef);
        }

        jump2 = jump2->next;
    }
    trierPolynome(difference);
    return difference;
}