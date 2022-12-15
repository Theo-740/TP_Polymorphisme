/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : 15/12/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr, elie.tarassov@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const Trajet * Maillon::GetTrajet ( ) const
// Algorithme :
//
{
    return trajet;
} //----- Fin de Méthode

Maillon * Maillon::GetSuivant ( ) const
// Algorithme :
//
{
    return suivant;
} //----- Fin de Méthode

void Maillon::SetSuivant ( Maillon * suivant)
// Algorithme :
//
{
    this->suivant = suivant;
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
//Maillon & Maillon::operator = ( const Maillon & unMaillon )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Maillon::Maillon ( const Maillon & unMaillon )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Maillon>" << endl;
//#endif
//} //----- Fin de Maillon (constructeur de copie)


Maillon::Maillon ( const Trajet * trajet, bool proprietaire )
    : trajet(trajet), suivant(nullptr), proprietaire(proprietaire)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
    delete this->suivant;
    if(this->proprietaire) {
        delete this->trajet;
    }
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
