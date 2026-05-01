#ifndef ORDINATEUR_H
#define ORDINATEUR_H


// Déclaration de la structure

typedef struct Tordinateur Tordinateur;
struct Tordinateur {

   int numCarte;
   char specialite[30];
   char numSerie[30];
   char marque [30];
   float vitesseCPU;
   int ram;
   int tailleDisque;
   int prixEstime;
};

#endif // ORDINATEUR_H
