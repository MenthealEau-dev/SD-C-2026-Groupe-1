/*
********************************************************

  Programme : Gestion des informations des
              étudiants et de leurs notes .
  Nom : SD+C-2022-2023-DST-EPL-LF
  Ecrit en formalisme pointeur
  Auteurs :
            1. ABIDI Mawusé Jean-Marie Gédéon (GM)
            2. AKONDO Samihatou (GC)
            3. AKOTSU Yao Aurelien Placide (GM)
            4. AGBOGAN Komlan Marcel (GC)
            5. BARA Oussonè Bryann (IA&BD)
            6. ETOH Fortunatus (GM)
            7. TCHA-ZAWA Abdou Moudjib (IA&BD)
            8. TINANKPA Wilfried kodjo (IA&BD)
            9. ZAMNA Mahamat Salim (GM)

  IDE : Code::Blocks
  Chargé de l'UE : Monsieur AKAKPO
  Niveau : L1 Semestre 2
   Date de création : 20/04/2026
  Date de rendu : 21/04/2026

********************************************************


    PARTIE C
    Algorythme du programme qui répond au cahier des charges :

Début
    Lire N
    Pour i de 0 à N-1
        Saisir données étudiant
        Calculer moyenne_brute
        Déterminer bonus
        Calculer moyenne_definitive
    FinPour

    Calculer moyenne_generale

    Pour chaque étudiant
        Comparer à moyenne_generale → Valide ou Non
    FinPour
Fin
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Définition de la structure contenant les informations des étudiants

typedef struct renseignement renseignement;
struct renseignement
{
    int numero;
    char nom[50];
    char prenom[50];
    int noteDst;
    int noteExam;
    float moyBrute;
    float bonus;
    float moyDef;
};

//Variable contenant le nombre total des étudiants à enregistrer

 int nbre_etudiant;


// Fonction ne prenant aucun paramètre pour la saisie des informations

renseignement *saisir_informations()
{
    renseignement *liste_etudiant;
    renseignement *cpt;
    int i=0;
    printf("\n Entrer le nombre d'étudiant: ");
    scanf("%d",&nbre_etudiant);
    liste_etudiant = (renseignement*)malloc(nbre_etudiant*sizeof(renseignement));
    for (cpt = liste_etudiant; cpt < (liste_etudiant + nbre_etudiant); cpt ++)
    {
        printf("\n Entrer les informations de l'étudiant %d", i+1);
        printf("\n\n Entrer le numero de l'étudiant: ");
        scanf("%d", &cpt->numero);
        printf("\n Entrer le nom de l'étudiant: ");
        scanf("%s", cpt->nom);
        printf("\n Entrer le prenom de l'étudiant: ");
        scanf("%s", cpt->prenom);
        printf("\n Entrer la note de DST: ");
        scanf("%d", &cpt->noteDst);
        printf("\n Entrer la note d'Examen: ");
        scanf("%d", &cpt->noteExam);
    i++;
    }
       return liste_etudiant;
}

//Fonction de calcul de la moyenne  de chaque étudiant

void calculer_moyenne(renseignement*liste_etudiant)
{
    int i=0;
    renseignement *cmpt;
    for (cmpt = liste_etudiant; cmpt < (liste_etudiant+nbre_etudiant); cmpt++)
    {
        cmpt->moyBrute = 0.45* (cmpt->noteDst) + 0.55* (cmpt->noteExam);
        if ((cmpt->moyBrute) < 10)
        {
            (cmpt->moyDef) = (cmpt->moyBrute) + 1;
            (cmpt->bonus) = 1;
        }
        if ((cmpt->moyBrute) < 15 && (cmpt->moyBrute)>10)
        {
            (cmpt->moyDef) = (cmpt->moyBrute) + 0.5;
            (cmpt->bonus) = 0.5;
        }
        if ((cmpt->moyBrute) > 15 )
        {
            (cmpt->moyDef) = (cmpt->moyBrute);
            (cmpt->bonus) = 0;
        }
            i++;
    }

}


//Fonction d'afficher des résultats (moyennes brute et définitive)

void afficher_resultats(renseignement*liste_etudiant)
{
    renseignement*cnpt;
    int p =0;
    int moyGen = 0;
    printf("\n Voici le resultat des étudiants: ");
    for (cnpt = liste_etudiant; cnpt < (liste_etudiant+nbre_etudiant); cnpt++)
    {
        printf("\n Informations de l'etudiant %d: ", p+1);
        printf("\n Numéro: %d", cnpt->numero);
        printf("\n Nom: %s", cnpt->nom);
        printf("\n Prénom: %s",cnpt->prenom);
        printf("\n Note de DST: %d", cnpt->noteDst);
        printf("\n Note d'Exam: %d", cnpt->noteExam);
        printf("\n Moyenne Brute: %.2f", cnpt->moyBrute);
        printf("\n Bonus: %.1f", cnpt->bonus);
        printf("\n Moyenne Définitive: %.2f", cnpt->moyDef);
        p++;
        moyGen += (cnpt->moyDef);
    }
    moyGen = moyGen / nbre_etudiant;
    printf("\n La moyenne générale de la classe est %.2f", moyGen );
}

//Fonction principale

int main()
{
   setlocale(LC_ALL,"");

   renseignement *table;
   table = (renseignement*)malloc(nbre_etudiant*sizeof(renseignement));
   table = saisir_informations();
   calculer_moyenne(table);
   afficher_resultats(table);
   return 0;
}
