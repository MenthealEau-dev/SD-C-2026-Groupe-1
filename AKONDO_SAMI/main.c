#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynome.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

    TPolynome *Polynome1 = NULL;
    TPolynome *Polynome2 = NULL;
    TPolynome *Polynome3 = NULL;

    int menu = 0;
    while (menu != 4)
    {
        int choix = 0;
        menu = menuComplet();
        switch (menu)
        {
        case 1:

            Polynome1 = creation_initialisation();
            Polynome2 = creation_initialisation();

            printf("\n******AFFICHAGE DE VOS POLYNÔMES******\n");
            saisie_informations (Polynome1, 1);
            trier_Liste (Polynome1);

            saisie_informations (Polynome2, 2);
            trier_Liste (Polynome2);


            printf("Polynôme 1 : \n");
            afficher (Polynome1,1);


            printf("Polynôme 2 : \n");
            afficher (Polynome2,2);

            detruire(Polynome1);
            detruire(Polynome2);

            break;

        case 2:

            Polynome1 = creation_initialisation();
            Polynome2 = creation_initialisation();

            printf("\n*******ADDITION DE VOS POLYNÔMES******\n");

            saisie_informations (Polynome1, 1);
            trier_Liste (Polynome1);

            saisie_informations (Polynome2, 2);
            trier_Liste (Polynome2);


            Polynome3 = additionner_Polynome(Polynome1, Polynome2);
            trier_Liste (Polynome3);
            afficher(Polynome3, 3);
            printf("\n Addition terminée\n");

            detruire(Polynome1);
            detruire(Polynome2);
            detruire(Polynome3);

            break;

        case 3:

            Polynome1 = creation_initialisation();
            Polynome2 = creation_initialisation();
            printf("\n******SOUSTRACTION DE VOS POLYNÔMES******\n");

            saisie_informations (Polynome1, 1);
            trier_Liste (Polynome1);

            saisie_informations (Polynome2, 2);
            trier_Liste (Polynome2);


            printf("\n 1. Polynôme 1 - Polynôme 2 ? \n");
            printf("\n 2. Polynôme 2 - Polynôme 1 ? \n");

            while(choix != 1 && choix != 2)
            {
                printf("\nVeuillez faire un choix correct !!\n");
                scanf("%d",&choix);
            }
            if (choix == 1){
                Polynome3 = soustraire_Polynome(Polynome1, Polynome2);
            }
            if (choix == 2){
                Polynome3 = soustraire_Polynome(Polynome2, Polynome1);
            }
            afficher(Polynome3, 3);
            printf("\n Soustraction terminée\n");

            detruire(Polynome1);
            detruire(Polynome2);
            detruire(Polynome3);

            break;

        case 4:
            printf("\n******MERCI D'AVOIR VISITÉ LE MENU******\n");
            break;

        default:
            printf("\n Menu indisponible. Veuillez choisir un menu correct \n");
            break;
        }
    }
    return 0;
}
