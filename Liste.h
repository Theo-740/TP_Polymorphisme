/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#if ! defined ( LISTE_H )
#define LISTE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Maillon;

//------------------------------------------------------------------------
// Rôle de la classe <Liste>
//
//
//------------------------------------------------------------------------

class Liste
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AfficherEnLigne ( ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterEnFin ( const Trajet * trajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterEnPlace ( const Trajet * trajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterEnTete ( const Trajet * trajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //void AjouterEnPlace ( const Liste * trajets );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Liste * TrouverTrajet ( const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Liste * TrouverTrajetAvance ( const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Liste * Clone ( ) const;

    bool EstVide ( ) const;

//------------------------------------------------- Surcharge d'opérateurs
    //Liste & operator = ( const Liste & unListe );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Liste ( const Liste & unListe );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Liste ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Liste ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Liste ( bool proprietaire );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Liste * RechercheRecursive ( const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    Maillon * premier;
    Maillon * dernier;
    const bool proprietaire;
};

//-------------------------------- Autres définitions dépendantes de <Liste>

#endif // LISTE_H
