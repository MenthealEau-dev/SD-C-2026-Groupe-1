/**
********************************************************

  Programme :  Opérations sur des polynômes
               à partir d'une liste chaînée.

  Nom :      SD+C-2026-Groupe-1-Polynômes
  Auteurs :
            1. ABIDI Mawusé Jean-Marie Gédéon (GM)
            2. AKONDO Samihatou               (GC)
            3. AKOTSU Yao Aurelien Placide    (GM)
            4. AGBOGAN Komlan Marcel          (GC)
            5. BARA Oussonè Bryann           (IA&BD)
            6. ETOH Fortunatus                (GM)
            7. TCHA-ZAWA Abdou Moudjib       (IA&BD)
            8. TINANKPA Wilfried Kodjo       (IA&BD)
            9. ZAMNA Mahamat Salim            (GM)


  IDE : Code::Blocks
  Chargé de l'UE : Monsieur AKAKPO
  Niveau : L1 Semestre 2
  Date de création : 14/06/2026
  Date de rendu : 23/06/2026

********************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "polynomes.h"

int main()
{
    setlocale(LC_ALL,"");

    // Déclaration des pointeurs sans allocation mémoire
    TPolynome *polynome1 = NULL;
    TPolynome *polynome2 = NULL;
    TPolynome *polynome3 = NULL;

int choix = 0;
    while(choix != 3)
    {
        int decision = 0;
        choix = menuGeneral();
        switch(choix)
        {
        case 1:
            polynome1 = creer_initialiser_poly();
            polynome2 = creer_initialiser_poly();

            printf("\nSAISIE DES INFORMATIONS SUR LES DEUX POLYNOMES : \n");
            saisir_infoPolynome(polynome1,1);
            afficher_polynome(polynome1,1);
            saisir_infoPolynome(polynome2,2);
            afficher_polynome(polynome2,2);

            printf("\nADDITION DES DEUX POLYNOMES : \n");
            polynome3 = additionner_polynomes(polynome1,polynome2);
            afficher_polynome(polynome3,3);
            printf("\nAddition des deux polyn�mes r�ussie avec succ�s! Merci\n");

            detruire_polynome(polynome1); free(polynome1);
            detruire_polynome(polynome2); free(polynome2);
            detruire_polynome(polynome3); free(polynome3);

            break;
    return 0;
}

