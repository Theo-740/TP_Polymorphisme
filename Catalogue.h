/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter ( const Trajet * trajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Liste * TrouverTrajet (const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Liste * TrouverTrajetAvance (const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Liste * const trajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
