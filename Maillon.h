/*************************************************************************
        Maillon  -  maillon d'une liste de trajet simplement chaînée
                             -------------------
    début                : 15/12/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <Maillon> (fichier Maillon.h) ---------
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
    // renvoie un pointeur const sur le trajet contenu dans le maillon
    // Contrat :
    //

    Maillon * GetSuivant ( ) const;
    // Mode d'emploi :
    // renvoie un pointeur sur le prochain maillon de la chaîne s'il 
    // existe, renvoie nullptr sinon
    // Contrat :
    //

    void SetSuivant ( Maillon * suivant );
    // Mode d'emploi :
    // remplace le maillon suivant actuel par le maillon suivant passé
    // en paramètre
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Maillon ( const Trajet * trajet, bool proprietaire );
    // Mode d'emploi :
    // crée un nouveau maillon contenant le trajet passé en paramètre
    // Contrat :
    // 

    virtual ~Maillon ( );
    // Mode d'emploi :
    // detruit le maillon et les maillons suivants, si le maillon est 
    // propriétaire détruit également le trajet contenu
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

//---------------------------- Autres définitions dépendantes de <Maillon>

#endif // MAILLON_H
