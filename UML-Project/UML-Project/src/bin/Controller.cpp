/*************************************************************************
                Controller  -  Manipule le Controller
                             -------------------
    début                : 17/01/2024
    copyright            : (C) 2021 by Chikhi Djalil & Thabet Yasmine  
                            & Cavagna Justine  & Hanader Rayan 
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
//------------------------------------------------------ Include personnel
using namespace std;
#include "Controller.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Getters
shared_ptr<Model>  Controller::getModel() const {
    return model;
}

shared_ptr<View>  Controller::getView() const {
    return vue;
}

Controller::Controller (  )
{
#ifdef MAP
    cout << "Appel au constructeur par défault de <Controller>" << endl;
#endif
}

Controller::Controller ( shared_ptr<Model>  model, shared_ptr<View>  vue ) : model(model), vue(vue)
{
#ifdef MAP
    cout << "Appel au constructeur de <Controller>" << endl;
#endif

} //----- Fin de Controller


Controller::~Controller ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Controller>" << endl;
#endif
} //----- Fin de ~Controller
