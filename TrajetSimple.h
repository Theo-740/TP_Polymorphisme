/*************************************************************************
        TrajetSimple  -  trajet direct avec moyen de transport
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
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
    // Affiche le départ et l'arrivée du trajet et le moyen de transport
    // Contrat :
    //

    static const TrajetSimple * LireTrajetSimple();
    // Mode d'emploi :
    // Demande a l'utilisateur de rentrer les caractéristiques d'un 
    // trajet simple
    // Renvoie un objet trajet simple avec ces caractéristiques
    // Contrat :
    //

    virtual void ExporterTrajet ( ofstream & stream ) const;
    // Mode d'emploi :
    // Exporte un trajet dans un fichier
    // Contrat :
    //

    virtual Trajet * Clone ( ) const;
    // Mode d'emploi :
    // Renvoie une copie profonde du trajet
    // Contrat :
    //

    virtual Liste * GetListeTrajets ( ) const;
    // Mode d'emploi :
    // Renvoie une liste contenant une copie du trajet
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    
//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char * const depart, const char * const arrivee,
                   const char * const transport);
    // Mode d'emploi :
    // construit un trajet dont le départ, l'arrivée et le moyen de
    // transport sont ceux passé en paramètre
    // Contrat :
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // détruit le trajet, son départ, son arrivée ainsi que son moyen 
    // de transport
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const char * const transport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJET_SIMPLE_H
