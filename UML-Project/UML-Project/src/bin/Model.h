/*************************************************************************
                        Model  -  Manipule le Model
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Interface de la classe <Model> (fichier Model.h) ----------------
#if ! defined ( MODEL_H )
#define MODEL_H

//--------------------------------------------------- Interfaces utilisées

//---------------------------------------------------Includes système
#include <vector>
//---------------------------------------------------Includes personnels
using namespace std; 
#include "Gouvernement.cpp"
#include "Particulier.cpp"
#include "Capteur.cpp"
#include "Cleaner.cpp"
#include "Fournisseur.cpp"
#include "View.cpp"
#include "Controller.cpp"


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Model>
//
//
//------------------------------------------------------------------------

class Model
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    View getVue() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet View associé au modèle.

    Controller getController() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet Controller associé au modèle.

    Gouvernement getGouvernement() const;
    // Mode d'emploi :
    // Cette méthode retourne l'objet Gouvernement associé au modèle.

    vector<Particulier> getListeParticuliers() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Particulier associés au modèle.

    vector<Capteur> getListeCapteurs() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Capteur associés au modèle.

    vector<Cleaner> getListeCleaners() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Cleaner associés au modèle.

    vector<Fournisseur> getListeFournisseurs() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Fournisseur associés au modèle.



//-------------------------------------------- Constructeurs - destructeur

    Model ( View vue, Controller controller, Gouvernement gouv,  vector<Particulier> listeParticuliers, vector<Capteur> listeCapteurs, vector<Cleaner> listeCleaners, vector<Fournisseur> listeFournisseurs );
    // Mode d'emploi : constructeur par défaut de Model
    //
    // Contrat :

    virtual ~Model ( );
    // Mode d'emploi :
    //
    // Contrat :
  
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
View vue;
Controller controller;
Gouvernement gouv;
vector<Particulier> listeParticuliers;
vector<Capteur> listeCapteurs;
vector<Cleaner> listeCleaners;
vector<Fournisseur> listeFournisseurs
};

#endif // Model_H
