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
#include <typeinfo>

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

void Catalogue::ImporterTrajets ( const char * nomFichier, int typeTrajet, 
                                  const char * depart, const char * arrivee,
                                  int debut, int fin )
// Algorithme :
//
{
    ifstream stream;
    stream.open( nomFichier );

    if(!stream.fail())
    {
        char * tmp = new char[1000];
        int index = 1;

        while(!stream.eof())
        {
            stream.getline(tmp,1000,',');

            // Test si on est dans l'intervalle demandé
            if((debut<=index && index<=fin) || debut==-1)
            {
                // Test si TS ou TC demandés
                if(tmp[0]=='s' && (typeTrajet==ALL || typeTrajet==TS))
                {
                    const TrajetSimple * ts = TrajetSimple::ImporterTrajet(stream,depart,arrivee);
                    
                    if(ts != nullptr)
                    {
                    this->trajets->AjouterEnPlace(ts);
                    }
                
                }
                else if (tmp[0]=='c' && (typeTrajet==ALL || typeTrajet==TC)) 
                {
                    const TrajetCompose * tc = TrajetCompose::ImporterTrajet(stream,depart,arrivee);
                    
                    if(tc != nullptr)
                    {
                        this->trajets->AjouterEnPlace(tc);
                    }

                }
            }

            stream.getline(tmp,200);
            ++index;
        }

        delete(tmp);
    }
    else
    {
        cout << "Le fichier ne peut pas être ouvert !" << endl;
    }
} //----- Fin de ImporterTrajets

void Catalogue::ExporterTrajets ( const char * nomFichier, int typeTrajet, 
                                  const char * depart, const char * arrivee,
                                  int debut, int fin )
// Algorithme :
//
{
    ofstream stream;
    stream.open( nomFichier );

    if(!stream.fail())
    {
        Maillon * maillon = this->trajets->premier;
        char * tmp = new char[1000];
        int index = 1;
    
        while(maillon != nullptr)
        {
            // Test si on est dans l'intervalle demandé
            if((debut<=index && index<=fin) || debut==-1)
            {
                // Test si TS ou TC demandés
                if( typeid(*(maillon->GetTrajet()))==typeid(TrajetSimple)
                    && (typeTrajet==ALL || typeTrajet==TS) )
                {
                    maillon->GetTrajet()->ExporterTrajet(stream);
                    stream << "\r\n";
                }
                else if( typeid(*(maillon->GetTrajet()))==typeid(TrajetCompose)
                         && (typeTrajet==ALL || typeTrajet==TC) ) 
                {
                    maillon->GetTrajet()->ExporterTrajet(stream);
                    stream << "\r\n";
                }
            }

            maillon = maillon->GetSuivant();
        }

        delete(tmp);
    }
    else
    {
        cout << "Le fichier ne peut pas être ouvert !" << endl;
    }
} //----- Fin de ExporterTousTrajets

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
