/*
********************************************************

  Programme : Gestion des informations des
              étudiants et de leurs notes .
  Nom : SD+C-2022-2023-DST-EPL-LF
  Ecrit en formalisme tableau
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
#define NB_ELEM_MAX 100

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

renseignement saisir_informations()

{

    renseignement etudiant;
    printf("\n\n Entrez le numéro de l'etudiant: ");
    scanf("%d", &etudiant.numero);
    printf("\n Entrez le nom de l'étudiant: ");
    scanf("%s", etudiant.nom);
    printf("\n Entrez le prénom de l'étudiant: ");
    scanf("%s", etudiant.prenom);
    printf("\n Entrez la note de DST: ");
    scanf("%d", &etudiant.noteDst);
    printf("\n Entrez la note d'Examen: ");
    scanf("%d", &etudiant.noteExam);
    return etudiant;
}

//Fonction de calcul de la moyenne  de chaque étudiant

void calculer_moyenne(renseignement liste_etudiant[nbre_etudiant], int nbre_etudiant)
{

    int cmpt;

    for (cmpt = 0; cmpt < nbre_etudiant; cmpt++)
    {
        liste_etudiant[cmpt].moyBrute = 0.45*(liste_etudiant[cmpt].noteDst) + 0.55*(liste_etudiant[cmpt].noteExam);
        if ((liste_etudiant[cmpt].moyBrute) < 10)
        {
            (liste_etudiant[cmpt].moyDef) = (liste_etudiant[cmpt].moyBrute) + 1;
            (liste_etudiant[cmpt].bonus) = 1;
        }
        if ((liste_etudiant[cmpt].moyBrute) < 15 && (liste_etudiant[cmpt].moyBrute)> 10)
        {
            (liste_etudiant[cmpt].moyDef) = (liste_etudiant[cmpt].moyBrute) + 0.5;
            (liste_etudiant[cmpt].bonus) = 0.5;
        }
        if ((liste_etudiant[cmpt].moyBrute) > 15)
        {
            (liste_etudiant[cmpt].moyDef) = (liste_etudiant[cmpt].moyBrute);
            (liste_etudiant[cmpt].bonus) = 0;
        }
    }

}


//Fonction d'afficher des résultats (moyennes brute, définitive et moyenne générale)

void afficher_resultats(renseignement liste_etudiant[nbre_etudiant],int nbre_etudiant)
{
    int cnpt;

    printf("\n Voici le résultat des étudiants: ");
    float moyGen;
    moyGen = 0;
    for (cnpt = 0 ; cnpt < nbre_etudiant ; cnpt++)
    {
        printf("\n Informations de l'étudiant %d: ", cnpt+1);
        printf("\n Numéro: %d", liste_etudiant[cnpt].numero);
        printf("\n Nom: %s", liste_etudiant[cnpt].nom);
        printf("\n Prénom: %s",liste_etudiant[cnpt].prenom);
        printf("\n Note de DST: %d", liste_etudiant[cnpt].noteDst);
        printf("\n Note d'Exam: %d", liste_etudiant[cnpt].noteExam);
        printf("\n Moyenne Brute: %.2f", liste_etudiant[cnpt].moyBrute);
        printf("\n Bonus: % .1f", liste_etudiant[cnpt].bonus);
        printf("\n Moyenne Définitive: %.2f",liste_etudiant[cnpt].moyDef);
        moyGen += liste_etudiant[cnpt].moyDef;
    }
    moyGen = moyGen / nbre_etudiant;
    printf("\n La moyenne générale de la classe est %.2f", moyGen );
}

// Fontion Principale
int main()
{
    setlocale(LC_ALL,"");

    printf("\n Entrez le nombre des étudiants: ");
    scanf("%d",&nbre_etudiant);

    while(nbre_etudiant > NB_ELEM_MAX)
    {
        printf("\n Erreur! nombre trop grand! veuillez resaisir: ");
        scanf("%d",&nbre_etudiant);
    }

    int cpt;

    renseignement table[nbre_etudiant];
    for(cpt=0; cpt < nbre_etudiant; cpt ++)
    {
        printf("\n Entrez les informations de l'etudiant %d:", cpt+1);
        table[cpt] = saisir_informations();
    }

    calculer_moyenne(table, nbre_etudiant);
    afficher_resultats(table, nbre_etudiant);

    return 0;
}
