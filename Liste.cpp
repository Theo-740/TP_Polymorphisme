/*************************************************************************
                Liste  -  liste simplement chainée de trajet
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//--------- Réalisation de la classe <Liste> (fichier Liste.cpp) ---------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Maillon.h"
#include "Liste.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Liste::Afficher ( ) const
// Algorithme :
// 
{
    if(this->premier == nullptr)
    {
       cout << "Il n'y a pas de trajets" << endl;
    }
    else
    {
        Maillon * maillon = this->premier;

        while(maillon != nullptr)
        {
            maillon->GetTrajet()->Afficher();
            cout << endl;
            maillon = maillon->GetSuivant();
        }
    }
} //----- Fin de Méthode Afficher

void Liste::AfficherEnLigne ( ) const
// Algorithme :
//
{
    cout << "{";
    Maillon * maillon = this->premier;
    if(maillon != nullptr)
    {
    while(maillon->GetSuivant() != nullptr)
        {
            maillon->GetTrajet()->Afficher();
            cout << ", ";
            maillon = maillon->GetSuivant();
        }
        maillon->GetTrajet()->Afficher();
    }
    cout << "}";
} //----- Fin de Méthode AfficherEnLigne

void Liste::AjouterEnFin ( const Trajet * const trajet )
// Algorithme :
// Crée un maillon contenant le trajet, le maillon est propriétaire si et
// seulement si la liste l'est
// Ajoute ce maillon en tant que dernier maillon
{
    Maillon * newMaillon = new Maillon(trajet, this->proprietaire);

    if(this->dernier == nullptr)
    {
        this->dernier = newMaillon;
        this->premier = newMaillon;
    }
    else
    {
        this->dernier->SetSuivant(newMaillon);
        this->dernier = newMaillon;

    }
} //----- Fin de Méthode AjouterEnFin

void Liste::AjouterEnTete ( const Trajet * const trajet )
// Algorithme :
// Crée un maillon contenant le trajet, le maillon est propriétaire si et
// seulement si la liste l'est
// Ajoute ce maillon en tant que premier maillon
{
    Maillon * newMaillon = new Maillon(trajet, this->proprietaire);
    newMaillon->SetSuivant(this->premier);
    this->premier = newMaillon;
    if(this->dernier == nullptr) 
    {
        this->dernier = newMaillon;
    }
} //----- Fin de Méthode AjouterEnTete

void Liste::AjouterEnPlace ( const Trajet * const trajet )
// Algorithme :
// Crée un maillon contenant le trajet, le maillon est propriétaire si et 
// seulement si la liste l'est
// Si la liste est vide ajoute le maillon en tant que premier et dernier 
// maillon de la liste
// Si le premier trajet de la liste est plus grand dans l'ordre de trie
// que le trajet a ajouter le maillon en tête
// Sinon arcours les trajets dans l'ordre jusqu'à trouver un trajet plus 
// petit ou égal que le trajet a ajouter et insère le maillon a sa place
{
    Maillon * newMaillon = new Maillon(trajet, this->proprietaire);

    if(this->premier == nullptr)
    {
        this->premier = newMaillon;
    }
    else if(trajet->Compare(*this->premier->GetTrajet()) <= 0) 
    {
        newMaillon->SetSuivant(this->premier);
        this->premier = newMaillon;
    }
    else
    {
      Maillon * maillon = this->premier;
      while (maillon->GetSuivant() != nullptr 
          && trajet->Compare(*maillon->GetSuivant()->GetTrajet()) > 0)
      {
          maillon = maillon->GetSuivant();
      }
      newMaillon->SetSuivant(maillon->GetSuivant());
      maillon->SetSuivant(newMaillon);
    }
} //----- Fin de Méthode AjouterEnPlace

const Liste * Liste::TrouverTrajet (const char * const depart, 
                                    const char * const arrivee ) const
// Algorithme :
// Parcours tous les trajets de la liste
// si un trajet a le même départ et la même arrivée que ceux passés en 
// paramètre, ajoute ce trajet a la liste qui est renvoyée
{
    Liste * trajetsTrouve = new Liste(false);
    Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        int cmp = maillon->GetTrajet()->Compare(depart,arrivee);
        if(cmp == 0)
        {
            trajetsTrouve->AjouterEnPlace(maillon->GetTrajet());
        }
        else if(cmp > 0)
        {
          return trajetsTrouve;
        }

        maillon = maillon->GetSuivant();
    }
    return trajetsTrouve;
} //----- Fin de Méthode TrouverTrajet

const Liste * Liste::TrouverTrajetAvance (const char * const depart, 
                                        const char * const arrivee ) const
// Algorithme :
// crée une liste non propriétaire avec les trajets qui ne vont pas du 
// départ spécifié a l'arrivée spécifiée
// lance une recherche récursive sur la nouvelle liste
{
    Liste * TrajetsNonDirects = new Liste(false);

    const Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        if(maillon->GetTrajet()->Compare(depart, arrivee) != 0)
        {
            const Trajet * trajet = maillon->GetTrajet();
            TrajetsNonDirects->AjouterEnPlace(trajet);
        }
        maillon = maillon->GetSuivant();
    }
    const Liste * trajetsTrouves = 
                   TrajetsNonDirects->RechercheRecursive(depart, arrivee);
    delete TrajetsNonDirects;
    return trajetsTrouves;
} //----- Fin de Méthode TrouverTrajetAvance

void Liste::ImporterTousTrajets ( ifstream & stream )
// Algorithme :
//
{
    char * tmp = new char[1000];

    while(!stream.eof())
    {
        stream.getline(tmp,1000,',');

        if(tmp[0]=='s')
        {
            this->AjouterEnPlace(TrajetSimple::ImporterTrajet(stream));
        }
        else if (tmp[0]=='c') 
        {
            this->AjouterEnPlace(TrajetCompose::ImporterTrajet(stream));
        }

        stream.getline(tmp,200);
    }
} //----- Fin de ImporterTousTrajets

void Liste::ImporterTSimples ( ifstream & stream )
// Algorithme :
//
{
    char * tmp = new char[1000];

    while(!stream.eof())
    {
        stream.getline(tmp,1000,',');

        if(tmp[0]=='s')
        {
            this->AjouterEnPlace(TrajetSimple::ImporterTrajet(stream));
        }
        else if (tmp[0]=='c') 
        {
            stream.getline(tmp,1000,'}');
        }

        stream.getline(tmp,200);
    }
} //----- Fin de ImporterTSimples

void Liste::ImporterTComposes ( ifstream & stream )
// Algorithme :
//
{
    char * tmp = new char[1000];

    while(!stream.eof())
    {
        stream.getline(tmp,1000,',');

        if(tmp[0]=='s') 
        {
            stream.getline(tmp,1000,';');
        }
        else if (tmp[0]=='c') 
        {
            this->AjouterEnPlace(TrajetCompose::ImporterTrajet(stream));
        }

        stream.getline(tmp,200);
    }
} //----- Fin de ImporterTComposes

void Liste::ExporterTousTrajets (ofstream & stream) const
// Algorithme :
//
{
    Maillon * maillon = this->premier;
    
    while(maillon != nullptr)
    {
        maillon->GetTrajet()->ExporterTrajet(stream);
        maillon = maillon->GetSuivant();
        
        if(maillon != nullptr)
        {
            stream << ";";
        }
    }
} //----- Fin de Méthode ExporterTousTrajets

Liste * Liste::Clone ( ) const
// Algorithme :
// Crée une liste vide non propriétaire et la remplit avec les trajets
// contenus dans la liste originale
{
    Liste * liste = new Liste(false);
    const Maillon * maillon = this->premier;
    while(maillon != nullptr) 
    {
      liste->AjouterEnFin(maillon->GetTrajet());
      maillon = maillon->GetSuivant();
    }
    return liste;
} //----- Fin de Méthode Clone


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Liste::Liste ( )
    : premier(nullptr), dernier(nullptr), proprietaire(true)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
} //----- Fin de Liste


Liste::~Liste ( )
// Algorithme :
// si il le premier maillon existe le détruit
// en se detruisant chaque maillon détruit le maillon suivant
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
    if(this->premier != nullptr)
    {
        delete this->premier;
    }
} //----- Fin de ~Liste


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
Liste::Liste ( bool proprietaire )
    : premier(nullptr), dernier(nullptr), proprietaire(proprietaire)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Liste>" << endl;
#endif
} //----- Fin de Liste

const Liste * Liste::RechercheRecursive ( const char * const depart, 
                                        const char * const arrivee ) const
// Algorithme :
// Crée une liste contenant les trajets ayant comme départ le départ
// spécifié en paramètre et une autre liste contenant les autres trajets
// Pour chaque trajet ayant le bon départ : 
//      Si le trajet a la bonne arrivée, l'ajoute a liste renvoyée en 
//      l'encapsulant dans un trajet composé
//
//      Sinon lance une recherche recursive sur les trajets n'ayant pas 
//      le bon départ entre l'arrivée du trajet et l'arrivée en paramètre
//      et ajoute le trajet au début de chaque composition de trajet et 
//      les ajoute a la liste de retour
{
    Liste * PossiblesPremiersTrajets = new Liste(false);
    Liste * AutresTrajets = new Liste(false);

    const Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        const Trajet * trajet = maillon->GetTrajet();
        if(trajet->CompareDepart(depart) == 0)
        {
            PossiblesPremiersTrajets->AjouterEnFin(trajet);
        }
        else
        {
            AutresTrajets->AjouterEnPlace(trajet);
        }
        maillon = maillon->GetSuivant();
    }

    Liste * trajetsTrouves = new Liste;

    const Maillon * maillonTrajetDepart;
    maillonTrajetDepart = PossiblesPremiersTrajets->premier;
    while(maillonTrajetDepart != nullptr)
    {
        const Trajet * trajet = maillonTrajetDepart->GetTrajet();
        if(trajet->CompareArrivee(arrivee) == 0)
        {
            Liste * l = new Liste(false);
            l->AjouterEnTete(trajet);
            char * departTrajet = new char[51];
            strcpy(departTrajet, depart);
            char * arriveeTrajet = new char[51];
            strcpy(arriveeTrajet, arrivee);
            trajetsTrouves->AjouterEnFin(
                    new TrajetCompose(departTrajet, arriveeTrajet, l));
        }
        else
        {
            const Liste * trajetsSuivants = 
                   AutresTrajets->RechercheRecursive(trajet->GetArrivee(), 
                                                     arrivee);
            Maillon * maillonTrajetsSuivants = trajetsSuivants->premier;
            while(maillonTrajetsSuivants != nullptr)
            {
                Liste * l = 
                   maillonTrajetsSuivants->GetTrajet()->GetListeTrajets();
                l->AjouterEnTete(maillonTrajetDepart->GetTrajet());
                char * departTrajet = new char[51];
                strcpy(departTrajet, depart);
                char * arriveeTrajet = new char[51];
                strcpy(arriveeTrajet, arrivee);
                trajetsTrouves->AjouterEnFin(
                       new TrajetCompose(departTrajet, arriveeTrajet, l));
                maillonTrajetsSuivants = 
                                     maillonTrajetsSuivants->GetSuivant();
            }
            delete trajetsSuivants;
        }
        maillonTrajetDepart = maillonTrajetDepart->GetSuivant();
    }
    delete PossiblesPremiersTrajets;
    delete AutresTrajets;
    
    return trajetsTrouves;

} //----- Fin de Méthode RechercheRecursive
