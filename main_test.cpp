using namespace std;

#include <iostream>
#include <cstring>
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main() 
{
    Catalogue c;
    char * importFile = "1_import.txt";
    char * exportFile = "2_export.txt";

    // Catalogue::ALL/TS/TC
    c.ImporterTrajets(importFile);

    cout << "Affichage du catalogue :" << endl;
    c.Afficher();

    c.ExporterTrajets(exportFile,Catalogue::TS);
}
