/*************************************************************************
                Catalogue  -  Collection ordonnée de trajet
                             -------------------
    début                : 15/12/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr, elie.tarassov@insa-lyon.fr
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
    // Affiche les trajets contenus dans le catalogue
    // Contrat :
    //

    void Ajouter ( const Trajet * trajet );
    // Mode d'emploi :
    // Ajouter un trajet au catalogue au bon endroit pour que le catalogue reste trié
    // Contrat :
    //

    const Liste * TrouverTrajet (const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les trajets contenus dans le catalogue qui ont comme départ le départ spécifié et comme arrivée l'arrivée spécifiée
    // Contrat :
    //

    const Liste * TrouverTrajetAvance (const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les compositions d'au moins deux trajets du catalogue qui vont du départ spécifié à l'arrivée spécifiée
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( );
    // Mode d'emploi :
    // Construit un catalogue vide
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Détruit le catalogue, la liste et les trajets associés
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
