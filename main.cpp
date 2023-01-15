using namespace std;

#include <iostream>
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main() 
{
    int choix;
    Catalogue c;
    char * depart, * arrivee;
    const Liste * trajetsTrouves;
    do
    {
      cout << "Menu :" << endl;
      cout << "0: Afficher les trajets" << endl;
      cout << "1: Ajouter un/des trajet(s)" << endl;
      cout << "2: Exporter un/des trajet(s)" << endl;
      cout << "3: Rechercher un trajet" << endl;
      cout << "4: Quitter" << endl;
      cin >> choix;
      switch (choix)
      {
        case 0:
          c.Afficher();
          cout << endl;
          break;

        case 1:
          int import;

          cout << "0: Manuellement" << endl;
          cout << "1: Depuis un fichier" << endl;
          cin >> import;

          switch (import)
          {
            case 0:
              c.Ajouter(Trajet::LireTrajet());
              break;

            case 1:
              char * nomFichier = new char[100];
              cout << "Nom du fichier > ";
              cin >> nomFichier;

              int selection;
              cout << "Voulez-vous plus d'option d'importation ? " << endl;
              cout << "0: Oui / 1: Non" << endl;
              cin >> selection;

              // Options avec les valeurs par défaut
              int typeTrajet = Catalogue::ALL;
              char * departImp = new char[51];
              departImp[0] = '\0';
              char * arriveeImp = new char[51];
              arriveeImp[0] = '\0';
              int debut = -1;
              int fin = -1;

              if(!selection)
              {
                cout << "-- Options d'importation --" << endl;
                cout << endl;

                // Choix du type de trajet à importer
                cout << "0: Importer tous types de trajets" << endl;
                cout << "1: Importer seulement les trajets simples" << endl;
                cout << "2: Importer seulement les trajets composés" << endl;
                cin >> selection;
                if(selection==0)
                {
                  typeTrajet = Catalogue::ALL;
                }
                else if(selection==1)
                {
                  typeTrajet = Catalogue::TS;
                }
                else if(selection==2)
                {
                  typeTrajet = Catalogue::TC;
                }
                else
                {
                  cout << "Input non reconnu" << endl;
                  break;
                }

                // Choix du départ à importer
                cout << "0: Importer les trajets avec n'importe quel départ" << endl;
                cout << "1: Importer les trajets avec un départ spécifique" << endl;
                cin >> selection;
                if(selection==0)
                {
                  departImp[0] = '\0';
                }
                else if(selection==1)
                {
                  cout << "Nom de la ville de départ > ";
                  cin >> departImp;
                }
                else
                {
                  cout << "Input non reconnu" << endl;
                  break;
                }

                // Choix de l'arrivée à importer
                cout << "0: Importer les trajets avec n'importe quelle arrivée" << endl;
                cout << "1: Importer les trajets avec une arrivée spécifique" << endl;
                cin >> selection;
                if(selection==0)
                {
                  arriveeImp[0] = '\0';
                }
                else if(selection==1)
                {
                  cout << "Nom de la ville d'arrivée > ";
                  cin >> arriveeImp;
                }
                else
                {
                  cout << "Input non reconnu" << endl;
                  break;
                }

                // Choix d'une sélection de trajets à importer
                cout << "0: Importer tous les trajets" << endl;
                cout << "1: Importer une sélection de trajets" << endl;
                cin >> selection;
                if(selection==0)
                {
                  debut = -1;
                  fin = -1;
                }
                else if(selection==1)
                {
                  cout << "Début de sélection (supérieur ou égal à 1) > ";
                  cin >> debut;
                  cout << "Fin de sélection (supérieur au début) > ";
                  cin >> fin;
                }
                else
                {
                  cout << "Input non reconnu" << endl;
                  break;
                }
              }

              c.ImporterTrajets(nomFichier,typeTrajet,departImp,arriveeImp,debut,fin);
              delete(nomFichier);
              delete(departImp);
              delete(arriveeImp);
          }
          cout << endl;
          break;

        case 2:
          c.Ajouter(Trajet::LireTrajet());
          cout << endl;
          break;

        case 3:
          cout << "Rechercher un trajet :" << endl;
          depart = new char[51];
          arrivee = new char[51];
          cout << "Ville de depart :";
          cin >> depart;
          cout << "Ville d'arrivee :";
          cin >> arrivee;
          cout << "recherche simple :" << endl;
          trajetsTrouves = c.TrouverTrajet(depart, arrivee);
          trajetsTrouves->Afficher();
          delete trajetsTrouves;
          cout << "recherche avancée :" << endl;
          trajetsTrouves = c.TrouverTrajetAvance(depart, arrivee);
          trajetsTrouves->Afficher();
          delete trajetsTrouves;

          delete[] depart;
          delete[] arrivee;
          cout << endl;
          break;

        case 4:
          break;

        default:
          cout << "Input non reconnu" << endl;
          cout << endl;
      }
    }
    while(choix != 4);
}
