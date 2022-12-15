/*************************************************************************
        Trajet  -  trajet d'une ville de départ à une ville d'arrivée
                             -------------------
    début                : 15/12/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//-------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) --------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Liste.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char * Trajet::GetDepart ( ) const
// Algorithme :
//
{
    return depart;
} //----- Fin de Méthode

const char * Trajet::GetArrivee ( ) const
// Algorithme :
//
{
    return arrivee;
} //----- Fin de Méthode

const Trajet * Trajet::LireTrajet()
// Algorithme :
// 
{
    int choix;
    const Trajet * trajet = nullptr;
    while(trajet == nullptr)
    {
      cout << "Creation d'un trajet :" << endl;
      cout << "0: Trajet simple" << endl;
      cout << "1: Trajet compose de trajets simples" << endl;
      cin >> choix;
      switch (choix) {
        case 0:
          trajet = TrajetSimple::LireTrajetSimple();
          break;

        case 1:
          trajet = TrajetCompose::LireTrajetComposeSimple();
          break;

        default:
          cout << "Input non reconnue" << endl;
      }
    }

    return trajet;
} //----- Fin de Méthode

int Trajet::Compare ( const Trajet & trajet) const
// Algorithme :
//
{
    int tmp =strcmp(this->depart, trajet.depart);
    if(tmp != 0)
    {
        return tmp;
    }
    return strcmp(this->arrivee, trajet.arrivee);
} //----- Fin de Méthode

int Trajet::Compare ( const char * const depart, 
                      const char * const arrivee ) const
// Algorithme :
//
{
    int tmp =strcmp(this->depart, depart);
    if(tmp != 0)
    {
        return tmp;
    }
    return strcmp(this->arrivee, arrivee);
} //----- Fin de Méthode


int Trajet::CompareDepart ( const char * const depart ) const
// Algorithme :
//
{
    return strcmp(this->depart, depart);
} //----- Fin de Méthode

int Trajet::CompareArrivee ( const char * const arrivee ) const
// Algorithme :
//
{
    return strcmp(this->arrivee, arrivee);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const char * const depart, const char * const arrivee )
    : depart(depart), arrivee(arrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
