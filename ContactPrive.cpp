#include "ContactPrive.hpp"

ContactPrive::ContactPrive(int id, string nom, string prenom, string sexe, Adresse* adresse, string date_naissance)
:Contact(id, nom, prenom, sexe, adresse)
{
    this->set_date_naissance(date_naissance);

}

ContactPrive::~ContactPrive(){};




void ContactPrive::set_date_naissance(string date_naissance){
    this->date_naissance = date_naissance;
}


// affiche les infos du contact prive
void ContactPrive::infos()
{
    //cout<<"Particulier: "<< this->get_id()<<endl;
    Contact::infos();
    cout << "\tDATE DE NAISSANCE: " << this->get_date_naissance() << endl;
}
