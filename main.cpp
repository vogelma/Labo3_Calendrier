/*-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Maëlle Vogel et Louis-Salim Ghosn
Date creation  : 27.10.2020
Description    : Ce programme va demander une date à l'utilisateur puis va afficher le calendrier de cette
                 année. A la fin le programme demande si l'utilisateur veut recommencer. Les erreurs de
                 saisie sont traitées.
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
   const int W = 3;
   const char oui = 'O';
   const char non = 'N';

   bool fluxErreur;
   int  anneeUtilisateur;
   char recommencer;


   //boucle de saisie utilisateur recommencer
   do {

      //boucle de saisie utilisateur d'année
      do {

         fluxErreur = 0;

         ////AFFICHAGE SAISIE ANNEE/////
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

      //saut de ligne avec janvier
      cout << endl;

      //le 1er janvier est un lundi
      int jourSemaine = 1;
      int nbreJours;

      //Affichage mois
      for (int moisCourant = JANVIER; moisCourant <= DECEMBRE; ++moisCourant)
      {
         //test pour connaître le nombre de jour
         if (moisCourant == FEVRIER)
         {
            //année bissextile
            if (anneeUtilisateur % 400 == 0 or anneeUtilisateur % 4 == 0 and anneeUtilisateur % 100 != 0)
            {
               nbreJours = 29;
            }
            else
               {
               nbreJours = 28;
            }

         }
         else if (moisCourant == AVRIL || moisCourant == JUIN || moisCourant == SEPTEMBRE || moisCourant == NOVEMBRE)
         {
            nbreJours = 30;
         }
         else {
            nbreJours = 31;
         }

         switch (moisCourant) {
            case JANVIER  :
               cout << "JANVIER ";
               break;
            case FEVRIER  :
               cout << "FEVRIER ";
               break;
            case MARS  :
               cout << "MARS ";
               break;
            case AVRIL  :
               cout << "AVRIL ";
               break;
            case MAI  :
               cout << "MAI ";
               break;
            case JUIN  :
               cout << "JUIN ";
               break;
            case JUILLET  :
               cout << "JUILLET ";
               break;
            case AOUT  :
               cout << "AOUT ";
               break;
            case SEPTEMBRE  :
               cout << "SEPTEMBRE ";
               break;
            case OCTOBRE :
               cout << "OCTOBRE ";
               break;
            case NOVEMBRE :
               cout << "NOVEMBRE ";
               break;
            case DECEMBRE :
               cout << "DECEMBRE ";
               break;
         }

         cout << anneeUtilisateur << endl;
         cout << "  L  M  M  J  V  S  D" << endl;

         //affichage jours
         for (int jour = 1; jour <= nbreJours; ++jour) {
            //alignement pour le premier de chaque mois
            if (jour == 1) {
               cout << setw(W * jourSemaine) << jour;
            }
            else {
               cout << setw(W) << jour;
            }

            //saut de ligne si c'est dimanche
            //seulement si c'est pas le dernier jour du mois
            if (jourSemaine == 7) {
               jourSemaine = 1;

               if (jour != nbreJours) {
                  cout << endl;
               }
            }
            else {
               ++jourSemaine;
            }
         }

         cout << endl << endl;
      }


      //boucle de recommencement
      do {

         fluxErreur = 0;

         cout << "Voulez-vous recommencer [O/N]? ";
         cin >> recommencer;

         if (recommencer != non and recommencer != oui or !cin.good())
         {
            fluxErreur = 1;
            cout << "/!\\ recommencez" << endl;
            cin.clear();
         }
         EMPTY_BUFFER

      } while(fluxErreur);

   } while (recommencer == oui);

   return EXIT_SUCCESS;
}