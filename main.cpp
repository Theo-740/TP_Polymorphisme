using namespace std;

#include <iostream>
#include <fstream>
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
    ofstream stream;
    do
    {
      cout << "Menu :" << endl;
      cout << "0: Afficher les trajets" << endl;
      cout << "1: Ajouter un trajet" << endl;
      cout << "2: Importer des trajets" << endl;
      cout << "3: Sauvegarder des trajets" << endl;
      cout << "4: Rechercher un trajet" << endl;
      cout << "5: Quitter" << endl;
      cin >> choix;
      switch (choix)
      {
        case 0:
          c.Afficher();
          break;

        case 1:
          c.Ajouter(Trajet::LireTrajet());
          break;

        case 2:
          
          stream.open("test.txt");
          //c.trajets->ExporterTousTrajets(stream);
          stream.close();
          break;

        case 4:
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
          break;

        case 5:
          break;

        default:
          cout << "Input non reconnue" << endl;
      }
    }
    while(choix != 5);
}
