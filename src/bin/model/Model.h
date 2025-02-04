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
#include <algorithm>
#include <cmath>
//---------------------------------------------------Includes personnels
using namespace std; 

#include "Gouvernement.h"
#include "Particulier.h"
#include "Capteur.h"
#include "Cleaner.h"
#include "Fournisseur.h"
#include "Mesure.h"

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Model>
//
//
//------------------------------------------------------------------------

struct Data {
        vector<Capteur> capteurs_defaillants;
        vector<Capteur> capteurs_potentiels;
        vector<double> ratio_capt_potentiels;
};

class Model
{ 
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void setGouvernement(const Gouvernement & gouvernement);
    void setListeParticuliers(const vector<Particulier> & liste);
    void setListeCapteurs(const vector<Capteur> & liste);
    void setListeCleaners(const vector<Cleaner> & liste);
    void setListeFournisseurs(const vector<Fournisseur> & liste);
    void setListeMesures(const vector<Mesure> & liste);

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

    vector<Mesure> getListeMesures() const;
    // Mode d'emploi :
    // Cette méthode retourne la liste des objets Mesure associés au modèle.

    vector<Capteur> get_liste_capteurs_fiables();
    // Mode d'emploi :
    // Cette méthode retourne la liste des capteurs fiables.

    vector<Capteur> get_liste_capteurs_date(time_t date);
    // Mode d'emploi :
    // Cette méthode retourne la liste des capteurs qui possèdent des mesures à une date donnée.

    double trouver_distance(double lat1, double lon1, double lat2, double lon2);
    // Mode d'emploi :
    // Cette méthode retourne la distance entre deux points géographiques.

    double getValeurDateType(Capteur capteur, time_t date, string type);
    // Mode d'emploi :
    // Cette méthode retourne la valeur d'un type de mesure à une date donnée pour un capteur donné.

    string calculer_indice_ATMO(double val_O3, double val_SO2, double val_NO2, double val_PM10);
    // Mode d'emploi :
    // Cette méthode retourne l'indice ATMO à partir des valeurs de O3, SO2, NO2 et PM10.
    
    vector<double> getIndiceATMO(double latitude, double longitude, time_t date, int rayon);
    // Mode d'emploi :
    // Cette méthode retourne l'indice ATMO à une date donnée pour une zone donnée.

    string getAirQuality(double latitude, double longitude, time_t date_debut, time_t date_fin, int rayon);
    // Mode d'emploi :
    // Cette méthode retourne la qualité de l'air pour une zone donnée et une période donnée.

    vector<double> getMoyenneMesures(Capteur capteur);
    // Mode d'emploi :
    // Cette méthode retourne la moyenne des mesures d'un capteur.

    Data trouverCapteursDefaillants(double marge_erreur, double distance, double ratio_incoherence);
    // Mode d'emploi :
    // Cette méthode retourne la liste des capteurs potentiellement défaillants.

//-------------------------------------------- Constructeurs - destructeur

    Model ( );
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

Gouvernement gouv;
vector<Particulier> listeParticuliers;
vector<Capteur> listeCapteurs;
vector<Cleaner> listeCleaners;
vector<Fournisseur> listeFournisseurs;
vector<Mesure> listeMesures;


};

#endif // Model_H
