/*************************************************************************
                Liste  -  liste simplement chainée de trajet
                             -------------------
    début                : 25/11/2022
    copyright            : (C) 2022 par Théo Gaigé et Elie Tarassov
    e-mail               : theo.gaige@insa-lyon.fr
                           elie.tarassov@insa-lyon.fr
*************************************************************************/

//----------- Interface de la classe <Liste> (fichier Liste.h) -----------
#if ! defined ( LISTE_H )
#define LISTE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Maillon;
class Trajet;

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
    // affiche les trajets contenu dans la liste sur plusieurs lignes
    // Si la liste est vide affiche "Il n'y a pas de trajets"
    // Contrat :
    //

    void AfficherEnLigne ( ) const;
    // Mode d'emploi :
    // Affiche les trajets contenu dans la liste sur une seule ligne 
    // entre accolades
    // Si la liste est vide affiche seulement les accolades
    // Contrat :
    //

    void AjouterEnFin ( const Trajet * trajet );
    // Mode d'emploi :
    // Ajoute le trajet a la fin de la liste
    // Contrat :
    //

    void AjouterEnPlace ( const Trajet * trajet );
    // Mode d'emploi :
    // Ajoute le trajet de telle manière que la liste reste triée selon 
    // le départ puis l'arrivée des trajets
    // Contrat :
    // La liste est déjà triée selon le départ puis l'arrivée des trajets

    void AjouterEnTete ( const Trajet * trajet );
    // Mode d'emploi :
    // Ajoute le trajet au début de la liste
    // Contrat :
    //

    const Liste * TrouverTrajet ( const char * const depart, 
                                  const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les trajets contenu dans la liste qui ont comme départ le 
    // départ spécifié et comme arrivée l'arrivée spécifiée
    // Contrat :
    //

    const Liste * TrouverTrajetAvance ( const char * const depart, 
                                       const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les compositions d'au moins deux trajets de la liste qui
    // vont du départ spécifié à l'arrivée spécifiée
    // Contrat :
    //

    void ExporterTousTrajets (ofstream & stream) const;
    // Mode d'emploi :
    // Exporte tous les trajets de la liste dans un fichier
    // Contrat :
    //

    Liste * Clone ( ) const;
    // Mode d'emploi :
    // Renvoie une copie non propriétaire de la liste
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Liste ( );
    // Mode d'emploi :
    // Construit une liste vide propriétaire de ses trajets
    // Contrat :
    //

    virtual ~Liste ( );
    // Mode d'emploi :
    // Détruit la liste et ses maillons, si la liste est propriétaire 
    // détruit aussi les trajets qu'elle contient
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Liste ( bool proprietaire );
    // Mode d'emploi :
    // Construit une liste vide, qui est propriétaire ou non en fonction
    // du paramêtre proprietaire
    // Contrat :
    //

    const Liste * RechercheRecursive ( const char * const depart, 
                                       const char * const arrivee ) const;
    // Mode d'emploi :
    // Renvoie les trajets et compositions de trajets de la liste qui vont
    // du départ spécifié à l'arrivée spécifiée
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
    Maillon * premier;
    Maillon * dernier;
    const bool proprietaire;
};

//------------------------------ Autres définitions dépendantes de <Liste>

#endif // LISTE_H
