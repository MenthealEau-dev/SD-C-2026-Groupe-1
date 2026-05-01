/*

********************************************************
  Programme : Produit scalaire de deux vecteurs
  Nom : SD+C - Les fondamentaux – Exercice 1
  Ecrit en formalisme pointeur
  Auteurs :
            1. ABIDI Mawusé Jean-Marie Gédéon (GM)
            2. AKONDO Samihatou (GC)
            3. AKOTSU Yao Aurelien Placide (GM)
            4. AGBOGAN Komaln Marcel (GC)
            5. BARA Oussonè Bryann (IA&BD)
            6. ETOH Fortunatus (GM)
            7. TCHA-ZAWA Abdou Moudjib (IA&BD)
            8. TINANKPA Wilfried kodjo (IA&BD)
            9. ZAMNA Mahamat Salim (GM)
  IDE : Code::Blocks
  Chargé de l'UE : Monsieur AKAKPO
  Niveau : L1 Semestre 2
  Date de création : 07/04/2026
  Date de rendu : 08/04/2026
********************************************************

  */


  #include <stdio.h>
  #include <stdlib.h>
  #include <locale.h>


//Fonction de lecture la taille unique des vecteurs

void taille_vecteur(int *P_taille){
    scanf("%d",P_taille);
    while(*P_taille <=0)
    {
        printf("ERREUR!! Entrez une taille positive non nulle : ");
        scanf("%d", P_taille);
    }
}


 //Fonction de Lecture et enregistrement des vecteurs

void lire_vecteur(int *vect, int *P_taille){
    int indice;
    for ( indice=0; indice<*P_taille; indice++){
        printf("Composante %d : ",indice+1);
        scanf("%d", &*(vect+indice));
    }
}


 //Fonction de calcul du produit scalaire

int produit_scalaire(int *vect_U, int *vect_V, int taille){
    int indice, produit=0;
    for (indice=0; indice<taille; indice++){
        produit+=*(vect_U+indice) * *(vect_V+indice);
    }
    return produit;
}


  //Fonction principale

int main(void){

    setlocale(LC_ALL, "");

  //Lecture de la taille unique
    int taille,*P_taille;
    P_taille= &taille;
    printf(" Entrez la taille des vecteurs : ");
    taille_vecteur(P_taille);

  //Allocation de la mémoire
    int *vect_U = malloc(taille*sizeof(*vect_U));
    int *vect_V = malloc(taille*sizeof(*vect_V));

  //Vérification de la mémoire allouée
    if ((vect_U==NULL)||(vect_V==NULL))
    {
        printf("ERREUR d'allocation de mémoire");
        return 1;
    }


  //Lecture des composantes
    printf("Entrez les composantes du vecteur U : \n");
    lire_vecteur(vect_U, P_taille);
    printf("Entrez les composantes du vecteur V :  \n");
    lire_vecteur(vect_V, P_taille);

  //Operation du produit scalaire
    printf("Le produit scalaire U.V est = %d \n", produit_scalaire(vect_U, vect_V, taille));

  //libération de l'espace mémoire
    free(vect_U);
    free(vect_V);
    vect_U=NULL;
    vect_V=NULL;

    return 0;
}
