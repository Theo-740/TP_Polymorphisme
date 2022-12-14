/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    static const TrajetCompose * LireTrajetCompose();
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
    //TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetCompose ( const char * const depart, const char * const arrivee, const Liste * const trajetsInternes );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const Liste * const trajetsInternes;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJET_COMPOSE_H
