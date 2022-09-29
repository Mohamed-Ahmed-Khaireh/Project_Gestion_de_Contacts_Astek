#include "Adresse.hpp"
#include <algorithm>
#include <string>

Adresse::Adresse(int numero, string rue, string complement, int code_postal, string ville)
{
    this->set_numero(numero);
    this->set_rue(rue);
    this->set_complement(complement);
    this->set_code_postal(to_string(code_postal));
    this->set_ville(ville);
}

Adresse::Adresse(int numero, string rue, string complement, string code_postal, string ville){
    this->set_numero(numero);
    this->set_rue(rue);
    this->set_complement(complement);
    this->set_code_postal(code_postal);
    this->set_ville(ville);
}

Adresse::~Adresse(){};




void Adresse::set_numero(int numero){
    this->numero = numero;
}

void Adresse::set_rue(string rue){
    try{
        if (rue.length() <= 250)
            this->rue = rue;
        else
            throw(rue.length());
    }
    catch(unsigned long length){
        cout << "  ERREUR: longueur nom de rue supérieur à la limite de 250" << endl;
        cout << "  longueur nom de rue: " << length << endl << endl;
    }

}

void Adresse::set_complement(string complement){
    try{
        if (complement.length() <= 250)
            this->complement = complement;
        else
            throw(complement.length());
    }
    catch(unsigned long length){
        cout << "  ERREUR: longueur complement supérieur à la limite de 250" << endl;
        cout << "  longueur complement: " << length << endl << endl;
    }
}

void Adresse::set_code_postal(string code_postal){
    try{
        if (code_postal.length() == 5)
            this->code_postal = code_postal;
        else
            throw(code_postal.length());
    }
    catch(unsigned long length){
        cout << "  ERREUR: longueur code postal différent de 5" << endl;
        cout << "  longueur code postal: " << length << endl << endl;
    }
}

void Adresse::set_ville(string ville){
    try{
        if (ville.length() <= 100){
            transform(ville.begin(), ville.end(), ville.begin(), ::toupper);
            this->ville = ville;
        }
        else
            throw(ville.length());
    }
    catch(unsigned long length){
        cout << "  ERREUR: longueur nom de ville supérieur à la limite de 100" << endl;
        cout << "  longueur nom de ville: " << length << endl << endl;
    }
}


void Adresse::infos(){

    cout << "\t" << this->get_numero()<<"," << " " << this->get_rue() << endl;
    cout << "\t" << this->get_code_postal() << " " << this->get_ville() << endl;
    if(this->get_complement() != "")
        cout << "\tCOMPLEMENT: " << this->get_complement() << endl;



}
