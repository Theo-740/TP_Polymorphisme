/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 15/12/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr, elie.tarassov@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Liste;

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const char * GetDepart ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const char * GetArrivee ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Liste * GetListeTrajets ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Afficher ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    static const Trajet * LireTrajet();
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Compare ( const Trajet & trajet) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Compare ( const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int CompareDepart ( const char * const depart ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int CompareArrivee ( const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Trajet * Clone ( ) const = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( const char * const depart, const char * const arrivee);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const char * const depart;
    const char * const arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
