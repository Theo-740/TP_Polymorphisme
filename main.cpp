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

    // Options pour l'import et l'export de trajets
    char * nomFichier = new char[100];
    int typeTrajet;
    char * departOpt = new char[51];
    char * arriveeOpt = new char[51];
    int debut;
    int fin;
    int selection;

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
              cout << "Nom du fichier > ";
              cin >> nomFichier;

              cout << "Voulez-vous plus d'option d'importation ? " << endl;
              cout << "0: Oui / 1: Non" << endl;
              cin >> selection;

              // Options avec les valeurs par défaut
              typeTrajet = Catalogue::ALL;
              departOpt[0] = '\0';
              arriveeOpt[0] = '\0';
              debut = -1;
              fin = -1;

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
                  departOpt[0] = '\0';
                }
                else if(selection==1)
                {
                  cout << "Nom de la ville de départ > ";
                  cin >> departOpt;
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
                  arriveeOpt[0] = '\0';
                }
                else if(selection==1)
                {
                  cout << "Nom de la ville d'arrivée > ";
                  cin >> arriveeOpt;
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

              c.ImporterTrajets(nomFichier,typeTrajet,departOpt,arriveeOpt,debut,fin);
          }
          cout << endl;
          break;

        case 2:
          cout << "Nom du fichier > ";
          cin >> nomFichier;

          cout << "Voulez-vous plus d'option d'exportation ? " << endl;
          cout << "0: Oui / 1: Non" << endl;
          cin >> selection;

          // Options avec les valeurs par défaut
          typeTrajet = Catalogue::ALL;
          departOpt[0] = '\0';
          arriveeOpt[0] = '\0';
          debut = -1;
          fin = -1;

          if(!selection)
          {
            cout << "-- Options d'exportation --" << endl;
            cout << endl;

            // Choix du type de trajet à exporter
            cout << "0: Exporter tous types de trajets" << endl;
            cout << "1: Exporter seulement les trajets simples" << endl;
            cout << "2: Exporter seulement les trajets composés" << endl;
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

            // Choix du départ à exporter
            cout << "0: Exporter les trajets avec n'importe quel départ" << endl;
            cout << "1: Exporter les trajets avec un départ spécifique" << endl;
            cin >> selection;
            if(selection==0)
            {
              departOpt[0] = '\0';
            }
            else if(selection==1)
            {
              cout << "Nom de la ville de départ > ";
              cin >> departOpt;
            }
            else
            {
              cout << "Input non reconnu" << endl;
              break;
            }

            // Choix de l'arrivée à exporter
            cout << "0: Exporter les trajets avec n'importe quelle arrivée" << endl;
            cout << "1: Exporter les trajets avec une arrivée spécifique" << endl;
            cin >> selection;
            if(selection==0)
            {
              arriveeOpt[0] = '\0';
            }
            else if(selection==1)
            {
              cout << "Nom de la ville d'arrivée > ";
              cin >> arriveeOpt;
            }
            else
            {
              cout << "Input non reconnu" << endl;
              break;
            }

            // Choix d'une sélection de trajets à importer
            cout << "0: Exporter tous les trajets" << endl;
            cout << "1: Exporter une sélection de trajets" << endl;
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

          c.ExporterTrajets(nomFichier,typeTrajet,departOpt,arriveeOpt,debut,fin);
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

    delete(nomFichier);
    delete(departOpt);
    delete(arriveeOpt);
}
