/*************************************************************************
                Catalogue  -  Collection ordonnée de trajet
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Catalogue> (fichier Catalogue.h) -------
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
    enum TypeTrajet { ALL, TS, TC };

//----------------------------------------------------- Méthodes publiques
    void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche les trajets contenus dans le catalogue
    // Contrat :
    //

    void Ajouter ( const Trajet * trajet );
    // Mode d'emploi :
    // Ajouter un trajet au catalogue au bon endroit pour que le catalogue
    // reste trié
    // Contrat :
    //

    const Liste * TrouverTrajet ( const char * const depart, 
                                  const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les trajets contenus dans le catalogue qui ont comme départ
    // le départ spécifié et comme arrivée l'arrivée spécifiée
    // Contrat :
    //

    const Liste * TrouverTrajetAvance ( const char * const depart, 
                                        const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les compositions d'au moins deux trajets du catalogue qui 
    // vont du départ spécifié à l'arrivée spécifiée
    // Contrat :
    //

    void ImporterTrajets ( const char * nomFichier, int typeTrajet = Catalogue::ALL, 
                           const char * depart = "", const char * arrivee = "",
                           int debut = -1, int fin = -1 );
    // Mode d'emploi :
    // Importe des trajets depuis un fichier suivant les paramètres
    // spécifiés par l'utilisateur
    // Contrat :
    //

    void ExporterTrajets ( const char * nomFichier, int typeTrajet = Catalogue::ALL, 
                           const char * depart = "", const char * arrivee = "",
                           int debut = -1, int fin = -1 );
    // Mode d'emploi :
    // Exporte des trajets dans un fichier suivant les paramètres
    // spécifiés par l'utilisateur
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

//-------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
