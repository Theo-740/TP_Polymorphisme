/*************************************************************************
        TrajetCompose  -  trajet compose d'un ou plusieurs trajets
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
#include "Liste.h"
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ( ) const
// Algorithme :
//
{
    cout << "Trajet de " << depart << " à " << arrivee  << " composé de ";
    this->trajetsInternes->AfficherEnLigne();
} //----- Fin de Afficher

Liste * TrajetCompose::GetListeTrajets ( ) const
// Algorithme :
//
{
    return this->trajetsInternes->Clone();
} //----- Fin de GetListeTrajets

const TrajetCompose * TrajetCompose::LireTrajetComposeSimple()
// Algorithme :
//
{
  cout << "Creation d'un trajet composé de trajets simples :" << endl;
  Liste * trajets = new Liste;
  char * depart = new char[51];
  cout << "Ville de depart :";
  cin >> depart;
  char * etape = new char[51];
  strcpy(etape, depart);
  char * suivant, * transport;
  int choix = 0;
  do
  {
    switch (choix) {
      case 0:
      transport = new char[51];
      cout << "Mode de transport :";
      cin >> transport;
      suivant = new char[51];
      cout << "Ville suivante :";
      cin >> suivant;
      trajets->AjouterEnFin(new TrajetSimple(etape, suivant, transport));
      etape = new char[51];
      strcpy(etape, suivant);
      break;

      default:
        cout << "Input non reconnue" << endl;
    }
    cout << "0: Continuer" << endl;
    cout << "1: Fin du trajet" << endl;
    cin >> choix;
  }
  while (choix != 1);

  return new TrajetCompose(depart, etape, trajets);
} //----- Fin de LireTrajetComposeSimple

const TrajetCompose * TrajetCompose::ImporterTrajet ( ifstream & stream,
                                                      const char * selectDepart, 
                                                      const char * selectArrivee )
// Algorithme :
//
{
    char * depart = new char[51];
    char * arrivee = new char[51];
    Liste * trajets = new Liste;

    char * tmp = new char[200];
    int tCompose = 0;

    stream.getline(depart,51,',');
    stream.getline(arrivee,51,',');

    // Test si les départ et arrivés sont bien conformes aux choix de
    // l'utilisateur
    if( ((strcmp(depart,selectDepart)!=0 && strcmp(selectDepart,"")!=0))
     || ((strcmp(arrivee,selectArrivee)!=0 && strcmp(selectArrivee,"")!=0)) )
    {
        TrajetCompose * fail = nullptr;
        cout << "fail" << endl;
        return fail;
    }

    stream.getline(tmp,51,'{');

    while( (stream.peek()!='}' && tCompose!=1)
        || (stream.peek()=='}' && tCompose==1) )
    {
        if((stream.peek()=='}' && tCompose==1))
        {
            stream.getline(tmp,200,'}');
        }

        stream.getline(tmp,200,',');

        if(tmp[0]=='s')
        {
            trajets->AjouterEnPlace(
                TrajetSimple::ImporterTrajet(stream)
            );
            tCompose = 0;
        }
        else if (tmp[0]=='c')
        {
            trajets->AjouterEnPlace(
                TrajetCompose::ImporterTrajet(stream)
            );
            tCompose = 1;
        }
    }

    delete(tmp);
    
    return new TrajetCompose(depart, arrivee, trajets);
} //----- Fin de ImporterTrajet

int TrajetCompose::ExporterTrajet ( ofstream & stream,
                                     const char * selectDepart, 
                                     const char * selectArrivee ) const
// Algorithme :
//
{
    // Test si les départ et arrivés sont bien conformes aux choix de
    // l'utilisateur
    if( (strcmp(this->depart,selectDepart)!=0 && strcmp(selectDepart,"")!=0)
     || (strcmp(this->arrivee,selectArrivee)!=0 && strcmp(selectArrivee,"")!=0) )
    {
        return Catalogue::FAIL;
    }


    stream << "c," << this->depart << "," << this->arrivee << ",{";

    // Exporter les trajets qui composent ce trajet composé
    Maillon * maillon = this->trajetsInternes->premier;
    
    while(maillon != nullptr)
    {
        maillon->GetTrajet()->ExporterTrajet(stream);
        maillon = maillon->GetSuivant();
    }

    stream << "}";

    return Catalogue::OK;
} //----- Fin de ExporterTrajet

Trajet * TrajetCompose::Clone ( ) const
// Algorithme :
//
{
  char * d = new char[51];
  strcpy(d, this->depart);
  char * a = new char[51];
  strcpy(a, this->arrivee);
  return new TrajetCompose(d, a, this->trajetsInternes->Clone());
} //----- Fin de Clone

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const char * const depart, 
                               const char * const arrivee, 
                               const Liste * const trajetsInternes )
    : Trajet(depart, arrivee), trajetsInternes(trajetsInternes)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete trajetsInternes;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
