#include "ContactPro.hpp"
#include <algorithm>

ContactPro::ContactPro(int id, string nom, string prenom, string sexe, string nom_entreprise, string statut_juridique, Adresse* adresse, string mail)
:Contact(id, nom, prenom, sexe, adresse)
{
    this->set_nom_entreprise(nom_entreprise);
    this->set_statut_juridique(statut_juridique);
    this->set_mail(mail);

}

ContactPro::~ContactPro(){};

void ContactPro::set_nom_entreprise(string nom){
    // Si longueur du nom <= 50, on assigne
    try{
        if (nom.length() <= 50){
            transform(nom.begin(), nom.end(), nom.begin(), ::toupper);
            this->nom_entreprise = nom;
        }
        else
            throw(nom.length());
    } // sinon erreur
    catch(unsigned long length){
        cout << "  ERREUR: longueur nom entreprise supérieure à 50 lettres" << endl;
        cout << "  longueur nom entreprise: " << length << endl << endl;
    }
}

void ContactPro::set_statut_juridique(string statut)
{
    // Si longueur du statut juridique <= 4, on assigne
    try{
        if (statut.length() <= 4)
        {
            transform(statut.begin(), statut.end(), statut.begin(), ::toupper);
            this->statut_juridique = statut;
        }
        else
            throw(statut.length());
    } // sinon erreur
    catch(unsigned long length){
        cout << "  ERREUR: longueur statut juridique supérieure à 4 lettres" << endl;
        cout << "  longueur statut juridique: " << length << endl << endl;
    }
}

void ContactPro::set_mail(string mail){
    // Si il y a bien un @ dans le mail, on assigne
    try{
        if(mail.find('@') != string::npos)
            this->mail = mail;
        else
            throw(mail);
    } // sinon erreur
    catch(string m){
        cout << "  ERREUR: mail non conforme, ne contient pas de @" << endl;
        cout << "  mail indiqué: " << m << endl << endl;
    }
}

// affiche les infos du contact pro
void ContactPro::infos(){
    //cout<<"Professionnel: "<< this->get_id()<<endl;
    Contact::infos();
    cout << "\tentreprise: " << this->get_nom_entreprise()<< endl;
    cout << "\tstatut juridique: " << this->get_statut_juridique() << endl;
    cout << "\n\tMAIL: " << this->get_mail() << endl;
}
