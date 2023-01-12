using namespace std;

#include <iostream>
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main() 
{
    Catalogue c;
    char * fichier = "import.txt";

    c.ImporterTousTrajets(fichier);

    cout << "Affichage du catalogue :" << endl;
    c.Afficher();
}
