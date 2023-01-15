/*************************************************************************
        TrajetSimple  -  trajet direct avec moyen de transport
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
#include "Liste.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher ( ) const
// Algorithme :
//
{
    cout << "Trajet de " << depart << " à " << arrivee 
         << " en " << transport;
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

const TrajetSimple * TrajetSimple::ImporterTrajet ( ifstream & stream, 
                                                    const char * selectDepart, 
                                                    const char * selectArrivee )
// Algorithme :
//
{
    char * depart = new char[51];
    char * arrivee = new char[51];
    char * transport = new char[51];

    stream.getline(depart,51,',');
    stream.getline(arrivee,51,',');
    stream.getline(transport,51,';');

    if( (strcmp(depart,selectDepart)!=0 && strcmp(selectDepart,"")!=0)
     || (strcmp(arrivee,selectArrivee)!=0 && strcmp(selectArrivee,"")!=0) )
    {
        TrajetSimple * fail = nullptr;
        cout << "fail" << endl;
        return fail;
    }

    return new TrajetSimple(depart, arrivee, transport);
} //----- Fin de ImporterTrajet

int TrajetSimple::ExporterTrajet ( ofstream & stream,
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


    stream << "s,";
    stream << this->depart << "," << this->arrivee << "," << this->transport;
    stream << ";";

    return Catalogue::OK;
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

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const char * const depart, 
                             const char * const arrivee, 
                             const char * const transport )
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
