#include "Contact.hpp"
#include <algorithm>

Contact::Contact(int id, string nom, string prenom, string sexe, Adresse* adresse)
{
    set_id(id);
    set_nom(nom);
    set_prenom(prenom);
    set_sexe(sexe);
    set_adresse(adresse);
}

Contact::~Contact(){
    delete this->adresse;
}


void Contact::set_id(int id){
    this->id = id;
}

void Contact::set_nom(string nom){
    // Si la longueur est inférieur ou égal à 30, on assigne
    try{
        if (nom.length() <= 30){
            transform(nom.begin(), nom.end(), nom.begin(), ::toupper);
            this->nom = nom;
        }
        else
            throw(nom.length());
    } // sinon erreur
    catch(unsigned long length){
        cout << "  ERREUR:  longueur du nom max dépassée" << endl;
        cout << "  longueur nom actuelle: " << length << endl << endl;;
    }
}

void Contact::set_prenom(string prenom){
    // Si la longueur est inférieur ou égal à 30, on assigne
    try{
        if (prenom.length() <= 30){
            transform(prenom.begin(), prenom.begin()+1, prenom.begin(), ::toupper);
            transform(prenom.begin()+1, prenom.end(), prenom.begin()+1, ::tolower);
            this->prenom = prenom;
        }
        else
            throw(prenom.length());
    } // sinon erreur
    catch(unsigned long length){
        cout << "  ERREUR:  longueur du prenom max dépassée" << endl;
        cout << "  longueur prenom actuelle: " << length << endl << endl;;
    }
}

void Contact::set_sexe(string sexe){

    transform(sexe.begin(), sexe.end(), sexe.begin(), ::toupper);

    // Si le sexe est bien H ou F, on assigne
    try{
        if (sexe == "F" || sexe == "M"){
            transform(sexe.begin(), sexe.end(), sexe.begin(), ::toupper);
            this->sexe = sexe;
        }
        else
            throw(sexe);
    } // sinon erreur
    catch(string s){
        cout << "  ERREUR: le sexe est différent de H ou F" << endl;
        cout << "  sexe indiqué: " << s << endl << endl;
    }
}

void Contact::set_adresse(Adresse* adresse){
    this->adresse = adresse;
}

// affiche les infos d'un contact
void Contact::infos(){
    cout << endl;
    if(this->get_sexe() == "M")
        cout << "\tM. " << this->get_nom();
    else
        cout << "\tMme " << this->get_nom();
    cout << " " << this->get_prenom() << endl;
    this->adresse->infos();
}
