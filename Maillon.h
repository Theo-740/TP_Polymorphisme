/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( MAILLON_H )
#define MAILLON_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
//
//
//------------------------------------------------------------------------

class Maillon
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const Trajet * GetTrajet ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Maillon * GetSuivant ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void SetSuivant ( Maillon * suivant );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Maillon & operator = ( const Maillon & unMaillon );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Maillon ( const Maillon & unMaillon );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Maillon ( const Trajet * trajet, bool proprietaire );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Maillon ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const Trajet * trajet;
    Maillon * suivant;
    const bool proprietaire;
};

//-------------------------------- Autres définitions dépendantes de <Maillon>

#endif // MAILLON_H
