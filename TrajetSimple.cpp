/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Liste.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher ( ) const
// Algorithme :
//
{
    cout << "Trajet de " << depart << " à " << arrivee << " en " << transport;
} //----- Fin de Méthode

const TrajetSimple * TrajetSimple::LireTrajetSimple()
// Algorithme :
//
{
  cout << "Creation d'un trajet simple :" << endl;
  char * depart = new char[51];
  char * arrivee = new char[51];
  char * transport = new char[51];
  cout << "Ville de départ :";
  cin >> depart;
  cout << "Mode de transport :";
  cin >> transport;
  cout << "Ville d'arrivée :";
  cin >> arrivee;
  return new TrajetSimple(depart, arrivee, transport);
} //----- Fin de Méthode

Liste * TrajetSimple::GetListeTrajets ( ) const
// Algorithme :
//
{
    Liste * l = new Liste;
    l->AjouterEnTete(this->Clone());
    return l;
} //----- Fin de Méthode

Trajet * TrajetSimple::Clone ( ) const
// Algorithme :
//
{
    char * d = new char[51];
    strcpy(d, this->depart);
    char * a = new char[51];
    strcpy(a, this->arrivee);
    char * t = new char[51];
    strcpy(t, this->transport);
    return new TrajetSimple(d, a, t);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
//#endif
//} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( const char * const depart, const char * const arrivee, const char * const transport )
    : Trajet(depart, arrivee), transport(transport)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
