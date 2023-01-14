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

    void ImporterTrajets ( const char * nomFichier, int typeTrajet = 0, 
                           const char * depart = "", const char * arrivee = "",
                           int debut = -1, int fin = -1 );
    // Mode d'emploi :
    // Importe des trajets depuis un fichier suivant les paramètres
    // spécifiés par l'utilisateur
    // Contrat :
    //

    /*
    void ImporterTousTrajets ( const char * nomFichier );
    // Mode d'emploi :
    // Importe tous les trajets depuis un fichier
    // Contrat :
    //

    void ImporterTSimples ( const char * nomFichier );
    // Mode d'emploi :
    // Importe seulement les trajets simples depuis un fichier
    // Contrat :
    //

    void ImporterTComposes ( const char * nomFichier );
    // Mode d'emploi :
    // Importe seulement les trajets composés depuis un fichier
    // Contrat :
    //

    void ImporterSelection ( const char * nomFichier, int debut, int fin );
    // Mode d'emploi :
    // Importe seulement les trajets compris entre une position debut et fin
    // Le premier trajet présent dans le fichier est le trajet 1
    // Contrat :
    //
    */

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
