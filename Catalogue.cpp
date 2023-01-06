/*************************************************************************
                Catalogue  -  Collection ordonnée de trajet
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Liste.h"
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher ( ) const
// Algorithme :
//
{
    trajets->Afficher();
} //----- Fin de Méthode

void Catalogue::Ajouter ( const Trajet * trajet )
// Algorithme :
//
{
    trajets->AjouterEnPlace(trajet);
} //----- Fin de Méthode

const Liste * Catalogue::TrouverTrajet (const char * const depart, 
                                        const char * const arrivee ) const
// Algorithme :
//
{
    return this->trajets->TrouverTrajet(depart, arrivee);
} //----- Fin de Méthode

const Liste * Catalogue::TrouverTrajetAvance ( const char * const depart, 
                                        const char * const arrivee ) const
// Algorithme :
//
{
    return this->trajets->TrouverTrajetAvance(depart, arrivee);
} //----- Fin de Méthode

bool Catalogue::AjouterToutFichier (const char * nomFichier) 

{
        ifstream in;
        in.open( nomFichier );
        if(in.fail()) {
            return false;
        }
        char * description = new char[1000];
        while(!in.eof()) {
            in.getline(description,1000);
            if(in.fail()) {
                return false;
            }
            if(description[0]=='s') {
                //Ajouter(new TrajetSimple(description));
            } else if (description[0]=='c') {
                //Ajouter(new TrajetCompose(description));
            } else {
                return false;
            }
        }
        return true;
}

bool Catalogue::AjouterTrajetsSimples (const char * nomFichier) 

{
        ifstream in;
        in.open( nomFichier );
        if(in.fail()) {
            return false;
        }
        char * description = new char[1000];
        while(!in.eof()) {
            in.getline(description,1000);
            if(in.fail()) {
                return false;
            }
            if(description[0]=='s') {
                //Ajouter(new TrajetSimple(description));
            } else if (description[0]!='c') {
                return false;
            }
        }
        return true;
}

bool Catalogue::AjouterTrajetsComposes (const char * nomFichier) 

{
        ifstream in;
        in.open( nomFichier );
        if(in.fail()) {
            return false;
        }
        char * description = new char[1000];
        while(!in.eof()) {
            in.getline(description,1000);
            if(in.fail()) {
                return false;
            }
            if(description[0]=='c') {
                //Ajouter(new TrajetCompose(description));
            } else if (description[0]!='s') {
                return false;
            }
        }
        return true;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( )
    : trajets(new Liste)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
