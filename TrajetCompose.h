/*************************************************************************
        TrajetCompose  -  trajet compose d'un ou plusieurs trajets
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;
class Liste;
class Catalogue;

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
    // Afficher le départ et l'arrivée du trajet puis les trajets internes
    // Contrat :
    //

    static const TrajetCompose * LireTrajetComposeSimple();
    // Mode d'emploi :
    // Demande a l'utilisateur de rentrer les caractéristiques d'un 
    // trajet composé uniquement de trajets simple
    // Renvoie un objet trajet composé avec ces caractéristiques
    // Contrat :
    //

    static const TrajetCompose * ImporterTrajet ( ifstream & stream,
                                                  const char * selectDepart = "", 
                                                  const char * selectArrivee = "" );
    // Mode d'emploi :
    // Importe un trajet composé depuis un fichier
    // Il est possible de n'importer que les trajets qui ont une
    // certaine ville de départ ou d'arivée ou les deux
    // Contrat :
    //

    virtual int ExporterTrajet ( ofstream & stream,
                                 const char * selectDepart = "", 
                                 const char * selectArrivee = "" ) const;
    // Mode d'emploi :
    // Exporte un trajet composé dans un fichier
    // Il est possible de n'exporter que les trajets qui ont une
    // certaine ville de départ ou d'arivée ou les deux
    // Contrat :
    //

    virtual Trajet * Clone ( ) const;
    // Mode d'emploi :
    // Renvoie une copie du trajet composé
    // Contrat :
    //

    virtual Liste * GetListeTrajets ( ) const;
    // Mode d'emploi :
    // Renvoie une copie de la liste de trajets internes
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    
//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const char * const depart, const char * const arrivee,
                    const Liste * const trajetsInternes );
    // Mode d'emploi :
    // construit un trajet composé dont le depart, l'arrivée et les 
    // trajets internes sont ceux passés en paramètre
    // Contrat :
    // le depart passé en paramètre doit être le même que le départ
    // du premier trajet des trajets internes
    // l'arrivée passée en paramètre doit être la même que l'arrivée
    // du dernier trajet des trajets internes

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // détruit le trajet composé, son départ, son arrivée et 
    // ses trajets internes
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const Liste * const trajetsInternes;
};

//---------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJET_COMPOSE_H
