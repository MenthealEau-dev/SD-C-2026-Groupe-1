#include<stdio.h>
#include<stdlib.h>
#include"polynome.h"

int main(void)
{
    TPolynome* tabPolynome[MAX];
    int pos = 0;
    int choix = 0;
    int pos1,pos2;
    while(choix !=5)
    {   
        choix = menu();
        switch (choix)
        {
            
            case 1:
                printf("Bienvenu dans le menu d'ajout d'un poynome\n");
                if(pos >= MAX)
                {
                    printf("Vous avez atteind la limite de polynome ajoutable\n");
                }
                else
                {
                    *(tabPolynome + pos) = ajoutPolynome(&pos);
                    printf("Ajout en cours...\n");
                    printf("Votre polynome a bien ete ajouter!\n");
                }
                break;
            case 2:
                if(pos <2)
                {
                    printf("Vous n'avez pas assez de polynome pour utiliser ce menue\n");
                    printf("Veuillez encore en ajouter au moins %d\n",abs(pos-2));
                }
                else{
                    printf("Bienvenu dans le menu addition de polynome\n");
                    demanderPosition(&pos1 , &pos2);
                    tabPolynome[pos] = additionPolynome(tabPolynome , pos1 - 1 , pos2 - 1); 
                    pos++;
                    printf("La somme a bien ete efectuee...\n");
                }
                break;
            case 3:
                if(pos <2)
                {
                    printf("Vous n'avez pas assez de polynome pour utiliser ce menue\n");
                    printf("Veuillez encore en ajouter au moins %d\n",abs(pos-2));
                }
                else{
                    printf("Bienvenu dans le menu difference de polynome\n");
                    demanderPosition(&pos1 , &pos2);
                    tabPolynome[pos] = soustractionPolynome(tabPolynome, pos1 - 1, pos2 - 1);
                    pos++;
                    printf("Difference effectuee avec succes\n");
                }
                break;
            case 4:
                if(pos==0)
                {
                    printf("Aucun polynome n'est disponible a afficher\n");
                }
                else{
                    printf("Bienvenu dans le menu d'affchage des polynomes\n");
                    affichageTableau(tabPolynome,pos);
                }
                break;
            case 5:
                printf("Merci d'avoir visiter le menu...\n");
                break;
            default:
                printf("Ce menu n'est pas pris en compte par ce programme\n");
                break;
        }
        
    }

    for(int i = 0; i < pos; i++)
    {
        liberationPolynome(*(tabPolynome +i));
        *(tabPolynome +i) = NULL;
    }
    return 0;
}