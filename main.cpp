/*--------------------------------------------------------------------------------------------------------------
Nom du fichier : main.cpp
Auteur(s)      : Maëlle Vogel et Louis-Salim Ghosn
Date creation  : 27.10.2020
Description    : Ce programme va demander une année à l'utilisateur puis va afficher le calendrier de cette
                 année. A la fin le programme demande si l'utilisateur veut recommencer. Les erreurs de
                 saisie sont traitées.
Remarque(s)    : Le switch n'as pas de default car toutes les valeurs ont un résultat différent.
Compilateur    : Mingw-w64 g++ 8.1.0
-------------------------------------------------------------------------------------------------------------*/
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>

#define EMPTY_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n');
using namespace std;

int main() {

   enum Mois {
      JANVIER = 1,
      FEVRIER    ,
      MARS       ,
      AVRIL      ,
      MAI        ,
      JUIN       ,
      JUILLET    ,
      AOUT       ,
      SEPTEMBRE  ,
      OCTOBRE    ,
      NOVEMBRE   ,
      DECEMBRE
   };

   const int   ANNEEMIN = 1900;
   const int   ANNEEMAX = 2100;
   const int   W        =    3;
   const char  OUI      =  'O';
   const char  NON      =  'N';

   bool fluxErreur;
   int  anneeUtilisateur;
   char recommencer;


   // do de la boucle recommencer?
   do {

      // do de la boucle année? gère erreurs de saisie
      do {

         fluxErreur = false; // faux par défaut, flux intact

         cout << "Entrez une valeur [" << ANNEEMIN << "-" << ANNEEMAX << "] : ";
         cin  >>  anneeUtilisateur;

         // vérifie si la saisie de l'utilisateur n'a pas cassé le flux ou n'a pas respecté l'intervalle d'années
         if (!cin.good() or anneeUtilisateur < ANNEEMIN or anneeUtilisateur > ANNEEMAX)
         {
            fluxErreur = true; // passe la variable à vrai
            cout << "/!\\ recommencez" << endl;
            cin.clear();      // vide le cache d'erreur
         }

         EMPTY_BUFFER

      } while (fluxErreur); // tant que fluxErreur == vrai (=> saisie invalide)


      // saut de ligne avant affichage du calendrier
      cout << endl;

      // formule de Keith simplifiée pour trouver le jour de la semaine du premier janvier de n'importe quelle année
      // [https://fr.wikibooks.org/wiki/Curiosit%C3%A9s_math%C3%A9matiques/
      // Trouver_le_jour_de_la_semaine_avec_une_date_donn%C3%A9e]
      int calculKeith = (23/9 + 4 + (anneeUtilisateur+1) + (anneeUtilisateur-1)/4 - (anneeUtilisateur-1)/100
                        + (anneeUtilisateur-1)/400) % 7;

      // corrige le problème du dimanche qui vaut 0 au lieu de 7
      int jourSemaine = calculKeith == 0 ? 7 : calculKeith;
      int nbreJours;

      // Affichage mois, de janvier à décembre
      for (int moisCourant = JANVIER; moisCourant <= DECEMBRE; ++moisCourant)
      {
         // Affiche le nom du mois courant grâce à un switch 1 - 12
         switch (moisCourant) {

            case JANVIER  :
               cout << "JANVIER "  ; break;

            case FEVRIER  :
               cout << "FEVRIER "  ; break;

            case MARS  :
               cout << "MARS "     ; break;

            case AVRIL  :
               cout << "AVRIL "    ; break;

            case MAI  :
               cout << "MAI "      ; break;

            case JUIN  :
               cout << "JUIN "     ; break;

            case JUILLET  :
               cout << "JUILLET "  ; break;

            case AOUT  :
               cout << "AOUT "     ; break;

            case SEPTEMBRE  :
               cout << "SEPTEMBRE "; break;

            case OCTOBRE :
               cout << "OCTOBRE "  ; break;

            case NOVEMBRE :
               cout << "NOVEMBRE " ; break;

            case DECEMBRE :
               cout << "DECEMBRE " ; break;
         }

         cout << anneeUtilisateur<< endl << "  L  M  M  J  V  S  D" << endl;

         // Test pour connaître le nombre de jour du mois courant
         if (moisCourant == FEVRIER)
         {
            // Cas année bissextile
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
         else
         {
            nbreJours = 31;
         }

         // Affichage jours
         for (int jour = 1; jour <= nbreJours; ++jour)
         {
            // Alignement pour le premier de chaque mois
            if (jour == 1)
            {
               cout << setw(W * jourSemaine) << jour;
            }
            else
            {
               cout << setw(W) << jour;
            }

            // Si c'est dimanche, recommence la semaine,
            // et saut de ligne seulement si ce n'est pas le dernier jour du mois
            if (jourSemaine == 7)
            {
               jourSemaine = 1;

               if (jour != nbreJours)
               {
                  cout << endl;
               }
            }
            else
            {
               ++jourSemaine;
            }
         }

         cout << endl << endl;
      }


      // boucle recommencer? gère erreurs de saisie
      do {

         fluxErreur = false;

         cout << "Voulez-vous recommencer [O/N] ? ";
         cin >> recommencer;

         if (recommencer != NON and recommencer != OUI or !cin.good())
         {
            fluxErreur = true;
            cout << "/!\\ recommencez" << endl;
            cin.clear();
         }
         EMPTY_BUFFER

      } while(fluxErreur);

   } while (recommencer == OUI);

   return EXIT_SUCCESS;
}