/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher ( ) const
// Algorithme :
//
{
    cout << "Trajet de " << depart << " à " << arrivee  << " composé de ";
    this->trajetsInternes->AfficherEnLigne();
} //----- Fin de Méthode

Liste * TrajetCompose::GetListeTrajets ( ) const
// Algorithme :
//
{
    return this->trajetsInternes->Clone();
} //----- Fin de Méthode

const TrajetCompose * TrajetCompose::LireTrajetCompose()
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
} //----- Fin de Méthode

Trajet * TrajetCompose::Clone ( ) const
// Algorithme :
//
{
  char * d = new char[51];
  strcpy(d, this->depart);
  char * a = new char[51];
  strcpy(a, this->arrivee);
  return new TrajetCompose(d, a, this->trajetsInternes->Clone());
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
//#endif
//} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( const char * const depart, const char * const arrivee, const Liste * const trajetsInternes )
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
