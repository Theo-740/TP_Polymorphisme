/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    static const TrajetSimple * LireTrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Trajet * Clone ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual Liste * GetListeTrajets ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetSimple ( const char * const depart, const char * const arrivee, const char * const transport);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const char * const transport;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H
