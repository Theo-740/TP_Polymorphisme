/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "Maillon.h"
#include "Liste.h"
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
       cout << "vide" << endl;
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
} //----- Fin de Méthode

void Liste::AfficherEnLigne ( ) const
// Algorithme :
//
{
    cout << "{";
    Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        maillon->GetTrajet()->Afficher();
        cout << " ,";
        maillon = maillon->GetSuivant();
    }
    cout << "}";
} //----- Fin de Méthode

void Liste::AjouterEnFin ( const Trajet * const trajet )
// Algorithme :
//
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
} //----- Fin de Méthode

void Liste::AjouterEnTete ( const Trajet * const trajet )
// Algorithme :
//
{
    Maillon * newMaillon = new Maillon(trajet, this->proprietaire);
    newMaillon->SetSuivant(this->premier);
    this->premier = newMaillon;
    if(this->dernier == nullptr) {
        this->dernier = newMaillon;
    }
} //----- Fin de Méthode

void Liste::AjouterEnPlace ( const Trajet * const trajet )
// Algorithme :
//
{
    Maillon * newMaillon = new Maillon(trajet, this->proprietaire);

    if(this->premier == nullptr)
    {
        this->premier = newMaillon;
    }
    else if(trajet->Compare(*this->premier->GetTrajet()) <= 0) {
        newMaillon->SetSuivant(this->premier);
        this->premier = newMaillon;
    }
    else
    {
      Maillon * maillon = this->premier;
      while (maillon->GetSuivant() != nullptr && trajet->Compare(*maillon->GetSuivant()->GetTrajet()) > 0)
      {
          maillon = maillon->GetSuivant();
      }
      newMaillon->SetSuivant(maillon->GetSuivant());
      maillon->SetSuivant(newMaillon);
    }
} //----- Fin de Méthode

/*void Liste::AjouterEnPlace ( const Liste * const trajets )
// Algorithme :
//
{
    Maillon * maillon = trajets->premier;
    while(maillon != nullptr) {
        this->AjouterEnPlace(maillon->GetTrajet()->Clone());
        maillon = maillon->GetSuivant();
    }
} //----- Fin de Méthode*/

const Liste * Liste::TrouverTrajet (const char * const depart, const char * const arrivee ) const
// Algorithme :
//
{
    Liste * trajetsTrouve = new Liste(false);
    Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        int cmp = maillon->GetTrajet()->Compare(depart,arrivee);
        if(cmp == 0){
            trajetsTrouve->AjouterEnPlace(maillon->GetTrajet());
        }
        else if(cmp > 0){
          return trajetsTrouve;
        }

        maillon = maillon->GetSuivant();
    }
    return trajetsTrouve;
} //----- Fin de Méthode

const Liste * Liste::TrouverTrajetAvance (const char * const depart, const char * const arrivee ) const
// Algorithme :
//
{
    Liste * TrajetsNonDirects = new Liste(false);

    const Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        if(maillon->GetTrajet()->Compare(depart, arrivee) != 0){
            const Trajet * trajet = maillon->GetTrajet();
            TrajetsNonDirects->AjouterEnPlace(trajet);
        }
        maillon = maillon->GetSuivant();
    }
    const Liste * trajetsTrouves = TrajetsNonDirects->RechercheRecursive(depart, arrivee);
    delete TrajetsNonDirects;
    return trajetsTrouves;
} //----- Fin de Méthode

Liste * Liste::Clone ( ) const
// Algorithme :
//
{
    Liste * liste = new Liste(false);
    const Maillon * maillon = this->premier;
    while(maillon != nullptr) {
      liste->AjouterEnFin(maillon->GetTrajet());
      maillon = maillon->GetSuivant();
    }
    return liste;
} //----- Fin de Méthode

bool Liste::EstVide ( ) const
// Algorithme :
//
{
    return this->premier == nullptr;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Liste & Liste::operator = ( const Liste & unListe )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//Liste::Liste ( const Liste & uneListe )
// Algorithme :
//
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <Liste>" << endl;
//#endif
//} //----- Fin de Liste (constructeur de copie)


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
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Liste>" << endl;
#endif
    delete this->premier;
    /*while (this->premier != nullptr)
    {
      Maillon * tmp = this->premier->GetSuivant();
      delete this->premier->trajet;
      delete this->premier;
      this->premier = tmp;
    }*/
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

const Liste * Liste::RechercheRecursive (const char * const depart, const char * const arrivee ) const
// Algorithme :
//
{
    Liste * PossiblesPremiersTrajets = new Liste(false);
    Liste * AutresTrajets = new Liste(false);

    const Maillon * maillon = this->premier;

    while(maillon != nullptr)
    {
        const Trajet * trajet = maillon->GetTrajet();
        if(trajet->CompareDepart(depart) == 0){
            PossiblesPremiersTrajets->AjouterEnFin(trajet);
        }
        else
        {
            AutresTrajets->AjouterEnPlace(trajet);
        }
        maillon = maillon->GetSuivant();
    }

    Liste * trajetsTrouves = new Liste;

    const Maillon * maillonTrajetDepart = PossiblesPremiersTrajets->premier;
    while(maillonTrajetDepart != nullptr) {
        const Trajet * trajet = maillonTrajetDepart->GetTrajet();
        if(trajet->CompareArrivee(arrivee) == 0){
            Liste * l = new Liste(false);
            l->AjouterEnTete(trajet);
            char * departTrajet = new char[51];
            strcpy(departTrajet, depart);
            char * arriveeTrajet = new char[51];
            strcpy(arriveeTrajet, arrivee);
            trajetsTrouves->AjouterEnFin(new TrajetCompose(departTrajet, arriveeTrajet, l));
        }
        else
        {
            const Liste * trajetsSuivants = AutresTrajets->RechercheRecursive(trajet->GetArrivee(), arrivee);
            Maillon * maillonTrajetsSuivants = trajetsSuivants->premier;
            while(maillonTrajetsSuivants != nullptr) {
                Liste * l = maillonTrajetsSuivants->GetTrajet()->GetListeTrajets();
                l->AjouterEnTete(maillonTrajetDepart->GetTrajet());
                char * departTrajet = new char[51];
                strcpy(departTrajet, depart);
                char * arriveeTrajet = new char[51];
                strcpy(arriveeTrajet, arrivee);
                trajetsTrouves->AjouterEnFin(new TrajetCompose(departTrajet, arriveeTrajet, l));
                maillonTrajetsSuivants = maillonTrajetsSuivants->GetSuivant();
            }
            delete trajetsSuivants;
        }
        maillonTrajetDepart = maillonTrajetDepart->GetSuivant();
    }
    delete PossiblesPremiersTrajets;
    delete AutresTrajets;
    
    return trajetsTrouves;

} //----- Fin de Méthode
