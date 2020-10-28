/*-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Maëlle Vogel et Louis-Salim Ghosn
Date creation  : 27.10.2020
Description    : <à compléter>
Remarque(s)    : <à compléter>
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
using namespace std;

int main() {

   enum Mois {
      JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
   };

   const int ANNEEMIN = 1900;
   const int ANNEEMAX = 2100;
   const int W = 2;
   bool fluxErreur;
   int nbreJours;

   int anneeUtilisateur;
   char recommencer;

   //boucle de saisie utilisateur recommencer
   do {

      //boucle de saisie utilisateur d'année
      do {
         fluxErreur = 0;

         cout << "Entrez une valeur [" << ANNEEMIN << "-" << ANNEEMAX << "]:";
         cin >> anneeUtilisateur;

         //vérifie les erreurs du flux et les années limites
         if (!cin.good() or anneeUtilisateur < ANNEEMIN or anneeUtilisateur > ANNEEMAX) {
            fluxErreur = 1;
            cout << "/!\\ recommencez" << endl;
            cin.clear();

         }
         EMPTY_BUFFER

      } while (fluxErreur);




      for (int moisCourant = JANVIER; moisCourant <= DECEMBRE; ++moisCourant) {
         //test avant chaque boucle de mois
         (moisCourant == FEVRIER ? nbreJours = 28 : moisCourant == AVRIL || moisCourant == JUIN ||
                                                    moisCourant == SEPTEMBRE || moisCourant == NOVEMBRE ? nbreJours = 30
                                                                                                        : nbreJours = 31);
            switch (moisCourant) {
               case 1  : cout << "JANVIER " << anneeUtilisateur << endl; break;
               case 2  : cout << "FEVRIER " << anneeUtilisateur << endl; break;
               case 3  : cout << "MARS " << anneeUtilisateur << endl; break;
               case 4  : cout << "AVRIL " << anneeUtilisateur << endl; break;
               case 5  : cout << "MAI " << anneeUtilisateur << endl; break;
               case 6  : cout << "JUIN " << anneeUtilisateur << endl; break;
               case 7  : cout << "JUILLET " << anneeUtilisateur << endl; break;
               case 8  : cout << "AOUT " << anneeUtilisateur << endl; break;
               case 9  : cout << "SEPTEMBRE " << anneeUtilisateur << endl; break;
               case 10 : cout << "OCTOBRE " << anneeUtilisateur << endl; break;
               case 11 : cout << "NOVEMBRE " << anneeUtilisateur << endl; break;
               case 12 : cout << "DECEMBRE " << anneeUtilisateur << endl; break;
            }

            cout << "  L  M  M  J  V  S  D" << endl;

            int JourSemaine = 1;
            for (int Jour = 1; Jour <= nbreJours; ++Jour)
            {
               if(Jour == 1) {
                  cout << setw(3* JourSemaine) << Jour;
               }
               else {
                  cout << setw(3) << Jour;
               }

               if(JourSemaine == 7 and Jour != nbreJours) // on voit cette ligne en labo
               {
                  cout << endl;
                  JourSemaine = 1;
               }
               else{
                  ++JourSemaine;
               }
            }
            cout << endl << endl;
      }


      cout << "Voulez-vous recommencer [O/N]? ";
      cin >> recommencer;
      cin.clear();
      EMPTY_BUFFER

   } while (recommencer == 'O' or recommencer == 'o');

   return EXIT_SUCCESS;
}