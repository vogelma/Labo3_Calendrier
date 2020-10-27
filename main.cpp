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

      for (int moisCourant = 1; moisCourant <= DECEMBRE; ++moisCourant) {
         //test avant chaque boucle de mois
         (moisCourant == FEVRIER ? nbreJours = 28 : moisCourant == AVRIL || moisCourant == JUIN ||
                                                    moisCourant == SEPTEMBRE || moisCourant == NOVEMBRE ? nbreJours = 30
                                                                                                        : nbreJours = 31);
         for(int nbreJoursAffiche = 0; nbreJoursAffiche <= nbreJours; ++nbreJoursAffiche)
         {
            cout << setw(W)  << nbreJoursAffiche;
         }
      }

      //hello
      cout << "Voulez-vous recommencer [O/N]? ";
      cin >> recommencer;
      cin.clear();
      EMPTY_BUFFER

   } while (recommencer == 'O' or recommencer == 'o');

   return EXIT_SUCCESS;
}