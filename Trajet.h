/*************************************************************************
        Trajet  -  trajet d'une ville de départ à une ville d'arrivée
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
    // Renvoie un pointeur const sur le départ du trajet
    // Contrat :
    //

    const char * GetArrivee ( ) const;
    // Mode d'emploi :
    // Renvoie un pointeur const sur l'arrivée du trajet
    // Contrat :
    //

    virtual Liste * GetListeTrajets ( ) const = 0;
    // Mode d'emploi :
    // Renvoie une liste contenant les trajets composant le trajets
    // Contrat :
    //

    virtual void Afficher ( ) const = 0;
    // Mode d'emploi :
    // Affiche les informations du trajet
    // Contrat :
    //

    static const Trajet * LireTrajet();
    // Mode d'emploi :
    // Demande a l'utilisateur de rentrer les caractéristiques d'un trajet
    // Renvoie un objet trajet avec ces caractéristiques
    // Contrat :
    //

    int Compare ( const Trajet & trajet) const;
    // Mode d'emploi :
    // Renvoie 0 si le départ et l'arrivée du trajet sont les mêmes que le départ et l'arrivée du trajet passé en paramètre
    // Renvoie un entier positif si le trajet est plus grand que le trajet passé en paramètre dans l'ordre alphabétique du départ puis de l'arrivée
    // Renvoie un entier négatif si le trajet est plus petit que le trajet passé en paramètre dans l'ordre alphabétique du départ puis de l'arrivée
    // Contrat :
    //

    int Compare ( const char * const depart, const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie 0 si le départ et l'arrivée du trajet sont les mêmes que le départ et l'arrivée passés en paramètre
    // Renvoie un entier positif si le trajet est plus grand que le départ et l'arrivée passés en paramètre dans l'ordre alphabétique du départ puis de l'arrivée
    // Renvoie un entier négatif si le trajet est plus petit que le départ et l'arrivée passés en paramètre dans l'ordre alphabétique du départ puis de l'arrivée
    // Contrat :
    //

    int CompareDepart ( const char * const depart ) const;
    // Mode d'emploi :
    // Renvoie 0 si le départ du trajet est le même que le départ passé en paramètre
    // Renvoie un entier positif si le départ du trajet est plus grand que le départ passé en paramètre dans l'ordre alphabétique
    // Renvoie un entier négatif si le départ du trajet est plus petit que le départ passé en paramètre dans l'ordre alphabétique
    // Contrat :
    //

    int CompareArrivee ( const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie 0 si l'arrivée du trajet est le même que l'arrivée passé en paramètre
    // Renvoie un entier positif si l'arrivée du trajet est plus grande que l'arrivée passé en paramètre dans l'ordre alphabétique
    // Renvoie un entier négatif si l'arrivée du trajet est plus petite que l'arrivée passé en paramètre dans l'ordre alphabétique
    // Contrat :
    //
    virtual Trajet * Clone ( ) const = 0;
    // Mode d'emploi :
    // Renvoie une copie profonde du trajet
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const char * const depart, const char * const arrivee);
    // Mode d'emploi :
    // construit un trajet dont le départ et l'arrivée sont le départ et l'arrivée passés en paramètre
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Détruit le trajet, son départ et son arrivée
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
